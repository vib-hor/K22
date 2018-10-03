/* ###################################################################
**     Filename    : rtos_main_task.c
**     Project     : UARTbaremetal
**     Processor   : MK22FN1M0AVLH12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-08-30, 22:58, # CodeGen: 1
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
#include"mqx.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
void itoa(int a , char * ch);
void put(char *ptr_str);
void uart_putchar (char ch);
uint8_t uart_getchar ();

void itoa (int a ,char *ch)
{
 	for(int i = 9 ; i >= 0 ; i--)
 	{
 		ch[i] = (a%10 + 48);
 		a=(a-a%10)/10;
 	}
}

void put(char *ptr_str)
{
while(*ptr_str)
uart_putchar(*ptr_str++);
}
//////////
void uart_putchar (char ch)
{
/* Wait until space is available in the FIFO */
while(!(UART1_S1 & UART_S1_TDRE_MASK));
/* Send the character */ UART1_D = (uint8_t)ch;
}
////////
uint8_t uart_getchar ()
{
/* Wait until character has been received */
while (!(UART1_S1 & UART_S1_RDRF_MASK));
/* Return the 8-bit data from the receiver */
return UART1_D;
}

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
	uint16_t ubd;
	uint8_t temp;
int a = 123456789;
	char chr ,temp1[10];

	itoa (a , temp1);
	/* Initialization of Processor Expert components (when some RTOS is active). DON'T REMOVE THIS CODE!!! */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
  PEX_components_init(); 
#endif 
  /* End of Processor Expert components initialization.  */
 /////////////////////////////////////////////////////////////////////////////////////
  SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
  SIM_SCGC4 |= SIM_SCGC4_UART1_MASK;

 //-----------------------------------------//Step-1
  PORTE_PCR0 |= PORT_PCR_MUX(3);
  PORTE_PCR1 |= PORT_PCR_MUX(3);
 //-----------------------------------------//Step-2
  /*UART1_C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK ); //Transmitter and Receiver off

  UART_C2_TE_MASK = 0x8; //to turn on Transmitter later
  UART_C2_RE_MASK = 0x4; //to turn on Receiver later
*/
  UART1_C1 = 0;

  ubd = (uint16_t)((120*1000000)/(115200 * 16));// UART baud rate = UART module clock/(Baud Rate * 16)
//ubd = (uint16_t)32.55208333333333;
  temp = UART1_BDH & ~(UART_BDH_SBR(0x1F));/*Save the value of UART1_BDH except SBR*/
  UART1_BDH |= temp | (((ubd & 0x1F00) >> 8));
  UART1_BDL |= (uint8_t)(ubd & UART_BDL_SBR_MASK);

  UART1_C2 |=(UART_C2_TE_MASK |UART_C2_RE_MASK); // RX and TX on
  //-----------------------------------------//Step-3

/*
  void put(char *ptr_str)
  {
  while(*ptr_str)
  uart_putchar(*ptr_str++);
  }
//////////
  void uart_putchar (char ch)
  {
   Wait until space is available in the FIFO
  while(!(UART1_S1 & UART_S1_TDRE_MASK));
   Send the character  UART1_D = (uint8_t)ch;
  }
  ////////
  uint8_t uart_getchar ()
  {
   Wait until character has been received
  while (!(UART1_S1 & UART_S1_RDRF_MASK));
   Return the 8-bit data from the receiver
  return UART1_D;
  }
*/

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  put(temp1);
	  _time_delay(1000);
/*    chr = uart_getchar();
    uart_putchar(chr);*/
    //BLUE_TOGGLE;
	  printf("1");
#ifdef PEX_USE_RTOS   
  }
#endif    
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
