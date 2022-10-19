/*  Created on: Sep 29, 2022
 * Developer: Ziad Elmarakbi
 */

// header Protection
#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "stdbool.h"
#define size_limit 5
#define string_size 15
#define courses_count 5

#define DPRINTF(...) {fflush(stdin); \
		fflush(stdout); \
		printf(__VA_ARGS__);\
		fflush(stdin); \
		fflush(stdout);}

typedef struct{
	char firstname[string_size];
	char lastname[string_size];
	uint32_t rollnum;
	double gpa;
	uint32_t courseId[courses_count];
}Sstudent;

typedef struct {
	Sstudent* base;
	Sstudent* head;
	Sstudent* tail;
	uint32_t count;
	uint32_t length;
}fifo_student;

typedef enum {
	fifo_no_error,
	fifo_null,
	fifo_full,
	fifo_empty
}fifo_status;

typedef enum {
	system_no_error,
	system_has_error
}Function_status;

// ---------------------------System APIs---------------------------//
void welcome(void);
Function_status QueueEmptyCheck(fifo_student* fifo_p);
Function_status Add_stud_manually(fifo_student* fifo);
Function_status Reg_studs_bycourseId(fifo_student* fifo_p);
Function_status Update_stud(fifo_student* fifo_p);
Function_status studs_count(fifo_student* fifo_p);
Function_status delete_stud(fifo_student* fifo);
Function_status Find_stud_byId(fifo_student* fifo_p);
Function_status Find_stud_byFirstName(fifo_student* fifo_p);
Function_status Add_stud_fromfile(fifo_student* fifo_p);
void count(uint32_t countstud);
void show_stud(Sstudent* temp, uint32_t i);
void print_all(fifo_student* fifo_p);

// ---------------------------FIFO APIs---------------------------//
fifo_status fifo_init(fifo_student* fifo_p, Sstudent* student, uint32_t length);
fifo_status fifo_enqueue(fifo_student* fifo_p, Sstudent* student);
fifo_status fifo_dequeue(fifo_student* fifo_p);

#endif /* SYSTEM_H_ */
