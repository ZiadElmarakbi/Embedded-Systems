
#include "system.h"

extern fifo_student fifo_p;

int main() {

	uint32_t choice;
	welcome();

	while(true){

		DPRINTF("[Choose One of the Following Options]:\n\n");
		DPRINTF("1)...Add a Student Details From File\n");
		DPRINTF("2)...Add a Student Details Manually\n");
		DPRINTF("3)...Find a Student by ID Number\n");
		DPRINTF("4)...Find a Student by First Name\n");
		DPRINTF("5)...Find the Students Registered in a Course\n");
		DPRINTF("6)...Count of Students\n");
		DPRINTF("7)...Delete a Student\n");
		DPRINTF("8)...Update a Student\n");
		DPRINTF("9)...Show All Registered Students\n");
		DPRINTF("10)..Quit Program\n\n");

		DPRINTF("Please Enter Your Choice:");
		scanf("%d",&choice);

		switch(choice){

		case 1 :
			Add_stud_fromfile(&fifo_p);
			break;

		case 2:
			Add_stud_manually(&fifo_p);
			break;

		case 3:
			Find_stud_byId(&fifo_p);
			break;

		case 4:
			Find_stud_byFirstName(&fifo_p);
			break;

		case 5:
			Reg_studs_bycourseId(&fifo_p);
			break;

		case 6:
			DPRINTF("========================================================\n");
			DPRINTF("...Total Number of Students = %d\n",studs_count(&fifo_p));
			DPRINTF("========================================================\n\n");
			break;

		case 7:
			delete_stud(&fifo_p);
			break;

		case 8:
			Update_stud(&fifo_p);
			break;

		case 9:
			print_all(&fifo_p);
			break;

		case 10:
			exit(1);
			break;

		default:
			DPRINTF("==================================================================\n");
			DPRINTF("You have Entered a Wrong Choice, Please Enter your choice again...\n");
			DPRINTF("==================================================================\n\n");
			break;
		}
	}
	return system_no_error;
}

