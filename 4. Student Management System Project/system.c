
#include "system.h"

fifo_student fifo_p; // FIFO Object
fifo_status status; // FIFO Status Object
uint32_t countstud1 = 0, add2loop = 0,  Reserved; // Global Counters
Sstudent student[size_limit]; // Array of Structures

//--------------------------------System FUNCTIONS-----------------------------------//

void welcome(){

	// Initializing QUEUE array
	status = fifo_init(&fifo_p, student, size_limit);

	DPRINTF("\n[============================WELCOME TO THE DATABASE=============================]\n\n");
	DPRINTF("                      System Developed by Eng.Ziad Elmarakbi\n");
	DPRINTF("                      _______________________________________\n\n");
	DPRINTF("                                 LEARN-IN-DEPTH\n");
	DPRINTF("                      _______________________________________\n\n");
	DPRINTF("                           {STUDENT MANAGEMENT SYSTEM}\n");
	DPRINTF("                      _______________________________________\n\n");
	DPRINTF("[=================================================================================]\n\n");

}

Function_status QueueEmptyCheck(fifo_student* fifo_p){

	if(fifo_p->count == 0){
		DPRINTF("QUEUE is Empty.\n\n");
		return system_has_error;
	}
	return system_no_error;
}

Function_status QueueFullCheck(fifo_student* fifo_p){

	if(fifo_p->count == fifo_p->length){
		DPRINTF("QUEUE is Full.\n\n");
		return system_has_error;
	}
	return system_no_error;
}

Function_status Add_stud_manually(fifo_student* fifo){

	Sstudent temp, *tempptr = fifo->base; 	// Taking an Object From Student type Structure
	uint32_t i, j, ID, countstud = 0;
	char add;

	if(QueueFullCheck(fifo) == system_has_error)
		return system_has_error ;

	DPRINTF("========================================================\n");
	DPRINTF("\t\t[REGISTERING STUDENT INFO]\n");

	flag:

	DPRINTF("========================================================\n");
	DPRINTF("Enter Student ID:");
	scanf("%d",&ID);

	for(i = 0 ; i < fifo->count; i++){

		if(tempptr->rollnum == ID){
			DPRINTF("========================================================\n");
			DPRINTF("[ERROR] Student ID Registered Before !\n");
			DPRINTF("========================================================\n\n");
			return system_has_error;
		}
		tempptr++ ;
	}

	temp.rollnum = ID;
	DPRINTF("\n[INFO] Student ID Added Successfully.\n");
	DPRINTF("---------------------------------------------------------\n");

	if(status == fifo_no_error){

		for(i = add2loop; i < size_limit; i++){

			DPRINTF("Enter Your First Name:");
			gets(temp.firstname);
			DPRINTF("Enter Your Last Name:");
			gets(temp.lastname);
			DPRINTF("Enter Your GPA:");
			scanf("%lf",&temp.gpa);

			DPRINTF("----------------Enter Your Course IDs----------------\n");
			for(j = 0; j < courses_count; j++){

				DPRINTF("Course ID %d:",j+1);
				scanf("%d",&temp.courseId[j]);
			}

			fifo_enqueue(&fifo_p, &temp);

			countstud++ ;  // Local
			countstud1++ ; // Global
			add2loop++ ; /* Will restore previous state of the last added student in the loop
									   so that when the user exits this function and return back to it
									   again to add another student it will loop from the last added
									   student to prevent overwriting on the existing student in the Queue */
			count(countstud);

			DPRINTF("Do you want to add another Student y/n ?\n");
			scanf("%c",&add);

			if(add == 'y'|| add == 'Y'){goto flag;}
			else{
				DPRINTF("..........Transferring to MAIN MENU..........\n\n");
				break;
			}
		}
	}
	else{DPRINTF("Queue is NULL\n\n");}
	return system_no_error;
}

Function_status Add_stud_fromfile(fifo_student* fifo){

	uint32_t temp_ID, i, j, countstud = 0;
	Sstudent sendstudent;
	Sstudent* temp = fifo->base;
	FILE* fileptr = fopen("Student_file.txt","r");

	// Check Queue first
	if(QueueFullCheck(fifo) == system_has_error)
		return system_has_error;

	// If the file doesn't Exist.
	if(!fileptr){
		DPRINTF("[ERROR] File Not found !!\n\n");
		return system_has_error;
	}

	// If the file exists
	while(!feof(fileptr) && !ferror(fileptr) && (fifo->count != fifo->length)){

		uint8_t unique = 1;
		fscanf(fileptr,"%u",&temp_ID);

		for(i = 0; i < fifo->count; i++){

			if(temp->rollnum == temp_ID){

				DPRINTF("---------------------------------------------------------\n");
				DPRINTF("[ERROR] ID %u is already taken.\n",temp_ID);
				DPRINTF("---------------------------------------------------------\n\n");
				fscanf(fileptr,"%*[^\n]");
				unique = 0;
				break;
			}
			temp++ ;
		}

		if(unique){

			sendstudent.rollnum = temp_ID;
			fscanf(fileptr, "%s", sendstudent.firstname);
			fscanf(fileptr, "%s", sendstudent.lastname);
			fscanf(fileptr, "%lf",&sendstudent.gpa);

			for(j = 0; j < fifo->length; j++){
				fscanf(fileptr, "%u", &sendstudent.courseId[j]);
			}

			status = fifo_enqueue(fifo, &sendstudent);

			if(status == fifo_no_error){
				DPRINTF("---------------------------------------------------------\n");
				DPRINTF("[INFO] ID %u added successfully.\n",temp_ID);
				DPRINTF("---------------------------------------------------------\n\n");
				countstud++ ; countstud1++ ; add2loop++ ;
			}
			else{
				return system_has_error;
			}
		}
	}
	count(countstud);
	fclose(fileptr);
	return system_no_error;
}

Function_status Find_stud_byId(fifo_student* fifo_p){

	uint32_t rollnum, i = 0;
	Sstudent* temp = fifo_p->tail;

	if(QueueEmptyCheck(fifo_p) == system_has_error)
		return system_has_error;

	DPRINTF("========================================================\n");
	DPRINTF("Enter Student ID Number you want to find:");
	scanf("%d",&rollnum);
	DPRINTF("========================================================\n\n");

	for(i = 0; i < fifo_p->count; i++){

		if(temp->rollnum == rollnum){

			show_stud(temp, i);
			return system_no_error;
		}
		temp++;
	}
	DPRINTF("======================================================\n");
	DPRINTF("Student ID Number Not found !\n");
	DPRINTF("======================================================\n\n");
	return system_has_error;
}

Function_status Find_stud_byFirstName(fifo_student* fifo_p){

	uint32_t i = 0;
	char string[string_size];
	Sstudent* temp = student;

	if(QueueEmptyCheck(fifo_p) == system_has_error)
		return system_has_error;

	DPRINTF("======================================================\n");
	DPRINTF("Enter Student First name to check for Info:");
	gets(string);
	DPRINTF("======================================================\n\n");

	for(i = 0; i < fifo_p->count; i++){

		if(strcmp(temp->firstname, string) == 0){

			show_stud(temp, i);
			return system_no_error; //Found name
		}
		temp++ ;
	}
	DPRINTF("======================================================\n");
	DPRINTF("Student First Name not found !\n");
	DPRINTF("======================================================\n\n");
	return system_no_error;
}

Function_status Reg_studs_bycourseId(fifo_student* fifo_p){

	uint32_t flag = 0;
	uint32_t i, j, courseID;
	Sstudent *temp = fifo_p->tail;

	if(QueueEmptyCheck(fifo_p) == system_has_error)
		return system_has_error;

	DPRINTF("========================================================\n");
	DPRINTF("Enter the Course ID:");
	scanf("%d", &courseID);
	DPRINTF("========================================================\n\n");

	for(i = 0; i < fifo_p->count; i++){

		for(j = 0; j < courses_count; j++){

			if(temp->courseId[j] == courseID){

				DPRINTF("\t\t[DISPLAYING STUDENT INFO]\n");
				DPRINTF("========================================================\n");
				DPRINTF("Student ID Number: %d\n",temp->rollnum);
				DPRINTF("Student Full Name: %s %s\n",temp->firstname,temp->lastname);
				DPRINTF("Student GPA: %.2lf\n",temp->gpa);
				DPRINTF("========================================================\n\n");
				flag = 1;
			}
		}
		temp++;
	}

	if(flag == 0){
		DPRINTF("======================================================\n");
		DPRINTF("Course ID not found !\n");
		DPRINTF("======================================================\n\n");
	}
	return system_no_error;
}

Function_status studs_count(fifo_student* fifo_p){

	if(fifo_p->count == 0)
		return system_no_error;

	else
		return fifo_p->count;
}

Function_status delete_stud(fifo_student* fifo){

	uint32_t  rollnum, i;
	uint32_t deletestud = 1;

	if(QueueEmptyCheck(fifo) == system_has_error)
		return system_has_error;

	DPRINTF("========================================================\n");
	DPRINTF("Enter the ID number you want to delete:");
	scanf("%d",&rollnum);
	DPRINTF("========================================================\n");

	for(i = 0; i < fifo->count; i++){

		if(fifo->tail->rollnum == rollnum){

			status = fifo_dequeue(fifo);

			if (status == fifo_empty){
				DPRINTF("QUEUE is Empty.\n\n");
				return system_has_error;
			}

			else{
				DPRINTF("\n[INFO] The ID Number has been deleted Successfully.\n");
				DPRINTF("---------------------------------------------------------\n");
				DPRINTF("[INFO] You deleted %d students\n",deletestud);
				DPRINTF("---------------------------------------------------------\n\n");

				deletestud++ ;
				--countstud1;
				++Reserved;
				--add2loop;
				return system_no_error; //found it
			}
		}
		fifo->tail++ ;
	}
	DPRINTF("---------------------------------------------------------\n");
	DPRINTF("[ERROR] The ID Number you Entered is not found\n");
	DPRINTF("---------------------------------------------------------\n\n");
	return system_has_error;
}

Function_status Update_stud(fifo_student* fifo_p){

	uint32_t rollnum,CourseID, choice, i,  k, flag = 0;
	uint8_t character;
	Sstudent *temp = fifo_p->tail;

	if(QueueEmptyCheck(fifo_p) == system_has_error)
		return system_has_error;

	DPRINTF("------------------------------------------------------------\n");
	DPRINTF("Enter the Student ID Number you are interested in Updating:");
	scanf("%d",&rollnum);

	for(i = 0; i < fifo_p->count; i++){

		if(temp->rollnum == rollnum){

			repeat:
			DPRINTF("------------------------------------------------------------\n\n");
			DPRINTF("----------What do you want to update ?----------\n");
			DPRINTF("1.First Name\n");
			DPRINTF("2.Last Name\n");
			DPRINTF("3.ID Number\n");
			DPRINTF("4.GPA\n");
			DPRINTF("5.Courses\n");
			scanf("%d", &choice);

			switch(choice){

			// How to do case 1 and 2 using pointers !!??
			case 1:
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("Enter the New first name:");
				gets(temp->firstname);
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("[INFO] First Name of Student has been Updated Successfully.\n");
				DPRINTF("------------------------------------------------------------\n");
				break;

			case 2:
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("Enter the New Last name:");
				gets(temp->lastname);
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("[INFO] Last Name of Student has been Updated Successfully.\n");
				DPRINTF("------------------------------------------------------------\n");
				break;

			case 3:
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("Enter the New ID Number:");
				scanf("%d",&temp->rollnum);
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("[INFO] ID Number of Student has been Updated Successfully.\n");
				DPRINTF("------------------------------------------------------------\n");
				break;

			case 4:
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("Enter the New GPA Score:");
				scanf("%lf",&temp->gpa);
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("[INFO] GPA of Student has been Updated Successfully.\n");
				DPRINTF("------------------------------------------------------------\n");
				break;

			case 5:
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("Which Course ID You want to Update?");
				scanf("%d",&CourseID);
				DPRINTF("------------------------------------------------------------\n");

				for(k = 0; k < courses_count; k++){

					if(temp->courseId[k] == CourseID){
						DPRINTF("------------------------------------------------------------\n");
						DPRINTF("Enter New Course ID you want to Update with the Existing One:");
						scanf("%d",&temp->courseId[k]);
						DPRINTF("------------------------------------------------------------\n");
						DPRINTF("[INFO] Course ID has been Updated Successfully.\n");
						DPRINTF("------------------------------------------------------------\n");
						flag = 1;
					}
				}

				if (flag) {goto flag;}

				else{
					DPRINTF("------------------------------------------------------------\n");
					DPRINTF("[ERROR] Course ID Entered Doesn't Exist.\n");
					DPRINTF("------------------------------------------------------------\n\n");
					goto flag;
				}

			default :
				DPRINTF("------------------------------------------------------------\n");
				DPRINTF("You Entered a Wrong Choice.\n")
				DPRINTF("------------------------------------------------------------\n\n");
				return system_has_error;
			}

			flag:
			DPRINTF("------------------------------------------------------------\n");
			DPRINTF("Do you Want to Update Any other Info y/n ?");
			scanf("%c",&character);

			if(character == 'y' || character == 'Y')
				goto repeat;
			else
				return system_no_error;
		}
		temp++ ; //Move or Point to the next student in QUEUE
	}
	DPRINTF("------------------------------------------------------------\n");
	DPRINTF("\n[ERROR] ID Number Not Existed in Database.\n");
	DPRINTF("------------------------------------------------------------\n\n");
	return system_has_error;
}

void show_stud(Sstudent* temp, uint32_t i){

	uint32_t j;
	DPRINTF("=========================================================\n");
	DPRINTF("\t\t[DISPLAYING STUDENT %d INFO]\n",i+1);
	DPRINTF("=========================================================\n");
	DPRINTF("Student ID Number: %d\n",temp->rollnum);
	DPRINTF("Student Full Name: %s %s\n",temp->firstname,temp->lastname);
	DPRINTF("Student GPA: %.2lf\n",temp->gpa);
	DPRINTF("-----------Student Courses ID-----------\n");

	for(j = 0; j < courses_count; j++){
		DPRINTF("Course ID %d = %d\n",(j+1),(temp->courseId[j]));
	}
	DPRINTF("=========================================================\n\n");
}

void count(uint32_t countstud){

	DPRINTF("\n[INFO] Student Details has been added Successfully.\n");
	DPRINTF("---------------------------------------------------------\n");
	DPRINTF("[INFO] The total number of Students is %d\n",size_limit);
	DPRINTF("[INFO] You added %d students\n",countstud);
	Reserved = size_limit - countstud1;
	DPRINTF("[INFO] You can add %d more students\n",Reserved);
	DPRINTF("---------------------------------------------------------\n");
}

void print_all(fifo_student* fifo_p){

	uint32_t i = 0;
	Sstudent* temp = NULL;
	temp = fifo_p->base;

	if(QueueEmptyCheck(fifo_p) == system_has_error){/*Do Nothing*/}

	else{
		for(i = 0; i < fifo_p->count; i++){
			show_stud(temp, i);
			temp++ ;
		}
	}
}

//--------------------------------FIFO FUNCTIONS-----------------------------------//
fifo_status fifo_init(fifo_student* fifo_p, Sstudent* student, uint32_t length){

	if(fifo_p == NULL)
		return fifo_null;

	fifo_p->head = student;
	fifo_p->base = student;
	fifo_p->tail = student;
	fifo_p->count = 0;
	fifo_p->length = length;

	return fifo_no_error;
}

fifo_status fifo_enqueue(fifo_student* fifo_p, Sstudent* student){

	if(fifo_p->count == fifo_p->length){
		DPRINTF("QUEUE is Full.\n\n");
		return fifo_full;
	}

	else{

		*(fifo_p->head) = *(student);
		fifo_p->count++ ;

		if(fifo_p->head == fifo_p->base + (fifo_p->length * sizeof(Sstudent)))
			fifo_p->head = fifo_p->base;

		else
			fifo_p->head++ ;

		return fifo_no_error ;
	}
}

fifo_status fifo_dequeue(fifo_student* fifo_p){

	uint32_t j;

	if(fifo_p->count == 0){
		DPRINTF("QUEUE is Empty.\n\n");
		return fifo_empty;
	}

	else{

		fifo_p->count-- ;

		for(j = 0; j < fifo_p->count; j++)
		{
			*(fifo_p->tail + j) = *(fifo_p->tail + j + 1) ;
		}

		fifo_p->head-- ;
		fifo_p->tail = fifo_p->base ;

		//		if(fifo_p->tail == fifo_p->base + (fifo_p->length * sizeof(Sstudent))){
		//			fifo_p->tail = fifo_p->base; }
		//
		//		else{
		//}
		return fifo_no_error ;
	}

}




