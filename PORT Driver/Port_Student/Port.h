 /******************************************************************************
 *
 * [MODULE]: PORT
 *
 * [FILE NAME]: Port.h
 *
 * [DESCRIPTION]: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Ahmed Hassan's ID = 500 */
#define PORT_VENDOR_ID    (500U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID   (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/*
 * Macros for Port Number
 */
#define PORTA                           (0U)
#define PORTB                           (1U)
#define PORTC                           (2U)
#define PORTD                           (3U)
#define PORTE                           (4U)
#define PORTF                           (5U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/*******************************************************************************
 *                           API SERVICE IDs MACROS                            *
 *******************************************************************************/
 
/* Service ID for PORT Init Channel */
#define PORT_INIT_SID                   	(uint8)0x00

/* Service ID for PORT Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID      	(uint8)0x01

/* Service ID for PORT Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID 	(uint8)0x02

/* Service ID for PORT Get Version Info */
#define PORT_GET_VERSION_INFO_SID       	(uint8)0x03

/* Service ID for PORT Set Pin Mode */
#define PORT_SET_PIN_MODE_SID          		(uint8)0x04

/*******************************************************************************
 *                               DET ERROR CODES                               *
 *******************************************************************************/

/* DET code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                        (uint8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE           (uint8)0x0B

/* The API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG                     (uint8)0x0C

/* The API service called with Invalid Mode */
#define PORT_E_PARAM_INVALID_MODE               (uint8)0x0D

/* The API service called with unchangeable Mode */
#define PORT_E_MODE_UNCHANGEABLE                (uint8)0x0E

/* The API service used without module initialization */
#define PORT_E_UNINIT                           (uint8)0x0F

/* The API called with a NULL Pointer */
#define PORT_E_PARAM_POINTER                    (uint8)0x10

/* (USER IMPLEMENTATION) DET code to report Invalid Port Pin direction */
#define PORT_E_PARAM_INVALID_DIR                (uint8)0x11

/*******************************************************************************
 *                             MODULE DEFINTIONS  (MODES)                      *
 *******************************************************************************/

/* 
 * PORT Defined Alternative Modes, these values should be inserted through PORT Driver to change the Pin Mode
 * Ex: To covert the PIN PA0 from the default mode(GPIO) to UART Mode we must insert value 1 into the Target Registers
 * Customer/User must use the correct Pin for each Mode(Mentioned below)
 *
 * NOTE: There are some cases that the mode take more than one value (Supported by more than one Pin),
 * in these cases seperate between them using CH ("stands for Choice")
 * Ex: UART_1 Mode can be supported by PB0, PB1 (with value 1), PC4, PC5 (with value 2), so seperate between
 * them using Choice 1, 2, ...
 */
#define PORT_PIN_MODE_ADC  		(Port_PinType)0 /* Alternate Function as ADC correspond to --> ALL PINs */

#define PORT_PIN_MODE_U0RX 		(Port_PinType)1 /* Alternate Function as UART0 RX correspond to --> PA0 */
#define PORT_PIN_MODE_U0TX  		(Port_PinType)1 /* Alternate Function as UART0 TX correspond to --> PA1 */
#define PORT_PIN_MODE_U1RX_CH1  	(Port_PinType)1 /* Alternate Function as UART1 RX correspond to --> PB0 */
#define PORT_PIN_MODE_U1TX_CH1  	(Port_PinType)1 /* Alternate Function as UART1 TX correspond to --> PB1 */
#define PORT_PIN_MODE_U4RX  		(Port_PinType)1 /* Alternate Function as UART4 RX correspond to --> PC4 */
#define PORT_PIN_MODE_U4TX  		(Port_PinType)1 /* Alternate Function as UART4 TX correspond to --> PC5 */
#define PORT_PIN_MODE_U3RX  		(Port_PinType)1 /* Alternate Function as UART3 RX correspond to --> PC6 */
#define PORT_PIN_MODE_U3TX  		(Port_PinType)1 /* Alternate Function as UART3 TX correspond to --> PC7 */
#define PORT_PIN_MODE_U6RX  		(Port_PinType)1 /* Alternate Function as UART6 RX correspond to --> PD4 */
#define PORT_PIN_MODE_U6TX  		(Port_PinType)1 /* Alternate Function as UART6 TX correspond to --> PD5 */
#define PORT_PIN_MODE_U2RX  		(Port_PinType)1 /* Alternate Function as UART2 RX correspond to --> PD6 */
#define PORT_PIN_MODE_U2TX  		(Port_PinType)1 /* Alternate Function as UART2 TX correspond to --> PD7 */
#define PORT_PIN_MODE_U7RX  		(Port_PinType)1 /* Alternate Function as UART7 RX correspond to --> PE0 */
#define PORT_PIN_MODE_U7TX  		(Port_PinType)1 /* Alternate Function as UART7 TX correspond to --> PE1 */
#define PORT_PIN_MODE_U5RX  		(Port_PinType)1 /* Alternate Function as UART5 RX correspond to --> PE4 */
#define PORT_PIN_MODE_U5TX  		(Port_PinType)1 /* Alternate Function as UART5 TX correspond to --> PE5 */
#define PORT_PIN_MODE_U1RTS_CH1  	(Port_PinType)1 /* Alternate Function as UART1 RTS correspond to --> PF0 */
#define PORT_PIN_MODE_U1CTS_CH1  	(Port_PinType)1 /* Alternate Function as UART1 CTS correspond to --> PF1 */
#define PORT_PIN_MODE_SSI3CLK  		(Port_PinType)1 /* Alternate Function as SSI3_CLK correspond to --> PD0 */
#define PORT_PIN_MODE_SSI3Fss  		(Port_PinType)1 /* Alternate Function as SSI3_FSS correspond to --> PD1 */
#define PORT_PIN_MODE_SSI3RX   		(Port_PinType)1 /* Alternate Function as SSI3_RX correspond to  --> PD2 */
#define PORT_PIN_MODE_SSI3TX   		(Port_PinType)1 /* Alternate Function as SSI3_TX correspond to  --> PD3 */

#define PORT_PIN_MODE_SSI0CLK  		(Port_PinType)2 /* Alternate Function as SSI0_CLK correspond to --> PA2 */
#define PORT_PIN_MODE_SSI0FSS  		(Port_PinType)2 /* Alternate Function as SSI0_FSS correspond to --> PA3 */
#define PORT_PIN_MODE_SSI0RX   		(Port_PinType)2 /* Alternate Function as SSI0_RX correspond to  --> PA4 */
#define PORT_PIN_MODE_SSI0TX   		(Port_PinType)2 /* Alternate Function as SSI0_TX correspond to  --> PA5 */
#define PORT_PIN_MODE_SSI2CLK  		(Port_PinType)2 /* Alternate Function as SSI2_CLK correspond to --> PB4 */
#define PORT_PIN_MODE_SSI2FSS 		(Port_PinType)2 /* Alternate Function as SSI2_FSS correspond to --> PB5 */
#define PORT_PIN_MODE_SSI2RX   		(Port_PinType)2 /* Alternate Function as SSI2_RX correspond to  --> PB6 */
#define PORT_PIN_MODE_SSI2TX   		(Port_PinType)2 /* Alternate Function as SSI2_TX correspond to  --> PB7 */
#define PORT_PIN_MODE_SSI1CLK  		(Port_PinType)2 /* Alternate Function as SSI1_CLK correspond to --> PD0 or PF0 */
#define PORT_PIN_MODE_SSI1FSS  		(Port_PinType)2 /* Alternate Function as SSI1_FSS correspond to --> PD1 or PF1 */
#define PORT_PIN_MODE_SSI1RX   		(Port_PinType)2 /* Alternate Function as SSI1_RX correspond to  --> PD2 or PF2 */
#define PORT_PIN_MODE_SSI1TX   		(Port_PinType)2 /* Alternate Function as SSI1_TX correspond to  --> PD3 or PF3 */

#define PORT_PIN_MODE_I2C1SCL  		(Port_PinType)3 /* Alternate Function as I2C1_SCL correspond to --> PD6 */
#define PORT_PIN_MODE_I2C1SDA  		(Port_PinType)3 /* Alternate Function as I2C1_SDA correspond to --> PD7 */
#define PORT_PIN_MODE_I2C0SCL  		(Port_PinType)3 /* Alternate Function as I2C0_SCL correspond to --> PB2 */
#define PORT_PIN_MODE_I2C0SDA  		(Port_PinType)3 /* Alternate Function as I2C0_SDA correspond to --> PB3 */
#define PORT_PIN_MODE_I2C3SCL  		(Port_PinType)3 /* Alternate Function as I2C3_SCL correspond to --> PD0 */
#define PORT_PIN_MODE_I2C3SDA  		(Port_PinType)3 /* Alternate Function as I2C3_SDA correspond to --> PD1 */
#define PORT_PIN_MODE_I2C2SCL  		(Port_PinType)3 /* Alternate Function as I2C2_SCL correspond to --> PE4 */
#define PORT_PIN_MODE_I2C2SDA  		(Port_PinType)3 /* Alternate Function as I2C2_SDA correspond to --> PE5 */
#define PORT_PIN_MODE_CAN0RX_CH1  	(Port_PinType)3 /* Alternate Function as I2C2_SCL correspond to --> PF0 */
#define PORT_PIN_MODE_CAN0TX_CH1  	(Port_PinType)3 /* Alternate Function as I2C2_SCL correspond to --> PF3 */

#define PORT_PIN_MODE_GPIO  		(Port_PinType)12 /* Default Mode as GPIO correspond to --> ALL PINs
                                                            (Choose Num not supported in the table) as by default All Pins are GPIO */
/* Continue with the same sequance ... */

/*******************************************************************************
 *                              MODULE DATA TYPES                              *
 *******************************************************************************/

/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN, PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF, PULL_UP, PULL_DOWN
}Port_PinInternalResistor;

/* Description: Enum to hold direction changeable type for PIN */
typedef enum
{
    DIR_UNCHANGEABLE, DIR_CHANGEABLE 
}Port_PinDirectionChangeableType;  

/* Description: Enum to hold mode changeable type for PIN */
typedef enum
{
    MODE_UNCHANGEABLE, MODE_CHANGEABLE 
}Port_PinModeChangeableType;  

/* 
 * [Description]: Structure to configure each individual PIN:
 *		   - Configure the PIN Number (PIN0, PIN1, PIN2, ...)
 *		   - Configure the PIN Mode (DIO, ADC, SPI, ...)
 *		   - Configure the PIN Direction (PORT_PIN_IN, PORT_PIN_OUT)
 * 		   - Configure the PIN Internal Resistor (OFF, PULL_UP, PULL_DOWN)
 *		   - Configure the PIN Direction if it is Changeable during runtime or not (DIR_UNCHANGEABLE/DIR_CHANGEABLE)
 * 		   - Configure the PIN Mode if it is Changeable during runtime or not (MODE_UNCHANGEABLE/MODE_CHANGEABLE )
 * 		   - Insert the PIN Level value when the PORT PIN is used for DIO (STD_HIGH/STD_LOW)
 */
typedef struct 
{
  Port_PinType Port_Pin_Num; 
  Port_PinModeType Pin_Mode;
  Port_PinDirectionType Pin_Direction;
  Port_PinInternalResistor Pin_Resistor;
  Port_PinDirectionChangeableType Pin_Dir_Changeable;
  Port_PinModeChangeableType Pin_Mode_Changeable;
  boolean Pin_Level_Value;	
	
}Port_ConfigPin;

/* Data Structure required for initializing the Port Driver */
typedef struct
{
  Port_ConfigPin Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                            FUNCTION PROTOTYPES                              *
 *******************************************************************************/
 
/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize the Port Driver module
********************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*******************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*		   Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin direction
********************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/*******************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refreshe port direction
********************************************************************************/
void Port_RefreshPortDirection(void);

#if (PORT_VERSION_INFO_API == STD_ON)
/*******************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information
*                                 of this module
* Return value: None
* Description: Function to return the version information of this module
********************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
/*******************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*		   Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information
*                                 of this module
* Return value: None
* Description: Function to set the port pin mode
********************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/*******************************************************************************
 *                            EXTERNAL VARIABLES                               *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
