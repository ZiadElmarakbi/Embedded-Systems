/*
 * FIFO.c
 *
 *  Created on: Sep 27, 2022
 *      Author: Ziad
 */
#include "FIFO.h"

// Initialize Queue
fifo_status fifo_init(fifo_t* fifo_p ,Element_type* buffer, Element_type length){

	fifo_p->base = buffer;
	fifo_p->head = buffer;
	fifo_p->tail = buffer;
	fifo_p->count = 0;
	fifo_p->length = length;

	return fifo_no_error;
}

fifo_status fifo_enqueue(fifo_t* fifo_p ,Element_type item){

	if(fifo_p->count == fifo_p->length){return fifo_full;}

	else{

		*(fifo_p->head) = item ;
		fifo_p->count++ ;

		if(fifo_p->head == fifo_p->base + (fifo_p->length * sizeof(Element_type)))
			fifo_p->head = fifo_p->base ;

		else
			fifo_p->head++ ;

		return fifo_no_error;
	}
}

fifo_status fifo_dequeue(fifo_t* fifo_p ,Element_type* item){


	if(fifo_p->count == 0){return fifo_empty;}

	else{

		*item = *(fifo_p->tail);
		fifo_p->count-- ;

		if(fifo_p->tail == fifo_p->base + (fifo_p->length * sizeof(Element_type)))
			fifo_p->tail = fifo_p->base ;

		else
			fifo_p->tail++ ;

		return fifo_no_error ;
	}
}
