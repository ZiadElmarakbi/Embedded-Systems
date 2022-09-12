/*
 * Typedefs.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Ziad
 */

/*
 * Typedefs.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Ziad
 */
#ifndef TYPEDEF_H_
#define TYPEDEF_H_



typedef unsigned char 		 boolean;

typedef unsigned char 		 uint8;
typedef char   				 int8;
typedef unsigned short 		 uint16;
typedef short   			 int16;
typedef unsigned int 		 uint32;
typedef int   				 int32;
typedef long long 			 uint64;
typedef unsigned long long   int64;
typedef float   			 float32;
typedef double  			 double64;


// Volatile Types (Doesn't get affected by optimization)
// It's State can be changed by hardware from memory bus

typedef volatile boolean	 vboolean;

typedef volatile uint8       vuint8;
typedef volatile int8	 	 vint8;
typedef volatile uint16      vuint16 ;
typedef volatile int16       vint16;
typedef volatile uint32      vuint32 ;
typedef volatile int32  	 vint32;
typedef volatile uint64		 vuint64;
typedef volatile int64 		 vint64 ;
typedef volatile float32  	 vfloat32;
typedef volatile double64    vdouble64;






#endif /* TYPEDEF_H_ */
