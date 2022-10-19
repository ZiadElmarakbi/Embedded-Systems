/*
 ============================================================================
 Name        : Pointers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


//struct Employee {
//
//		char name[20];
//		int ID;
//	};

int main() {


//--------------------------------------------------------------------------

	// Q1) Handling Pointers

	/*	unsigned int *ptr = NULL, **ab = NULL, m;

	m = 29;
	ptr = &m;
	ab = &ptr;

	printf("Address of m : %p\n",ptr);
	fflush(stdin); fflush(stdout);
	printf("Value of m : %d\n\n",*ptr);
	fflush(stdin); fflush(stdout);

	printf("Address of Pointer ab : %p\n",*ab);
	fflush(stdin); fflush(stdout);

	**ab = 29;
	printf("Content of Pointer  ab : %d\n\n",**ab);
	fflush(stdin); fflush(stdout);

	printf("Address of Pointer ab : %p\n",*ab);
	fflush(stdin); fflush(stdout);

	**ab = 34;
	printf("Content of Pointer  ab : %d\n\n",**ab);
	fflush(stdin); fflush(stdout);

	printf("Address of m : %p\n",ptr);
	fflush(stdin); fflush(stdout);

	*ptr = 7;
	printf("Value of m : %d\n\n",*ptr);
	fflush(stdin); fflush(stdout);*/

//--------------------------------------------------------------------------

	// Q2) Reversing Alphabets

	/*unsigned char Alphabets = 'A';
	unsigned char* ptr = NULL;
	ptr = &Alphabets;

	int i;

	for(i=0; Alphabets>='A'&& Alphabets<='Z'; i++){

		printf("%c ",*ptr);
		Alphabets++;
	}*/

//--------------------------------------------------------------------------

	// Q3) Reversing a string

	/*char string[30], stringRev[30];
	char* ptrS = NULL, *ptrR = NULL;
	int i, j, temp;

	ptrS = string;
	ptrR = stringRev;

	printf("Input a String: ");
	fflush(stdin); fflush(stdout);
	scanf("%s", string);

	for(i = 0; *ptrS!='\0'; i++){
		ptrS++;
		temp = i;
	}
	// ptrS = string;
	for (j = temp; j >= 0; j--){

		ptrS--;
		*ptrR = *ptrS;
		ptrR++;
	}
	*ptrR = '\0';

	printf("\nReverse of the String is :  %s",stringRev);*/
//--------------------------------------------------------------------------

	// Q4) Reversing Number of Integers

	// First Way (Lengthy and Not Optimal)

	/*int arr[5], revArr[5];
	int* ptr,*rev;
	int i, j = 0;

	ptr = arr;

	printf("Input 5 Elements in the Array: \n");
	fflush(stdin); fflush(stdout);

	for(i = 0; i < sizeof(arr)/sizeof(int); ++i){

		printf("Element - %d: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",ptr);
		ptr++;
	}

	printf("\nThe Elements in Reverse Order are: \n");
	fflush(stdin); fflush(stdout);

	rev = revArr;

	for (j = i-1; j >= 0; j--){

		//i = 0;
		--ptr;
		*rev = *ptr;

		printf("Element - %d = %d\n",j+1,*rev);
		fflush(stdin); fflush(stdout);
		rev++;
	}*/

//--------------------------------------------------------------------------

	// Q4) 2nd Way (Optimal), uses less space

	/*int arr[15], n, i;
	int* ptr = NULL;

	ptr = arr;

	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);
	printf("\nInput %d number of elements in the array\n", n);
	fflush(stdin); fflush(stdout);

	for (i = 0; i<n; ++i){

		printf("Element %d: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",ptr);
		ptr++;
	}

	ptr = ptr-1;

	printf("\nThe elements of the array in reverse order are: \n");
	fflush(stdin); fflush(stdout);

	for(i = n; n > 0; --n){

		printf("Element %d: %d\n",n,*ptr);
		ptr--;
	}*/
//--------------------------------------------------------------------------

	// Q5) Pointer to Structure

	/*struct Employee Emp = {"Alex",1002};
	struct Employee* ptr = &Emp;

	printf("Employee Name: %s",ptr->name);
	fflush(stdin); fflush(stdout);
	printf("\nEmployee ID: %d",ptr->ID);*/

//--------------------------------------------------------------------------



	return 0;
}
