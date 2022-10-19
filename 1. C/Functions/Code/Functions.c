/*
 ============================================================================
 Name        : FunctionsHW4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* All the functions are defined at the end of the file
but prototyped at the beginning */

#include <stdio.h>
#include <string.h>
#include <math.h>

//---------------//PROTOTYPES\\-----------------

//int primechecker(int num1, int num2);
//int factorialR(int num);
//void reverseSt();
//int pownum(int num, int pow);


int main() {

// Ex1: (Prime number checker using two intervals)

//	int num1, num2;
//	printf("\n Enter two numbers: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d %d", &num1,&num2);
//	printf("prime Numbers between %d and %d are: ", num1,num2);
//	primechecker(num1,num2);

//----------------------------------------------------------------------

// Ex2: (Factorial Using Recursion)

//	int n,y;
//	printf("Enter a number: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d", &n);
//	 y = factorialR(n);
//    printf("%d",y);
//----------------------------------------------------------------------

//Ex3: (Reverse a Sentence Using Recursion) #NC

//	printf("Enter a String: ");
//	fflush(stdin); fflush(stdout);
//	reverseSt();
//
//	return 0;
//}
//----------------------------------------------------------------------

// Ex4: (Power of a Number Using Recursion)

//	int num,pow,Out;
//
//	printf("Enter base number: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d", &num);
//	printf("Enter Power number:");
//	fflush(stdin); fflush(stdout);
//	scanf("%d",&pow);
//	Out = pownum(num,pow);
//	printf("%d",Out);
//
//	return 0;
//}
//----------------------------------------------------------------------


//-----------Functions Declaration-------------

//int primechecker(int num1, int num2){
//	int i,k,count = 0;
//	for(i=num1; i<=num2; ++i){
//		count=0;
//
//		for (k=1; k<=i; ++k){
//
//			if(i%k==0){
//				count ++;
//			}
//		}
//		if (count==2){
//			printf("%d", i);
//		}
//	}
//	return i;
//}

//int factorialR(int n){
//
//	int fact;
//	if(n<=1)
//		return n;
//	else
//		fact = n*factorialR(n-1);
//	return fact;
//}

//void reverseSt(){
//
//	char c;
//
//	scanf("%c", &c);
//
//	if(c!='\n')
//	reverseSt();
//	printf("%c",c);
//
//}

//int pownum(int n, int p){
//
//	int res;
//	if (p==0){
//		return 1;
//	}
//	else{
//		res = n*pownum(n,p-1);
//	}
//	return res;
//}

