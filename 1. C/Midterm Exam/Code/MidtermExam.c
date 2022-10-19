/*
 ============================================================================
 Name        : MIDTERM_EXAM1.c
 Author      : Ziad Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#define s 20

//____________________________________PROTOTYPES____________________________________


// int SumDecimal(int);
// int SumBinary(int);
// double squareroot(int);
// void primenumber(int,int);
// void revertdigits(void);
// int binarycounter(int);
// void UniqeNum(int arr[], int size);
// void takearr(int arr[], int size);
// int SumNumRec(int, int);
// void IntegerReverse(int arr[], int size);
// void StringReverse(char firstname[], char secondname[]);
int oneCount(int);

//__________________________________________________________________________________

int main() {

// ---------------------------------------------------------------------------------

	// Q1a) Function to take a number and sum all digits (return decimal number)

	/*char R;
	int num;

	Repeat:
	printf("Input: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);
	printf("Output --> %d", Sum(num));

	printf("\n\nDo you want to Execute Program Again y/n?");
	fflush(stdin); fflush(stdout);
	scanf("%c",&R);
	if(R == 'y')
		goto Repeat;*/
// ---------------------------------------------------------------------------------

	// Q1b) Function to take a number and sum all digits (return binary number)






// ---------------------------------------------------------------------------------

// Q2) Function to take a number and find its square root

	/*int num;

		printf("Input: ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&num);
		printf("Output --> %.3lf",squareroot(num));*/

// ---------------------------------------------------------------------------------

// Q3) Function to print out prime numbers between two integers

	/*int num1, num2;

	printf("Enter num1 and num2: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&num1, &num2);
	primenumber(num1,num2);*/

// ---------------------------------------------------------------------------------

// Q4) Function to revert a set of integers

	/*printf("Input: ");
	fflush(stdin); fflush(stdout);
	printf("Output: ");
	revertdigits();
*/
// ---------------------------------------------------------------------------------

// Q5) Function to count number of ones in binary number

	/*int num;

	printf("Input: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	printf("Output: %d ", binarycounter(num));*/

// ---------------------------------------------------------------------------------


// Q6) Function to return unique number in array with one loop
/*

	int size, arr[s];

	printf("Enter array size: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &size);
	takearr(arr,size);
	printf("Output:");
	UniqeNum(arr,size);

*/

// ---------------------------------------------------------------------------------

	// Q7) Function to sum numbers from 1 - 100 without loop

	//printf("%d",SumNumRec(1,100));

// ---------------------------------------------------------------------------------

	// Q8) Function to take an array ad reverse it's elements

//	int size, arr[20], i;
//
//	printf("Enter Array Size: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d",&size);
//
//	printf("\nEnter Array: ");
//	fflush(stdin); fflush(stdout);
//
//	for (i = 0; i<size; i++){
//		scanf("%d",&arr[i]);
//	}
//
//	IntegerReverse(arr,size);

// ---------------------------------------------------------------------------------

	// Q9) Function to reverse words in a string

//	char storearr[50], firstname[50], secondname[50];
//
//	printf("Enter Your first and last names: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%s%s",firstname,secondname);
//	strcpy(storearr,firstname);
//	strcat(storearr, " ");
//	strcat(storearr, secondname);
//	printf("%s\n",storearr);
//	StringReverse(firstname,secondname);
//

// ---------------------------------------------------------------------------------

	// Q10)) Function to take maximum number of one between two zeros

//	int num;
//
//	printf("Enter a number: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d", &num);
//	oneCount(num);



// ---------------------------------------------------------------------------------




return 0;
}
//____________________________________FUNCTIONS DEFINITION__________________________

/*
int SumDecimal(int num){


	int Rem, sum = 0;

	do{

		Rem = num%10;
		sum += Rem;
		num /= 10;

	}while(num>0);
	return sum;
}
*/

/*
double squareroot(int num){

	return sqrt(num);

}*/

/*
void primenumber(int num1, int num2){

	int i, cnt = 0, j;

	for(j = num1; j<=num2; ++j){
		cnt = 0;

		for (i=1; i<=j; ++i){

			if(j%i==0)
				cnt++;
		}

		if(cnt==2||cnt==1)
			printf("%d\t",j);
	}

}
*/

/*
void revertdigits(){

	char values;

	scanf("%c",&values);

	if(values!='\n'){
		revertdigits();
	}

	printf("%c",values);
}*/

/*
int binarycounter(int num){

	int i, count = 0;

	for(i=0; i<=31; i++){

		if((num & 1<<i) != 0)
			count++;
	}
	return count;
}*/

/*
void takearr(int arr[],int size){

	int k;
	for(k = 0; k<size; k++){

		scanf("%d",&arr[k]);

	}
}*/

/*
void UniqeNum(int arr[], int size){


	int i, j, count = 0, temp;


	for(j = 0; j<size; j++){
		count = 0;

		for(i = 1; i<size; i++){

			if(arr[j] == arr[i])
				count++;
		}

		if(count<2)
			temp = arr[j];
	}
	printf("%d",temp);
}*/

/*
int SumNumRec(int n,int m){

		if(n<=100)
		return (n+SumNumRec(n+1,m-1));

		else
			return 0;
}*/

/*void IntegerReverse(int arr[], int size){

	int i,j;

	i = 0;
	j = sizeof(size);

	while(i<j){
		arr[i] ^= arr[j];
		arr[j] ^= arr[i];
		arr[i] ^= arr[j];
		i++;
		j--;
	}

	for(i=0; i<size; i++){
		printf("%d",arr[i]);
	}
}*/

/*
void StringReverse(char firstname[], char secondname[]){

	char storerev[50];

	strcpy(storerev,secondname);
	strcat(storerev," ");
	strcat(storerev,firstname);
	printf("\nReversed String: %s",storerev);

}*/

//
//int oneCount(int num){
//
//	int i, j, cnt1, cnt2;
//
//
//
//}

//__________________________________________________________________________________



