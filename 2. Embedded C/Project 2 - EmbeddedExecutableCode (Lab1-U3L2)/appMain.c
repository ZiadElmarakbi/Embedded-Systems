#include "uartHeader.h"

unsigned char Send_String[100] = "Learn-IN-Depth: <Ziad Elmarakbi>";

void main(void){

while(1){
	Uart_Send_String(Send_String);
}

}


