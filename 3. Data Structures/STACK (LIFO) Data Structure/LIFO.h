/*
 * LIFO.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Ziad
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint32_t* base;
	uint32_t* head;
	uint32_t count;
	uint32_t length;
}LIFO_buffer;
typedef enum {
	Lifo_no_Error,
	Lifo_full,
	Lifo_empty,
	// Lifo_null

}LIFO_Status;

LIFO_Status lifo_init(LIFO_buffer*, uint32_t*, uint32_t);
LIFO_Status lifo_Push(LIFO_buffer*, uint32_t);
LIFO_Status lifo_Pop(LIFO_buffer*, uint32_t*);

#endif /* LIFO_H_ */
