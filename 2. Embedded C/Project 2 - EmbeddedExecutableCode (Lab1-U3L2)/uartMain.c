#include "uartHeader.h"

#define UART0DR *((volatile unsigned int* const)((unsigned int*)0x101f1000)) 

void Uart_Send_String (unsigned char* Uart_Recieved_String){

	while(*Uart_Recieved_String != '\n'){

		UART0DR = (unsigned int)(*Uart_Recieved_String);
		Uart_Recieved_String++;
	}

}