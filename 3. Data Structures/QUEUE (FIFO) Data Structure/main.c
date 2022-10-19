/*
 * main.c
 *
 *  Created on: Sep 27, 2022
 *      Author: Ziad
 */

#include "FIFO.h"

Element_type buffer[5], i, item;
fifo_t send_buffer ;
fifo_status status ;

int main(){

	status = fifo_init(&send_buffer, buffer, size);

	if(status == fifo_no_error){

		for(i = 0; i < size; i++){

			status = fifo_enqueue(&send_buffer, i);

			if(status == fifo_full){printf("fifo is full");}

			else{ printf("queuing %d\n",i); }
		}
		printf("\n");

		for(i = 0; i < size; i++){

			status = fifo_dequeue(&send_buffer, &item);

			if(status == fifo_full){printf("fifo is full");}

			else{ printf("dequeuing %d\n",item); }
		}
		printf("\n");

	}
	return 0;
}

