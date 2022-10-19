
#include "LIFO.h"

LIFO_Status lifo_init(LIFO_buffer* lifo_ptr, uint32_t* buff, uint32_t length){

	// if(buff == NULL){return Lifo_null;}

		lifo_ptr->head = buff;
		lifo_ptr->base = buff;
		lifo_ptr->count = 0;
		lifo_ptr->length = length;

		return Lifo_no_Error;

}


LIFO_Status lifo_Push(LIFO_buffer* lifo_ptr, uint32_t item){

	if(lifo_ptr->count == lifo_ptr->length){return Lifo_full;}

	else
	{
		*(lifo_ptr->head++) = item;
		lifo_ptr->count++ ;
		return Lifo_no_Error;
	}
}


LIFO_Status lifo_Pop(LIFO_buffer* lifo_ptr, uint32_t* item){

	if(lifo_ptr->count == 0){return Lifo_empty;} // Used brackets with if to prevent Misra C Violation

	else
	{
		lifo_ptr->head-- ;
		*item = *(lifo_ptr->head);
		lifo_ptr->count-- ;
		return Lifo_no_Error;
	}
}

