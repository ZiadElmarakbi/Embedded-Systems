#include "Linked_List_Header.h"

extern uint32_t len;
extern uint32_t AdminStoredPass;
extern uint32_t AdminPass;

void main()
{
	uint32_t choice; // Local variable
	welcome();
	DPRINTF("Please Enter the Admin Password to Access the database:");
	scanf("%d",&AdminPass);

	if(AdminStoredPass == AdminPass){

		DPRINTF("\n============== WELCOME TO THE DATABASE ADMIN ==============\n\n");
		DPRINTF("Choose One of the 10 Options Below:\n\n");

		while(1)
		{
			DPRINTF("1. Add a Student\n");
			DPRINTF("2. View Students\n");
			DPRINTF("3. Delete a Student\n");
			DPRINTF("4. Delete all Students\n");
			DPRINTF("5. [Feature 1]: Number of Registered Students\n");
			DPRINTF("6. [Feature 2]: get Nth Node from the List\n");
			DPRINTF("7. [Feature 3]: get Nth Node from the end the List\n");
			DPRINTF("8. [Feature 4]: Find the middle of the list\n");
			DPRINTF("9. [Feature 5]: View a Reversed list\n");
			DPRINTF("10. Quit Program\n\n");

			DPRINTF("Please Enter Your Choice:");
			scanf("%d",&choice);

			switch (choice){

			case 1: AddStudent();
			break;

			case 2: DisplayStudents();
			break;

			case 3: DeleteStudent();
			break;

			case 4: deleteALL();
			DPRINTF("All The Students Have been Deleted from Database\n\n");
			break;

			case 5: len = length();
			DPRINTF("Number of Students = %d\n\n",len);
			break;

			case 6: getNth();
			break;

		    case 7: getNthEnd();
			break;

			case 8: MiddleList();
			break;

			case 9: ReversedList();
			break;

			case 10: exit(1);
			break;

			default:
				DPRINTF("You've Entered a Wrong Choice\n\n");
				break;
			}
		}
	}

	else {

		DPRINTF("\nYou've Entered Incorrect Password\n\n");
	}
}

