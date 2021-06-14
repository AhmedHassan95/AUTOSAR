 /*********************************************************************************************
 *
 * [MODULE]: PORT
 *
 * [FILE NAME]: Port.c
 *
 * [DESCRIPTION]: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * [AUTHOR]: Ahmed Hassan
 
 **********************************************************************************************/

#include "Port.h"
#include "Port_Regs.h"
#include "tm4c123gh6pm_registers.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPin * Port_Channels = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/**********************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize the Port Driver module
**********************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
	
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
	}
	else 
#endif	
	{
          volatile uint32 * PortGpio_Ptr = NULL_PTR;    /* Point to the required Port Registers base address */
          volatile uint32 delay = 0;                    /* Local variable to store the delay time in it */
          Port_Channels = ConfigPtr->Pins;              /* Address of the first structure --> PORTA --> PIN[0] */
          uint8 Port_Num = 0;                           /* Local variable used to store the Port number */
          uint8 Pin_Num = 0;                            /* Local variable used to store the Pin number */
          uint8 counter = 0;                            /* Local variable used as a counter for the PORTF PINs */
          uint8 Pin_Index;                              /* Local variable used as a counter to count the Pin number */
		
          /* Configure All Target PINs:
           * Loop from Index0 until PORT_CONFIGURED_PINS to cover All Target PINs
           *
           * - Decide which PORT the PIN belongs to (PORTA, PORTB, PORTC, PORTD, PORTE, PORTF)
           * - Decide the PIN Direction (PORT_PIN_IN, PORT_PIN_OUT)
           * - Decide the PIN Mode (DIO, ADC, SPI, ...)
           * - Decide the PIN Internal Resistor (OFF, PULL_UP, PULL_DOWN)
           * - Insert the PIN Initial value when the PORT PIN is used for DIO (STD_HIGH/STD_LOW)
           */
          for(Pin_Index = 0; Pin_Index < PORT_CONFIGURED_PINS ;Pin_Index++)
          {
            /************************************************************************************
             *                 DETERMINE THE PORT AND THE PIN NUMBER FOR EACH INDEX             *
             ************************************************************************************/
            
            /* From PORTA until PORTE */
            if(Pin_Index < PORT_PIN_38)
            {
              /* Extract the Port number from the configured Port Pins */ 
              Port_Num = (uint8)Pin_Index / PORT_CONFIGURED_PORT_PINS ;
              /* Extract the Pin number from the configured Port Pins */
              Pin_Num = (uint8)Pin_Index % PORT_CONFIGURED_PORT_PINS ;
            }
            /* Handle Case of PORTF, as it is have only 5 Pins */
            else
            {
              Port_Num = PORTF;
              Pin_Num = counter;
              ++counter;
            }
            
            /************************************************************************************
             *                      DETERMINE THE PORT REGISTER FOR EACH PIN                    *
             ************************************************************************************/
            
            switch(Port_Num)
            {
              case  PORTA: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                           break;
              case  PORTB: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                           break;
              case  PORTC: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                           break;
              case  PORTD: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                           break;
              case  PORTE: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                           break;
              case  PORTF: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                           break;
            }
            /* Enable clock for PORT and allow time for clock to start*/
              SYSCTL_REGCGC2_REG |= (1<<Port_Num);
              delay = SYSCTL_REGCGC2_REG;

              if( ((Port_Num == 3) && (Pin_Num == 7)) || ((Port_Num == 5) && (Pin_Num == 0)) ) /* PD7 or PF0 */
              {
                /* Unlock the GPIOCR register */ 
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;	  
                /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET), Pin_Num);
              }
              else if( (Port_Num == 2) && (Pin_Num <= 3) ) /* PC0 to PC3 */
              {
                continue;       /* Do Nothing ...  this is the JTAG pins */
              }
              else
              {
                /* Do Nothing ... No need to unlock the commit register for this pin */
              }
			
            /************************************************************************************
             *                        DETERMINE THE DIRECTION FOR EACH PIN                      *
             ************************************************************************************/
              
              switch(Port_Channels[Pin_Index].Pin_Direction)
              {
                /********************************************************************************
                 *                                 OUTPUT PIN                                   *
                 ********************************************************************************/
                 case PORT_PIN_OUT:
		
                  /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num);
                                  
                  /********************************************************************************
                   *                           LEVEL VALUE (STANDARD HIGH)                        *
                   ********************************************************************************/
                   if(Port_Channels[Pin_Index].Pin_Level_Value == STD_HIGH)
                   {
                      /* Set the corresponding bit in the GPIODATA register to provide level value 1 */
                        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), Pin_Num);
                   }
                      
                  /********************************************************************************
                   *                           LEVEL VALUE (STANDARD LOW)                         *
                   ********************************************************************************/
                   else
                   {
                     /* Clear the corresponding bit in the GPIODATA register to provide level value 0 */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), Pin_Num);
                   }
                   break;
                 
                   
                /********************************************************************************
                 *                                 INPUT PIN                                    *
                 ********************************************************************************/
                 case PORT_PIN_IN:

                  /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num);
				
                  /********************************************************************************
                   *                               PULL UP RESISTOR                               *
                   ********************************************************************************/
                   if(Port_Channels[Pin_Index].Pin_Resistor == PULL_UP)
                   {
                     /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), Pin_Num);
                   }
                                  
                  /********************************************************************************
                   *                               PULL DOWN RESISTOR                             *
                   ********************************************************************************/
                   else if(Port_Channels[Pin_Index].Pin_Resistor == PULL_DOWN)
                   {
                     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), Pin_Num);
                   }
                                  
                  /********************************************************************************
                   *                                  NO RESISTOR                                 *
                   ********************************************************************************/
                   else
                   {
                    /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), Pin_Num);
                    /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), Pin_Num);
                    }
                    break;
                   
              }       /* END OF DETERMINE THE DIRECTION FOR EACH PIN */

              
            /************************************************************************************
             *                        DETERMINE THE MODE FOR EACH PIN                           *
             ************************************************************************************/
               
               if(Port_Channels[Pin_Index].Pin_Mode == PORT_PIN_MODE_GPIO)
               {
                  /********************************************************************************
                   *                               DIGITAL MODE(GPIO)                             *
                   ********************************************************************************/
                   /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Pin_Num);      
                   /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Pin_Num);   
                   /* Clear the PMCx bits for this pin */
                     *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F<<(Pin_Num * 4));
                   /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Pin_Num);
               }
              
               else if(Port_Channels[Pin_Index].Pin_Mode == PORT_PIN_MODE_ADC)	
               {
                  /********************************************************************************
                   *                                ANALOG MODE (ADC)                             *
                   ********************************************************************************/
                   /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Pin_Num);      
                   /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Pin_Num);   
                   /* Clear the PMCx bits for this pin */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F<<(Pin_Num * 4));
                   /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Pin_Num);
               }
               
               else
                {	             
                  /********************************************************************************
                   *                         	   ALTERNATIVE MODE                               *
                   ********************************************************************************/
                   /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Pin_Num);      
                   /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Pin_Num);   
                   /* Clear the PMCx bits for this pin */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F<<(Pin_Num * 4));
                   /* Insert the required Mode into Control Register to chane the PIN Mode */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F & Port_Channels[Pin_Index].Pin_Mode<<(Pin_Num * 4));
                   /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Pin_Num);
                }
        }	
        /* Set the module state to initialized */
        Port_Status       = PORT_INITIALIZED;
        
    }
}	/* END OF PORT INIT FUNCTION */


#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/**********************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*	           Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin direction
**********************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR;    /* Point to the required Port Registers base address */
  boolean error = FALSE;
  uint8 Port_Num = 0;                           /* Local variable used to store the Port number */
  uint8 Pin_Num = 0;                            /* Local variable used to store the Pin number */
  uint8 counter = 0;                            /* Local variable used as a counter for the PORTF PINs */		
	
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
          error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used Pin is within the valid range */
	if (PORT_CONFIGURED_PINS <= Pin)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
          error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if Direction of the used Pin is Unchangeable */
	if (DIR_UNCHANGEABLE == Port_Channels[Pin].Pin_Dir_Changeable)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
          error = TRUE;
	}
	else
#endif		
	{
          /* In case there are no Errors */
          if(FALSE == error)
          {
            /************************************************************************************
             *                 DETERMINE THE PORT AND THE PIN NUMBER FOR EACH INDEX             *
             ************************************************************************************/
			 
            /* From PORTA until PORTE */
            if(Pin < PORT_PIN_38)
            {
              /* Extract the Port number from the configured Port Pins */ 
              Port_Num = (uint8)Pin / PORT_CONFIGURED_PORT_PINS ;
              /* Extract the Pin number from the configured Port Pins */
              Pin_Num = (uint8)Pin % PORT_CONFIGURED_PORT_PINS ;
            }
            /* Handle Case of PORTF, as it is have only 5 Pins */
            else
            {
              Port_Num = PORTF;
              Pin_Num = counter;
              ++counter;
            }

            /************************************************************************************
             *                      DETERMINE THE PORT REGISTER FOR EACH PIN                    *
             ************************************************************************************/
			 
            switch(Port_Num)
            {
              case  PORTA: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                           break;
              case  PORTB: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                           break;
              case  PORTC: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                           break;
              case  PORTD: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                           break;
              case  PORTE: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                           break;
              case  PORTF: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                           break;
            }
                
            /************************************************************************************
             *                            SET THE DIRECTION FOR EACH PIN                        *
             ************************************************************************************/
              
             switch(Direction)
             {
                /********************************************************************************
                 *                                 OUTPUT PIN                                   *
                 ********************************************************************************/
                  case PORT_PIN_OUT:
					
                  /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num);
                  break;
				
                /********************************************************************************
                 *                                 INPUT PIN                                    *
                 ********************************************************************************/
                  case PORT_PIN_IN:

                  /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num);
                  break;
                                  
                /********************************************************************************
                 *                                 INVALID PIN                                  *
                 ********************************************************************************/
                  default:
                  #if (PORT_DEV_ERROR_DETECT == STD_ON)
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, 
                                    PORT_E_PARAM_INVALID_DIR);
                    error = TRUE;
                  #endif	
                    
              } /* END OF SET THE DIRECTION FOR THE REQUIRED PIN */
          }
          else
          {
              /* No Action Required */
          }
    }
}       /* END OF SET PIN DIRECTION FUNCTION */
#endif


/**********************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refreshe port direction
**********************************************************************************************/
void Port_RefreshPortDirection(void)
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR;    /* Point to the required Port Registers base address */
  boolean error = FALSE;
  uint8 Port_Num = 0;                           /* Local variable used to store the Port number */
  uint8 Pin_Num = 0;                            /* Local variable used to store the Pin number */
  uint8 counter = 0;                            /* Local variable used as a counter for the PORTF PINs */
  uint8 Pin_Index;                              /* Local variable used as a counter to count the Pin number */

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
          error = TRUE;
	}
	else
	{
          /* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
	   /************************************************************************************
	    *                          REFRESH THE DIRECTION FOR EACH PIN                      *
	    ************************************************************************************/
	
            for(Pin_Index; Pin_Index < PORT_CONFIGURED_PINS ;Pin_Index++)
            {
                /************************************************************************************
                 *                 DETERMINE THE PORT AND THE PIN NUMBER FOR EACH INDEX             *
                 ************************************************************************************/
			 
                  /* From PORTA until PORTE */
                  if(Pin_Index < PORT_PIN_38)
                  {
                    /* Extract the Port number from the configured Port Pins */ 
                    Port_Num = (uint8)Pin_Index / PORT_CONFIGURED_PORT_PINS ;
                    /* Extract the Pin number from the configured Port Pins */
                    Pin_Num = (uint8)Pin_Index % PORT_CONFIGURED_PORT_PINS ;
                  }
                  /* Handle Case of PORTF, as it is have only 5 Pins */
                  else
                  {
                    Port_Num = PORTF;
                    Pin_Num = counter;
                    ++counter;
                  }

                /************************************************************************************
                 *                      DETERMINE THE PORT REGISTER FOR EACH PIN                    *
                 ************************************************************************************/
			 
                  switch(Port_Num)
                  {
                    case  PORTA: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                                 break;
                    case  PORTB: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                                 break;
                    case  PORTC: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                                 break;
                    case  PORTD: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                                 break;
                    case  PORTE: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                                 break;
                    case  PORTF: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                                 break;
                  }

                /********************************************************************************
                 *                           REFRESH THE OUTPUT PINs                            *
                 ********************************************************************************/
	
                  if( BIT_IS_SET(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num) )
                  {
                    /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num);
                  }
					
                /********************************************************************************
                 *                           REFRESH THE INPUT PINs                             *
                 ********************************************************************************/
				
                  else if( BIT_IS_CLEAR(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num) )
                  {
                    /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Pin_Num);
                  }
                  else
                  {
			/* No Action Required */
                  }
          }
    } 	
}	/* END OF REFRESH PIN DIRECTION */


#if (PORT_VERSION_INFO_API == STD_ON)
/**********************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module
* Return value: None
* Description: Function to return the version information of this module
**********************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not NULL pointer */
	if(NULL_PTR == versioninfo)
	{
          /* Report to DET  */
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, 
                          PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
          /* Copy the vendor Id */
          versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
          /* Copy the module Id */
          versioninfo->moduleID = (uint16)PORT_MODULE_ID;
          /* Copy Software Major Version */
          versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
          /* Copy Software Minor Version */
          versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
          /* Copy Software Patch Version */
          versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
        
}       /* END OF GET VERSION INFO FUNCTION */
#endif


#if (PORT_SET_PIN_MODE_API == STD_ON)
/**********************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*				   Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module
* Return value: None
* Description: Function to set the port pin mode
**********************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR;    /* Point to the required Port Registers base address */
  boolean error = FALSE;
  uint8 Port_Num = 0;                           /* Local variable used to store the Port number */
  uint8 Pin_Num = 0;                            /* Local variable used to store the Pin number */
  uint8 counter = 0;                            /* Local variable used as a counter for the PORTF PINs */
	
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
          error = TRUE;
	}
	else
	{
          /* No Action Required */
	}
	/* Check if the used Pin is within the valid range */
	if (PORT_CONFIGURED_PINS <= Pin)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
          error = TRUE;
	}
	else
	{
          /* No Action Required */
	}
	/* Check if Mode of the used Pin is Unchangeable */
	if (MODE_UNCHANGEABLE == Port_Channels[Pin].Pin_Mode_Changeable)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_MODE_UNCHANGEABLE);
          error = TRUE;
	}
	else
#endif	
	{
          /* In-case there are no errors */
          if(FALSE == error)
          {
            /************************************************************************************
             *                 DETERMINE THE PORT AND THE PIN NUMBER FOR EACH INDEX             *
             ************************************************************************************/
			 
               /* From PORTA until PORTE */
               if(Pin < PORT_PIN_38)
               {
                 /* Extract the Port number from the configured Port Pins */ 
                   Port_Num = (uint8)Pin / PORT_CONFIGURED_PORT_PINS ;
                 /* Extract the Pin number from the configured Port Pins */
                   Pin_Num = (uint8)Pin % PORT_CONFIGURED_PORT_PINS ;
               }
               /* Handle Case of PORTF, as it is have only 5 Pins */
               else
               {
                 Port_Num = PORTF;
                 Pin_Num = counter;
                 ++counter;
               }
                  
            /************************************************************************************
             *                      DETERMINE THE PORT REGISTER FOR EACH PIN                    *
             ************************************************************************************/
			 
              switch(Port_Num)
              {
                case  PORTA: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                             break;
                case  PORTB: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                             break;
                case  PORTC: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                             break;
                case  PORTD: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                             break;
                case  PORTE: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                             break;
                case  PORTF: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                             break;
              }
                
            /************************************************************************************
             *                          SET THE MODE FOR THE REQUIRED PIN                       *
             ************************************************************************************/
              
              #if (PORT_DEV_ERROR_DETECT == STD_ON)	
              if(! (Mode == 14) || (Mode <= 8 && Mode >= 0) )
              {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, 
                                PORT_E_MODE_UNCHANGEABLE);
              }
              else
              {
                /* No Action Required */
              }
              #endif
			
               /********************************************************************************
                *                               DIGITAL MODE(GPIO)                             *
                ********************************************************************************/
              
                if(Mode == PORT_PIN_MODE_GPIO)
                {
                  /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Pin_Num);      
                  /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Pin_Num);   
                  /* Clear the PMCx bits for this pin */
                  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F<<(Pin_Num * 4));
                  /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Pin_Num);
                }		
		   
                /********************************************************************************
                 *                                ANALOG MODE (ADC)                             *
                 ********************************************************************************/
                else if(Mode == PORT_PIN_MODE_ADC)	
                {
                  /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Pin_Num);      
                  /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Pin_Num);   
                  /* Clear the PMCx bits for this pin */
                  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F<<(Pin_Num * 4));
                  /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Pin_Num);
                }				
			
                /********************************************************************************
                 *                         	   ALTERNATIVE MODE                             *
                 ********************************************************************************/
                else
                {	
                  /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Pin_Num);      
                  /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Pin_Num);   
                  /* Clear the PMCx bits for this pin */
                  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F<<(Pin_Num * 4));
                  /* Insert the required Mode into Control Register to chane the PIN Mode */
                  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F & Mode<<(Pin_Num * 4));
                  /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Pin_Num);
                }
          } 
    } 		
}	/* END OF SET PIN MODE FUCTION */
#endif