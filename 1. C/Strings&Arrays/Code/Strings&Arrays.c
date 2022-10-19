/*
 ============================================================================
 Name        : ALLExcercisesHW3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main() {

	// Ex1: (Sum of two matrices)
	/*float num1[3][3], num2[3][3], sum[3][3];
	int a, b;

	printf("Enter the Elements of the 1st Matrix: \n");

	for (a=1; a<3; a++){

		for (b=1; b<3; b++){

			printf("Enter a%d%d: ",a,b);
			fflush(stdin); fflush(stdout);
			scanf("%f",&num1[a][b]);
		}
	}
	printf("Enter the elements of 2nd Matrix: \n");

	for (a=1; a<3; a++){

		for (b=1; b<3; b++){

			printf("Enter a%d%d: ",a,b);
			fflush(stdin); fflush(stdout);
			scanf("%f",&num2[a][b]);
		}
	}

	printf("Sum of Matrices = \n");

	for (a=1; a<3; a++){

		for (b=1; b<3; b++){

			sum[a][b] = num1[a][b] + num2[a][b];
		}
	}


	for (a=1; a<3; a++){

		for (b=1; b<3; b++){
			printf("%.2f \t",sum[a][b]);
		}
		printf("\n");
	}*/

//----------------------------------------------------

	//Ex2: (Average of Numbers Entered)

	/*int data, i;
	float num[10], sum = 0.0, average;

	printf("Enter Numbers of Data: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&data);

	for(i=1; i<=data; i++){
		printf("%d. Enter Number: ",i);
		fflush(stdin); fflush(stdout);
		scanf("%f",&num[i]);
		sum = sum + num[i];
	}
	average = sum/(i-1);
	printf("Average = %f",average);*/
//----------------------------------------------------

	//Ex3: (Transpose of a Matrix)

	/*int i,j,rows,cols;
	float values[10][10], trans[10][10];

	printf("Enter the Rows and Columns: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&rows, &cols);
	printf("Enter the elements of Matrix: \n ");

	for (i=1; i<=rows; i++){
		for(j=1; j<=cols; j++){

			printf("Enter elements of a%d%d: ",i,j);
			fflush(stdin); fflush(stdout);
			scanf("%f",&values[i][j]);
		}

	}
	printf("\nEntered Matrix: \n");

	for (i=1; i<=rows; i++){
		for(j=1; j<=cols; j++){

			printf("%.1f \t",values[i][j]);
		}
		printf("\n");
	}

	for (i=1; i<=rows; i++){
		for(j=1; j<=cols; j++){

			trans[i][j] = values[j][i];
		}
	}

	printf("Transpose of Matrix: \n");

	for (i=1; i<=rows; i++){
		for(j=1; j<=cols; j++){

			printf("%.1f \t",trans[i][j]);
		}

		printf("\n");
	}*/
//----------------------------------------------------

	//Ex4: (Insertion between array) //my way
//
//	int arr[30], num, element, loc, i;
//
//	printf("Enter Number of Elements: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d", &num);
//
//	for(i=0; i<num; i++){
//		scanf("%d",&arr[i]);
//	}
//
//	printf("\nEnter element you want to insert: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d", &element);
//
//	printf("\nEnter location you want to insert: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%d", &loc);
//
//	for(i = num-1; i>=loc; i--){
//
//		arr[i + 1] = arr[i];
//	}
//
//	arr[loc] = element;
//
//	for(i = 0; i<num+1; i++){
//		printf("%d", arr[i]);
//	}


//----------------------------------------------------

	//Ex5: (Search an element) ##Question
/*	int elements, search, i;
	int Ele[10];

	printf("Enter no of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&elements);

	for(i=1; i<=elements; ++i){

		scanf("%d",&Ele[i]);
		printf("%d \t",Ele[i]);

	}

	printf("\nEnter the elements to be searched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&search);

	for(i=1; i<=elements; i++){

		if(search==Ele[i]){

			printf("Number found at location = %d",i);
			break;
		}
	}

	if (search!=Ele[i]){
		printf("Number not Found");
	}*/
//----------------------------------------------------

		//Ex6: (Frequency of character)

//	char text[50], freq;
//	int store = 0, i;
//
//	printf("Enter a string: ");
//	fflush(stdin); fflush(stdout);
//	gets(text);
//
//	printf("\nEnter a character to find frequency: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%c",&freq);
//
//	for (i=0; text[i]!='\0'; i++){
//
//		if(freq==text[i]){
//
//			++store;
//		}
//	}
//	printf("Frequency of %c = %d",freq, store);
//----------------------------------------------------

	//Ex7: (Length of string)

//	char string[100], i, store=0;
//
//	printf("Enter a String: ");
//	fflush(stdin); fflush(stdout);
//	scanf("%s",string);
//
//	for(i=0; string[i]!='\0'; ++i){
//
//		store += i;
//	}
//	printf("Length of string: %d",store);
//----------------------------------------------------

	//Ex8: (Reverse a String)
//	char string[100], temp;
//	int i, j;
//
//	printf("\n Enter a String: ");
//	fflush(stdin); fflush(stdout);
//
//	gets(string);
//	i = 0; j = strlen(string)-1;
//
//	while(i<j){
//
//		temp = string[i];
//		string[i] = string[j];
//		string[j] = temp;
//		i++;
//		j--;
//	}
//
//	printf("\n Reverse String is %s",string);
//
//
//----------------------------------------------------

	return 0;
}






