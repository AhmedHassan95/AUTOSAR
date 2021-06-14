 /*****************************************************************************************************
 *
 * [MODULE]: PORT
 *
 * [FILE NAME]: Port_Cfg.h
 *
 * [DESCRIPTION]: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 ******************************************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION             (1U)
#define PORT_CFG_SW_MINOR_VERSION             (0U)
#define PORT_CFG_SW_PATCH_VERSION             (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/******************************************************************************************************
 *                                    PRE-COMPILED CONFIGURATIONS                                     *
 ******************************************************************************************************/
 
/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

/* Pre-compile option for presence of Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API                (STD_ON)

/* Number of the configured PORTs */
#define PORT_CONFIGURED_PORTS                  (6U)

/* Number of the configured PORT PINs */
#define PORT_CONFIGURED_PORT_PINS              (8U)

/* Number of the configured PINs */
#define PORT_CONFIGURED_PINS                   (43U)

/******************************************************************************************************
 *                                       THE GENERATED PIN IDs                                        *
 ******************************************************************************************************/

/* PORT Configured Pin ID's */
#define PORT_PIN_0                      (Port_PinType)0		/* Pin 0 in Port 0 */
#define PORT_PIN_1                      (Port_PinType)1 	/* Pin 1 in Port 0 */
#define PORT_PIN_2                      (Port_PinType)2 	/* Pin 2 in Port 0 */
#define PORT_PIN_3             	        (Port_PinType)3 	/* Pin 3 in Port 0 */
#define PORT_PIN_4                      (Port_PinType)4 	/* Pin 4 in Port 0 */
#define PORT_PIN_5                      (Port_PinType)5 	/* Pin 5 in Port 0 */
#define PORT_PIN_6                      (Port_PinType)6 	/* Pin 6 in Port 0 */
#define PORT_PIN_7                      (Port_PinType)7 	/* Pin 7 in Port 0 */

#define PORT_PIN_8                      (Port_PinType)8 	/* Pin 0 in Port 1 */
#define PORT_PIN_9                      (Port_PinType)9 	/* Pin 1 in Port 1 */
#define PORT_PIN_10                     (Port_PinType)10 	/* Pin 2 in Port 1 */
#define PORT_PIN_11                     (Port_PinType)11 	/* Pin 3 in Port 1 */
#define PORT_PIN_12                     (Port_PinType)12 	/* Pin 4 in Port 1 */
#define PORT_PIN_13                     (Port_PinType)13 	/* Pin 5 in Port 1 */
#define PORT_PIN_14                     (Port_PinType)14 	/* Pin 6 in Port 1 */
#define PORT_PIN_15                     (Port_PinType)15 	/* Pin 7 in Port 1 */

#define PORT_PIN_16                     (Port_PinType)16	/* Pin 0 in Port 2 */
#define PORT_PIN_17                     (Port_PinType)17 	/* Pin 1 in Port 2 */
#define PORT_PIN_18                     (Port_PinType)18 	/* Pin 2 in Port 2 */
#define PORT_PIN_19                     (Port_PinType)19 	/* Pin 3 in Port 2 */
#define PORT_PIN_20                     (Port_PinType)20 	/* Pin 4 in Port 2 */
#define PORT_PIN_21                     (Port_PinType)21 	/* Pin 5 in Port 2 */
#define PORT_PIN_22                     (Port_PinType)22 	/* Pin 6 in Port 2 */
#define PORT_PIN_23                     (Port_PinType)23 	/* Pin 7 in Port 2 */

#define PORT_PIN_24                     (Port_PinType)24 	/* Pin 0 in Port 3 */
#define PORT_PIN_25                     (Port_PinType)25 	/* Pin 1 in Port 3 */
#define PORT_PIN_26                     (Port_PinType)26 	/* Pin 2 in Port 3 */
#define PORT_PIN_27                     (Port_PinType)27 	/* Pin 3 in Port 3 */
#define PORT_PIN_28                     (Port_PinType)28 	/* Pin 4 in Port 3 */
#define PORT_PIN_29                     (Port_PinType)29 	/* Pin 5 in Port 3 */
#define PORT_PIN_30                     (Port_PinType)30 	/* Pin 6 in Port 3 */
#define PORT_PIN_31                     (Port_PinType)31 	/* Pin 7 in Port 3 */

#define PORT_PIN_32                     (Port_PinType)32 	/* Pin 0 in Port 4 */
#define PORT_PIN_33                     (Port_PinType)33 	/* Pin 1 in Port 4 */
#define PORT_PIN_34                     (Port_PinType)34 	/* Pin 2 in Port 4 */
#define PORT_PIN_35                     (Port_PinType)35 	/* Pin 3 in Port 4 */
#define PORT_PIN_36                     (Port_PinType)36 	/* Pin 4 in Port 4 */
#define PORT_PIN_37                     (Port_PinType)37 	/* Pin 5 in Port 4 */

#define PORT_PIN_38                     (Port_PinType)38 	/* Pin 0 in Port 5 */
#define PORT_PIN_39_LED1_CHANNEL         (Port_PinType)39 	/* Pin 1 in Port 5 */
#define PORT_PIN_40                     (Port_PinType)40 	/* Pin 2 in Port 5 */
#define PORT_PIN_41                     (Port_PinType)41 	/* Pin 3 in Port 5 */
#define PORT_PIN_42_SW1_CHANNEL         (Port_PinType)42 	/* Pin 4 in Port 5 */

/******************************************************************************************************
 *                            	   THE PIN DEFAULT CONFIGURATIONS                                     *
 ******************************************************************************************************/

/* PORT Default Configurations */
#define PORT_PIN_DEFAULT_MODE                   (PORT_PIN_MODE_GPIO) /* The Default Mode of all Pins is GPIO Pin */
#define PORT_PIN_DEFAULT_DIRECTION              (PORT_PIN_IN)        /* The Default Direction of all Pins is Input Pin */
#define PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE   (DIR_CHANGEABLE)     /* The Default Changeable Direction of all Pins is (Changeable) */
#define PORT_PIN_DEFAULT_MODE_CHANGEABLE        (MODE_CHANGEABLE)    /* The Default Changeable Mode of all Pins is (Changeable) */
#define PORT_PIN_LEVEL_VALUE                    (STD_LOW)            /* The Default Initial Value of all Pins is Low (Logic 0) */
#define PORT_PIN_DEFAULT_INTERNAL_RESISTOR      (OFF)                /* The Default Internal Resistor Value of all Pins is OFF (No Resistor) */
	
#endif /* PORT_CFG_H */
