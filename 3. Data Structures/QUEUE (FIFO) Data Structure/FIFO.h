/*
 * FIFO.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Ziad
 */

#ifndef FIFO_H_
#define FIFO_H_
#define size 5
#define Element_type uint32_t // To make the code more generalized

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct {

	Element_type *base;
	Element_type *head;
	Element_type *tail;
	Element_type count;
	Element_type length;

} fifo_t;
typedef enum {

	fifo_no_error,
	fifo_full,
	fifo_empty

}fifo_status;

// APIs
fifo_status fifo_init(fifo_t* ,Element_type*, Element_type);
fifo_status fifo_enqueue(fifo_t* ,Element_type);
fifo_status fifo_dequeue(fifo_t* ,Element_type*);

#endif /* FIFO_H_ */
