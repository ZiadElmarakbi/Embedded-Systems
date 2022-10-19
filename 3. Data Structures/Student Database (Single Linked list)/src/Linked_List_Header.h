// File Guard to prevent Re-declaration
#ifndef _Header_File
#define _Header_File

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Typedefs

// To prevent Eclipse Printf problem
#define DPRINTF(...) {fflush(stdout);\
					  fflush(stdin);\
					  printf(__VA_ARGS__);\
					  fflush(stdout);\
					  fflush(stdin);}

// Defining Structures for student data and Node.
typedef struct Sdata{
	uint32_t count;
	uint32_t ID;
	char name[30];
	float Height;
}dataType;
typedef struct Student {
	dataType studentdata;
	struct Student* nextstudent ;
}Node;
enum Condition{false, true};

// Function Prototypes
void AddStudent(void);
void DisplayStudents(void);
void deleteALL(void);
void getNth(void);
void getNthEnd(void);
void MiddleList(void);
void ReversedList(void);
void welcome(void);
void EnterStudentInfo(Node* p);
void print(Node* p);
uint32_t length(void);
uint32_t DeleteStudent(void);
uint32_t EmptyListCheck(void);

#endif







