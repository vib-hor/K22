/* ###################################################################
**     Filename    : rtos_main_task.c
**     Project     : uart
**     Processor   : MK22FN1M0AVLH12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-08-24, 18:28, # CodeGen: 1
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         main_task - void main_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file rtos_main_task.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup rtos_main_task_module rtos_main_task module documentation
**  @{
*/         
/* MODULE rtos_main_task */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "fsl_uart_driver.h"
#include "fsl_clock_manager.h"
#include "mqx.h"
#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/* Initialization of Processor Expert components function prototype */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
extern void PEX_components_init(void);
#endif 

/*
** ===================================================================
**     Callback    : main_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void main_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	/*const uint8_t buffStart[]   = "\r\n++++++++++++++++ UART Send/Receive Blocking Example Start +++++++++++++++++\r\n";
	const uint8_t bufferData1[] = "\r\nType characters from keyboard, the board will receive and then echo them to terminal screen\r\n";
	 uint8_t rxChar = 0;
	    uint32_t byteCountBuff = 0;
*/
  /* Initialization of Processor Expert components (when some RTOS is active). DON'T REMOVE THIS CODE!!! */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
  PEX_components_init(); 
#endif 
  /* End of Processor Expert components initialization.  */
  uint8_t txbuff1 =1;
  uint8_t txbuff2 =2;

    /* Write your code here ... */



   // printf("Hello World!");
	  //UART_DRV_SendData(UART1_IDX, &txbuff1, 2);
	 // a = UART_DRV_SendDataBlocking(UART1_IDX, &txbuff1, 8 ,1000);
	 // printf("%d",a);
  while(1){
	  //UART_DRV_SendData(UART1_IDX, &txbuff1, 1);
	  _time_delay(1000);
	  printf("hello world!");
  }
	//  UART_DRV_SendData(UART1_IDX, &txbuff2, 1);
	//	GPIO_DRV_TogglePinOutput(GPIOC10);
	//	  _time_delay(1000);

////////////////////////////////////////////////////////////////////////
  /*uart_state_t uartState;

   uart_user_config_t uartConfig = {
       .bitCountPerChar = kUart8BitsPerChar,
       .parityMode      = kUartParityDisabled,
       .stopBitCount    = kUartOneStopBit,
       .baudRate        = 115200
   };
   SIM_SCGC4|= SIM_SCGC4_UART1_MASK;
   UART_DRV_Init(UART1_IDX, &uartState, &uartConfig);

	   // Inform to start blocking example
	    byteCountBuff = sizeof(buffStart);
	    UART_DRV_SendDataBlocking(UART1_IDX, buffStart, byteCountBuff, 1000u);

	    // Inform user of what to do
	    byteCountBuff = sizeof(bufferData1);
	    UART_DRV_SendDataBlocking(UART1_IDX, bufferData1, byteCountBuff, 1000u);

	    // Send/receive blocking function
	    while(true)
	    {
	        // Wait to receive input data
	        if (kStatus_UART_Success == UART_DRV_ReceiveDataBlocking(UART1_IDX, &rxChar, 1u, OSA_WAIT_FOREVER))
	        {
	            // Echo received character
	            UART_DRV_SendDataBlocking(UART1_IDX, &rxChar, 1u, 1000u);
	        }
	    }
*/


}

/* END rtos_main_task */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
