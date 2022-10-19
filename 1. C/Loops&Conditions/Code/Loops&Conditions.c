#include <stdio.h>
#include "string.h"

int main() {

	//Ex1:(Even and Odd Checker)
	/*int num; char confirm;
	OddEvenChecker: // Label
	printf("Enter the Integer You Want to Check: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	if((num%2)==0){
		printf("%d is Even\n",num);
	}
	else{
		printf("%d is Odd\n",num);
	}

	printf("Do you want to evaluate again (y/n): ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&confirm);

	if(confirm =='y')
		goto OddEvenChecker;*/
// Can be done with do while or while alone
//-----------------------------------------------------------------

	//Ex2: (Vowels and constants Identifier )
  /*char Alphabet, confirm;

do{
	printf("Enter an alphabet: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&Alphabet);

	switch (Alphabet){

	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	{
		printf("%c is a vowel\n",Alphabet);
	}
	break;

	default:
		printf("%c is a constant\n", Alphabet);
		break;
	}

	printf("Do you want to repeat program?");
	fflush(stdin); fflush(stdout);
	scanf("%c", &confirm);
}
	while (confirm=='y');*/
//-----------------------------------------------------------------

	//Ex3: (Largest Number Identifier)
	/*float a,b,c,ans;
	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f\n %f\n %f", &a, &b, &c);*/

//Method1:

	/*if(a>b)
	{

		if(a>c)
			printf("Largest Number is: %f",a);
		else
			printf("Largest Number is: %f",c);

	}
	else
	{

		if(b>c)
			printf("Largest Number is: %f",b);
		else
			printf("Largest number is: %f",c);
	}*/

//Method2:

	/*ans = (a>b ?(a>c?a:c):(b>c?b:c)); //Ternary Operator for Nested Condition
	printf("%f",ans);*/

//-----------------------------------------------------------------

	//Ex4 (Unsigned/signed integer checker)
	/*float num;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num);*/

//Method 1:
	/*(num>0 ? (printf("%f is Positive",num)):
			(num==0)?(printf("You Entered Zero"))
					:(printf("%f is Negative",num)));*/
//Method 2:
// Using if else conditions (easy)

//-----------------------------------------------------------------

	//Ex5:////// repeat again, (Alphabet Checker)
//Method 1 (Hard way)
	/*int flag, i;
	char character;
	char alphabets[26] = {'a','b','c','d','e','f','g',
			'h','i','j','k','l','m','n','o','p','q','r','s',
			't','u','v','w','x','y','z'};

	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&character);

	for(i=0, flag=-1; i<26; i++){

		if(character==alphabets[i]){
			flag = i;
		}
	}
	if(flag==-1){

		printf("%c is not an alphabet", alphabets[flag]);
	}

	else{

		printf("%c is an alphabet", character);
	}*/

//Method 2 (easy way)
	/*char C;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&C);

	if((C>='a' && C<='z')||(C>='A' && C<='Z')){
		printf("%c is an alphabet ",C);
	}
	else{
		printf("%c is not an alphabet",C);
	}*/
//-----------------------------------------------------------------

	//Ex6 (Sum of natural numbers)
	/*int i,n;
	int sum = 0;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	for(i=1; i<=n; i++){

		sum = sum + i;

	}
	printf("Sum = %d",sum);*/
//-----------------------------------------------------------------

	//Ex7 (Factorial Checker)
	/*int i,n;
	int factorial = 1;
	printf("Enter any positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	for(i=1; i<=n; i++){

		factorial = factorial * i;
	}

	(n==0 ? (printf("Factorial is 1")):(n<0?
			(printf("Error!!! Factorial doesn't exist")):
			(printf("factorial = %d",factorial))));*/

// Can use if else conditions
//-----------------------------------------------------------------

	//Ex8 (Calculator)
	/*char c;
	float num1, num2;

	printf("Enter an Operator * / +  - : ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &c);

	switch (c){

	case '*':
	{
		printf("Enter two Operands: ");
		fflush(stdin); fflush(stdout);
		scanf("%f\n %f", &num1, &num2);
		printf("%.2f %c %.2f = %.2f",num1,c,num2,num1*num2);
	}
	break;
	case '/':
	{
		printf("Enter two Operands: ");
		fflush(stdin); fflush(stdout);
		scanf("%f\n %f", &num1, &num2);
		printf("%.2f %c %.2f = %.2f",num1,c,num2,num1/num2);
	}
	break;
	case '+':
	{
		printf("Enter two Operands: ");
		fflush(stdin); fflush(stdout);
		scanf("%f\n %f", &num1, &num2);
		printf("%.2f %c %.2f = %.2f",num1,c,num2,num1+num2);
	}
	break;
	case '-':
	{
		printf("Enter two Operands: ");
		fflush(stdin); fflush(stdout);
		scanf("%f\n %f", &num1, &num2);
		printf("%.2f %c %.2f = %.2f",num1,c,num2,num1-num2);
	}
	break;
	default:
	{
		printf("You entered a wrong operand");
	}
	break;

	}*/
//-----------------------------------------------------------------

	//Ex9 (Pattern1)
//	int i, j;
//	int num = 0;
//
//	for(i=0; i<=9; i++)
//	{
//
//		for(j=i; j<=9; j++){
//
//			printf("% d  ",j);
//		}
//		printf("\n");
//
//	}
	return 0;
}



