/*
 ============================================================================
 Name        : Data.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
#define area(r) (pi*(r)*(r))

//_______________________Defining Structures & Functions Prototypes_________________________

//struct Sstudent {
//
//	char name[20];
//	int rollnum;
//	float marks;
//} X; //Since X is defined here, it's a global struct

//struct Sdistance {
//
//	int feet;
//	double inch;
//};

//struct Scomplex {
//
//	 double RealNO;
//	 double ImagNO;
// };

//struct SstudentArr {
//
//		char name[20];
//		int rollnum;
//		float marks;
//};


//struct Scomplex AddCom(struct Scomplex A, struct Scomplex B);
//struct Scomplex ReadComplex(char name []);
//void printComp(char name [], struct Scomplex C);


//__________________________________________________________________________________________



int main() {



//-----------------------------------------------------------------------------------

	// Ex1: Store name,roll, and marks of a student

	/*printf("Enter name: ");
	fflush(stdin); fflush(stdout);
	scanf("%s",X.name);
	printf("Enter Roll Number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&X.rollnum);
	printf("Enter Marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&X.marks);

	printf("\nDisplaying Information:\n");
	fflush(stdin); fflush(stdout);
	printf("Name: %s",X.name);
	fflush(stdin); fflush(stdout);
	printf("\nRoll: %d",X.rollnum);
	fflush(stdin); fflush(stdout);
	printf("\nMarks: %.2f",X.marks);*/

//-----------------------------------------------------------------------------------

	// Ex2: Adding Two distances

	/*struct Sdistance X, Y;

	printf("Enter Information for 1st distance:\n");
	fflush(stdin); fflush(stdout);
	printf("Enter feet: ")s;
	fflush(stdin); fflush(stdout);
	scanf("%d",&X.feet);
	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%lf",&X.inch);

	printf("\nEnter Information for 2nd distance:\n");
	fflush(stdin); fflush(stdout);
	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&Y.feet);
	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%lf",&Y.inch);

	printf("\nSum of distances = %d, %.2lf",
			(X.feet+Y.feet),(X.inch+Y.inch));*/

//-----------------------------------------------------------------------------------

	//Ex3: Adding two complex numbers by passing a structure to a function

//	struct Scomplex X, Y, Z;
//
//	X = ReadComplex("1st");
//	Y = ReadComplex("2nd");
//	Z =  AddCom(X,Y);
//	printComp("Sum = ",Z);

//-----------------------------------------------------------------------------------

	//Ex4: Array of Structures for student info

//	struct SstudentArr arr[10];
//
//	int count = 0, countdisp = 0;
//
//	printf("Enter information of students:\n\n");
//	fflush(stdin); fflush(stdout);
//
//	while(count<10){
//		printf("Enter Roll Number %d: ",count+1);
//		fflush(stdin); fflush(stdout);
//		scanf("%d",&arr[count].rollnum);
//		printf("Enter name: ");
//		fflush(stdin); fflush(stdout);
//		scanf("%s",arr[count].name);
//		printf("Enter Marks: ");
//		fflush(stdin); fflush(stdout);
//		scanf("%f",&arr[count].marks);
//		printf("\n");
//		fflush(stdin); fflush(stdout);
//
//		count++;
//
//	}
//
//	printf("\nDisplaying information of Students:\n\n");
//
//	for(countdisp=0; countdisp<10; countdisp++){
//
//		printf("Information of roll number %d\n", countdisp+1);
//		fflush(stdin); fflush(stdout);
//		printf("Name: %s\n", arr[countdisp].name);
//		fflush(stdin); fflush(stdout);
//		printf("Marks: %.2f\n",arr[countdisp].marks);
//		fflush(stdin); fflush(stdout);
//		printf("\n");
//		fflush(stdin); fflush(stdout);
//	}

//-----------------------------------------------------------------------------------

	//Ex5: Find Area of a Circle, passing arguments to macros

//	int radius;
//	float area;
//
//	printf("Enter the Radius: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d",&radius);
//	area = area(radius);
//	printf("Area = %.2f",area);

//-----------------------------------------------------------------------------------


	return 0;
}




//struct Scomplex ReadComplex(char name[]){
//
//	struct Scomplex C = {0, 0};
//
//	printf("\nFor %s Complex Number\n",name);
//	fflush(stdin); fflush(stdout);
//	printf("Enter Real and Imaginary Respectively: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%lf %lf", &C.RealNO, &C.ImagNO);
//	return C;
//
//}

//struct Scomplex AddCom (struct Scomplex A, struct Scomplex B){
//
//	struct Scomplex C;
//
//	C.RealNO = A.RealNO + B.RealNO;
//	C.ImagNO = A.ImagNO + B.ImagNO;
//
//	return C;
//
//}

//void printComp(char name [], struct Scomplex C){
//
//	printf("\n%s = %.2lf + %.2lf j",name,C.RealNO, C.ImagNO);
//}
//


