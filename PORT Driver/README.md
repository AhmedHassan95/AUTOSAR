##AUTOSAR PORT DRIVER                                     

 
  [AUTHOR]: Ahmed Hassan
 

##PRE-REQUEST                                         

 
Before Read any file in this Driver, You must:
- Have All AUTOSAR Standard Documents (SWS) version 4.0.3
- IAR IDE Version 9.10.1

For Each file:
- Check the AUTOSAR version
- May or not Check the Module SW version 


 ##PROJECT DESCRIPTION                                     

 
This Project is to Toggle LED output using Button as an input
                  
    Requirements:
	- Button is considered Pressed if it is reads high for 60 ms
    - Button is considered Released if it is reads low for 60 ms
    - LED output needs to be refreshed every 40 ms
				 
    Design Considerations:
	- All Drivers compatible with Autosar Standard version 4.0.3
	- MCU: TM4C123GH6PM (Tiva C LaunchPad)
	- Frequency: 16 MHZ
    - Bulid MCAL contains DIO and TIMER drivers
    - Bulid ECUAL contains LED and BUTTON drivers
    - Bulid Services layer contains Scheduler
    - Bulid Application contains System Logic


 #USEFUL NOTES                                       

1. Vendor IDs: Used to determine which vendor developed the Driver/Module
2. Std_Types.h: Contains standard symbols + standard return types + version Info. structure
				ex: OK, NOT_OK			
3. platform_Types.h: Contains CPU type and endianess + Optimized types + target dependant 
					 type definitions  ex: uint8, uint16, ...							 
4. compiler.h: Contains compiler dependant words to make our driver abstracted from any compiler
			   ex: inline, static			   
5. common_Macros.h: Contains common macros used between all files ex: SET_BIT, CLEAR_BIT, ...
6. tm4c123gh6pm_registers.h: Contains all registers of our target (TM4C123GH6PM)
7. Det.h, Det.c: Contains All we need to report development Error 

---------------------------------------------------------------------------------------------

8. Dio_Regs.h: Contains DIO registers of our target (TM4C123GH6PM)
9. Dio_Cfg.h: Contains pre-compile configurations generated from the AUTOSAR tool
			  ex: Numbers of the configured Dio Channels
			  ex: Turn (ON/OFF) the development ERROR
			  ex: Turn (ON/OFF) the FlipChannels API 			  
10. Dio_PBcfg.h: Contains post build configurations 
				ex: Filled structure with the configured information used by Dio_Init API				
11. Dio.h: Contains API Service IDs + DET Error Codes for DIO Driver + DIO Data Types +
		   DIO function prototypes		   
12. Dio.c: Contains code of services provided by DIO Driver
		   ex: Dio_Init, Dio_WriteChannel, ...

---------------------------------------------------------------------------------------------

13. Port_Regs.h: Contains PORT registers of our target (TM4C123GH6PM)	
14. Port_Cfg.h: Contains pre-compile configurations generated from the AUTOSAR tool
			    ex: Numbers of the configured PINs in each PORT
			    ex: Turn (ON/OFF) the development ERROR
			    ex: Turn (ON/OFF) the PORT_SET_PIN_MODE_API 			  
15. Port_PBcfg.h: Contains post build configurations 
				  ex: Filled structure with the configured information used by Port_Init API		
16. Port.h: Contains API Service IDs + DET Error Codes for PORT Driver + PORT Data Types +
		    PORT function prototypes	   
17. Port.c: Contains code of services provided by PORT Driver
		    ex: Port_SetPinDirection, Port_SetPinMode, ...
		   
---------------------------------------------------------------------------------------------	

18. Gpt.h, Gpt.c: Contains general-purpose timer functions to init, start and stop the timer
				  (Should be in the OS Files as handling Interrupts is OS Task)
19. Os.h, Os.c: Contains OS scheduler that handles Application tasks
20. Button.h, Button.c: Contains Button functions code
21. Led.h, Led.c: Contains Led functions code
22. App.h, App.c: Contains Application Tasks (init Task, Button Task, Led Task, ...)

 #HEADERS FILES STRUCTURE                                 
 

- Open the sent image
		