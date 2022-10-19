
#include "Linked_List_Header.h"

// Global Variables
uint32_t len;
uint32_t counter = 1;
uint32_t AdminStoredPass = 1234;
uint32_t AdminPass;

// Defining a Global pointer pointing to the first student in the list
Node* g_head = NULL;

uint32_t EmptyListCheck(){

	if(g_head == NULL){
		DPRINTF("List is Empty.\n\n");
		return true;
	}
	return false;
}

void welcome(){

	DPRINTF("Developed by Eng.Ziad Elmarakbi\n");
	DPRINTF("=================================================================================================|\n");
	DPRINTF("LEARN-IN-DEPTH\n");
	DPRINTF("=================================================================================================|\n");
	DPRINTF("UNIVERSITY DATABASE BY IMPLEMENTING A LINKED LIST DATA STRUCTURE ALGORITHM\n");
	DPRINTF("=================================================================================================|\n\n");
}

void EnterStudentInfo(Node* p){

	DPRINTF("\nEnter Your Student ID Number:");
	scanf("%d",&p->studentdata.ID);

	DPRINTF("Enter Your Full Name:");
	gets (p->studentdata.name);

	DPRINTF("Enter Your Height:");
	scanf("%f",&p->studentdata.Height);

	(p->studentdata.count) = counter;
	counter++;
}

void AddStudent(){

	/* It's always a good practice not to disturb the global head variable
	and instead use a looppointerorary pointer to point to the Nodes and perform
	the intended operations */

	Node* newstudent = NULL; // Intitializing a looppointer pointer with NULL

	// create a new list a let the newstudent pointer to point to it
	newstudent = (Node* )malloc(sizeof(Node));
	newstudent->nextstudent = NULL ;

	// if list is empty
	if(g_head == NULL){

		g_head = newstudent; // let the global head pointer to point to the 1st node
	}

	else{

		Node* looppointer = g_head ;
		while(looppointer->nextstudent != NULL){

			looppointer = looppointer->nextstudent ;

		}
		looppointer->nextstudent = newstudent ;
	}

	EnterStudentInfo(newstudent);
	DPRINTF("\nCongrats! A New Student has been Registered to the database.\n\n");

}

void DisplayStudents(){

	char character;
	uint32_t ID;
	//uint32_t count = 0;

	Node* p = g_head;

	if(EmptyListCheck() == true){/*Do Nothing*/}

	else{

		DPRINTF("Do you want to display All Students ? Y or N\n");
		scanf("%c",&character);

		if(character == 'Y'||character == 'y'){

			while(p){

				print(p);
				p = p->nextstudent ;
			}
		}

		else{

			DPRINTF("\nDo you want to display a specific student ? Y or N ");
			scanf("%c",&character);

			if (character == 'Y'||character == 'y')
			{

				DPRINTF("\nEnter Student ID You want to Display: ");
				scanf("%d",&ID);

				Node* p = g_head;

				while(p){

					if(p->studentdata.ID == ID){
						print(p);
						break;
					}
					p = p->nextstudent ;
				}
			}

			else{

				DPRINTF("Go to main Menu.\n\n"); // Not sure wtf is this ??!!
			}
		}
	}
}

void deleteALL(){

	Node* loopALL = g_head;

	if (EmptyListCheck() == true){/*Do Nothing*/}

	else{
		while(loopALL){

			Node* deleteNow = loopALL ;
			loopALL = loopALL->nextstudent ;
			free(deleteNow) ;
		}
		g_head = NULL;
		counter = 1;
	}
}

void getNth(){

	if (EmptyListCheck() == true){/*Do Nothing*/}

	else{
		uint32_t i, getNth;

		DPRINTF("Enter the Element Number You want to Obtain:");
		scanf("%d",&getNth);

		Node* temp = g_head ;
		// uint32_t count = 1;
		for(i = 1 ; temp != NULL; i++){

			if(i == getNth){
				print(temp);
				break ;
			}
			temp = temp->nextstudent ;
		}
	}
}

void getNthEnd(){

	if(EmptyListCheck() == true){}

	else{
		uint32_t cnt = 1, n;
		Node *p1 = g_head, *p2 = g_head;

		DPRINTF("Enter the 'N'th Element You want to Find from the end of the list:");
		scanf("%d",&n);

		while(cnt <= n){
			p2 = p2->nextstudent ;
			cnt++ ;
		}

		while(p2){
			p2 = p2->nextstudent ;
			p1 = p1->nextstudent ;
		}
		print(p1);
	}
}

void MiddleList(){

	Node* slowp = g_head;
	Node* fastp = g_head;

	if (EmptyListCheck()== true){/*Do Nothing*/}

	else{

		while(fastp && fastp->nextstudent){

			slowp = slowp->nextstudent;
			fastp = fastp->nextstudent->nextstudent;
		}

		print(slowp);
	}
}

void ReversedList(){
	// Node* p = g_head;

	if (EmptyListCheck() == true){/*Do Nothing*/}

	else{
		uint32_t i, j, k;

		i = 0;
		j = length() - 1;

		Node  *lagpointer = g_head, *leadpointer = g_head,*viewreverse = g_head;

		while(i<j){

			k = 0;
			while(k<j){

				// Let the lead pointer reach to the end of the linked list
				leadpointer = leadpointer->nextstudent ;
				k++ ;
			}

			dataType temp ;

			temp = leadpointer->studentdata ;
			leadpointer->studentdata = lagpointer->studentdata ;
			lagpointer->studentdata = temp ;

			i++;
			j--;

			lagpointer = lagpointer->nextstudent ;
			leadpointer = g_head ;

		}

		while(viewreverse!= NULL){

			print(viewreverse);
			viewreverse = viewreverse->nextstudent ;
		}
		DPRINTF("###_________Please Press 9 again to return the list in Ascending order_________###\n\n");
	}
}

uint32_t length(){

	uint32_t count1 = 0;

	if (EmptyListCheck() == true){return 0;}

	else{

		Node* looppointer = g_head ;
		while(looppointer->nextstudent != NULL){

			looppointer = looppointer->nextstudent ;
			count1++;
		}
		return count1+1;
	}
}

uint32_t DeleteStudent(){

	// Checking if the list is empty
	if (EmptyListCheck() == true){return 0;}

	else{
		uint32_t ID;
		Node *selectedstud = g_head, *prevstud = NULL;

		DPRINTF("Enter Student ID you Want to delete:\n");
		scanf("%d",&ID);

		// while pointer pointing to the Node is not equal to NULL
		while(selectedstud){

			// If the entered ID matches the one stored in any of the nodes
			if(selectedstud->studentdata.ID == ID){

				// 1st Case when the node we want to delete is anywhere in between the list
				if(prevstud)
				{
					prevstud->nextstudent = selectedstud->nextstudent ;
					selectedstud->nextstudent = NULL ;
				}

				// 2nd case when we want to delete first node in the list
				else
				{
					g_head = selectedstud->nextstudent ;
					selectedstud->nextstudent = NULL;
				}

				free(selectedstud);
				counter--;
				return 1;
			}

			prevstud = selectedstud ;
			selectedstud = selectedstud->nextstudent ;
		}

		DPRINTF("Didn't find the ID in the List.\n\n");
	}
	return 0;
}

void print(Node* p){

	DPRINTF("\n\t|===================== Student %d =====================|",(p->studentdata.count));
	DPRINTF("\n\t\tStudent ID : %d",p->studentdata.ID);
	DPRINTF("\n\t\tStudent Name is : %s",p->studentdata.name);
	DPRINTF("\n\t\tStudent Height is : %f\n\n",p->studentdata.Height);
}
