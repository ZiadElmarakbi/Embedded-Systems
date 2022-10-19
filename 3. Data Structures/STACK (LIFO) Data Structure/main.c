#include "LIFO.h"

uint32_t buffer[5];

int main(){

	uint32_t i, item;
	LIFO_buffer Send_buffer;
	LIFO_Status status;

	status  = lifo_init(&Send_buffer, buffer, 5);

	if(status == Lifo_no_Error){

		for(i = 0; i < 5; i++){

			status = lifo_Push(&Send_buffer,i);

			if(status == Lifo_no_Error)
				printf("Pushing %d",i);

			else
				printf("Lifo is Full");

		}

		printf("\n");
		fflush(stdin); fflush(stdout);

		for(i = 0; i < 5; i++){

			status = lifo_Pop(&Send_buffer, &item);

			if(status == Lifo_no_Error)
				printf("Popping : %d\n",item);

			else
				printf("Lifo is Empty");
		}
		printf("\n");
		fflush(stdin); fflush(stdout);
	}
	else{printf("Lifo is Null");}
	return 0;
}










