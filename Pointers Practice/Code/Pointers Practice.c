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

//----------------------------------------------------------
//int check(int, int);
//int main(){
//
//	int c;
//	c = check(10,20);
//	printf("c=%d\n",c);
//	return 0;
//}
//
//int check (int i, int j){
//
//	int *q, *p;
//	p = &i;
//	q = &j;
//
//	return(i>=45?*p:*q); // Correct way to use return with ternary operator
//}
//--------------------------------------------------------------


int main(){

int a = 10;
void *p = (int*)&a;

	return 0;
}

