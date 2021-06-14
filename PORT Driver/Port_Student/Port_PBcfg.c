 /******************************************************************************
 *
 * [MODULE]: PORT
 *
 * [FILE NAME]: Port_PBcfg.c
 *
 * [DESCRIPTION]: Post Build Configuration Source file for TM4C123GH6PM 
 *                Microcontroller - Port Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION             (1U)
#define PORT_PBCFG_SW_MINOR_VERSION             (0U)
#define PORT_PBCFG_SW_PATCH_VERSION             (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = 
{
  {
    /***********************************************************************************
     *                                     PORTA                                       *
     ***********************************************************************************/
	{ 
          PORT_PIN_0,                                   /* Pin Number is 0 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_1,                                   /* Pin Number is 1*/
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_2,                                   /* Pin Number is 2*/
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_3,                                   /* Pin Number is 3 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
			
	{ 
          PORT_PIN_4,                                   /* Pin Number is 4 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
			
	{ 
          PORT_PIN_5,                                   /* Pin Number is 5 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
		
	{ 
          PORT_PIN_6,                                   /* Pin Number is 6 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_7,                                   /* Pin Number is 7 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},		
	
      /* END OF PORTA */
		
    /***********************************************************************************
     *                                     PORTB                                       *
     ***********************************************************************************/
	{ 
          PORT_PIN_8,                                   /* Pin Number is 8 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_9,                                   /* Pin Number is 9 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_10,                                  /* Pin Number is 10 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_11,                                  /* Pin Number is 11 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
			
	{ 
          PORT_PIN_12,                                  /* Pin Number is 12 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
			
	{ 
          PORT_PIN_13,                                  /* Pin Number is 13 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
		
	{ 
          PORT_PIN_14,                                  /* Pin Number is 14 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_15,                                  /* Pin Number is 15 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
        },	
          
	/* END OF PORTB */
		
    /***********************************************************************************
     *                                     PORTC                                       *
     ***********************************************************************************/
	{ 
          PORT_PIN_16,                                  /* Pin Number is 16 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_17,                                  /* Pin Number is 17 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_18,                                  /* Pin Number is 18 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_19,                                  /* Pin Number is 19 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_20,                                  /* Pin Number is 20 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_21,                                  /* Pin Number is 21 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_22,                                  /* Pin Number is 22 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_23,                                  /* Pin Number is 23 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
	
	/* END OF PORTC */
			
    /***********************************************************************************
     *                                     PORTD                                       *
     ***********************************************************************************/
	{ 
          PORT_PIN_24,                                  /* Pin Number is 24 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_25,                                  /* Pin Number is 25 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_26,                                  /* Pin Number is 26 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,         /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_27,                                  /* Pin Number is 27 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
			
	{
          PORT_PIN_28,                                  /* Pin Number is 28 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_29,                                  /* Pin Number is 29 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_30,                                  /* Pin Number is 30 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_31,                                  /* Pin Number is 31 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
        
	/* END OF PORTD */
		
    /***********************************************************************************
     *                                     PORTE                                       *
     ***********************************************************************************/
	{ 
          PORT_PIN_32,                                  /* Pin Number is 32 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_33,                                  /* Pin Number is 33 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_34,                                  /* Pin Number is 34 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_35,                                  /* Pin Number is 35 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
			
	{ 
          PORT_PIN_36,                                  /* Pin Number is 36 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_37,                                  /* Pin Number is 37 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},				
	
        /* END OF PORTE */
	
    /***********************************************************************************
     *                                     PORTF                                       *
     ***********************************************************************************/
	{ 
          PORT_PIN_38,                                  /* Pin Number is 38 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{
          PORT_PIN_39_LED1_CHANNEL,                     /* Pin Number is 39 (LED1) */
          PORT_PIN_DEFAULT_MODE,                        /* LED Pin Mode is GPIO */
          PORT_PIN_OUT,                                 /* LED Pin Direction is Output */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* LED Pin Internal Resistor is NO Resistor */
          DIR_UNCHANGEABLE,                             /* LED Pin Direction can't be Changable, as LED is always Output */
          MODE_UNCHANGEABLE,                            /* LED Pin Mode can't be Changable, as LED is always GPIO Pin */
          STD_LOW                                       /* LED Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_40,                                  /* Pin Number is 40 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},	
			
	{ 
          PORT_PIN_41,                                  /* Pin Number is 41 */
          PORT_PIN_DEFAULT_MODE,                        /* Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* Pin Direction is Input */
          PORT_PIN_DEFAULT_INTERNAL_RESISTOR,           /* Pin Internal Resistor is NO Resistor */
          PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,        /* Pin Direction can be Changable */
          PORT_PIN_DEFAULT_MODE_CHANGEABLE,             /* Pin Mode can be Changable */
          PORT_PIN_LEVEL_VALUE                          /* Pin Level value is STD_LOW */
	},
		
	{ 
          PORT_PIN_42_SW1_CHANNEL,                      /* SW Pin Number is 42 (SW1) */
          PORT_PIN_DEFAULT_MODE,                        /* SW Pin Mode is GPIO */
          PORT_PIN_DEFAULT_DIRECTION,                   /* SW Pin Direction is Input */
          PULL_UP,                                      /* SW Internal Resistor is PULL UP Resistor */
          DIR_UNCHANGEABLE,                             /* SW Pin Direction can't be Changable, as SW is always Input */
          MODE_UNCHANGEABLE,                            /* SW Pin Mode can't be Changable, as SW is always GPIO Pin */
          STD_HIGH                                      /* SW Pin Level value is STD_HIGH */
	},		
        
	/* END OF PORTF */
      }   
 };	/* END OF PORT CONFIGURATION STRUCTURE */