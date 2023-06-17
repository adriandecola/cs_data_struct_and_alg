#include <stdio.h> //Preprocessor directive includes standard input and output
#include <stdlib.h> //Preprocessor directive includes standard library

// Creating the student struct
typedef struct student{
	int capacity;
	int total;
	int* data;
} STUDENT;

// Function declarations
void printData(STUDENT* myStudent);
STUDENT* initialize(void);
void deallocate(STUDENT** p_myStudent);
void pushData(STUDENT* myStudent, int item);
void resizeData(STUDENT* myStudent);

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]){
	// Initialzing a pointer to a STUDENT variable and initializing the variable
	STUDENT* myStudent = initialize();

	// Populating the array with 100 random numbers between 0 and 100 to test
	int i;
	for (i = 0; i < 100; i++){
		int randItem = rand()%101;		
		pushData(myStudent, randItem);
	}
	// Printing the data
	printData(myStudent);
	// Printing the capacity and total
	printf("Capacity: %d \t Total: %d \n", myStudent->capacity, myStudent->total);

	// Freeing the dynamically allocated memory--by passing in a pointer to
	// the student pointer
	deallocate(&myStudent);

	// Printing my answer to Task 3 Q2
	printf("------------------------- Task 3 Q2 ---------------------------\n");
	printf("When my printData function only took in only a STUDENT variable \n");
	printf("and did not return anything, the function did not work. This \n");
	printf("is because we were using stack memory and therefore a copy of \n");
	printf("the STUDENT variable was made and that was what we modified. \n"); 
	printf("When we exited this function this copy of the STUDENT struct \n");
	printf("was deleted and that's why the function doen't work. To fix \n");
	printf("this we could either return the new STUDENT variable and store \n");
	printf("it into the original STUDENT variable in main or we could \n");
	printf("pass in a pointer to the STUDENT variable to the function and \n");
	printf("modify it that way. Since the former required unneccesary \n");
	printf("copying I think it makes more sense to pass in a pointer to the \n");
	printf("STUDENT variable. \n");	

	// Printing my answer to Task 4 questions
	printf("-------------------------- Task 4 ----------------------------\n");
	printf("The pushData function now works. This makes sense since we \n");
	printf("passed in a pointer to the STUDENT variable. This way we were \n");
	printf("directly modifying the data member variable in the dynamically \n");
	printf("allocated memory, which means the function can actually modify\n");
	printf("the STUDENT variable without the need to return the new, \n");
	printf("modified variable. \n");

	return 0;
}
///////////////////////////////////////////////////////////////////////////////

// Function Implementations
STUDENT* initialize(void){
	/*
	This function does not  receive any arguments but does return a pointer 
	to a STUDENT. The function is used to do the memory allocation for 
	a struct variable and to  initialize all member variables including 
	allocating memory for the array. The capacity is initialized to 7.
	*/
	
	// Creating a pointer to a STUDENT variable
	STUDENT* myStudent = (STUDENT*)malloc(sizeof(STUDENT));	
	
	// Initializing it's data members
	myStudent->capacity = 7;
	myStudent->total = 0;
	myStudent->data = (int*)calloc(myStudent->capacity, sizeof(int));

	return myStudent;
}



void deallocate(STUDENT** p_myStudent){
	/*
	Freeing the dynamically allocated memory and making sure the STUDENT
	pointer points to NULL so that we don't try and access inaccesible 
	memory. 
	*/

	STUDENT* myStudent = *p_myStudent;
	free(myStudent->data);
	free(myStudent);
	myStudent = NULL;
	
	return;
}


void printData(STUDENT* myStudent){
	/*
	This function takes in a pointer to a STUDENT struct varibale and 
	prints the contents in its data memeber variable, sepereated by spaces.
	*/

	int i;
	for(i = 0; i < myStudent->total; i++){
		printf("%3d ", myStudent->data[i]);
	}
	printf("\n");
	
	return;
}


void pushData(STUDENT* myStudent, int item){
	/*
	This function takes in a pointer to a STUDENT variable and an 
	integer item. It pushes the integer item to the end ot  
	*/	
	
	// Resizing array if there is not enough space
	if (myStudent->total == myStudent->capacity){
		resizeData(myStudent);
	}
	
	// Pushing the item
	myStudent->data[myStudent->total] = item;

	// Updating the total
	myStudent->total += 1;
	
	return;
}

void resizeData(STUDENT* myStudent){
	/*
	This funciton takes in a pointer to a STUDENT variable and resizes
	its data array to twice the original size, copying in the old data
	and updateing the capacity. 
	*/
	
	// Getting new memmory of the correct size
	int* temp = (int* )calloc(myStudent->capacity * 2, sizeof(int));
	
	// Copying the old data
	int i;
	for (i = 0; i < myStudent->capacity; i++){
		temp[i] = myStudent->data[i];
	}

	//Deallocating the old data
	free(myStudent->data);
	
	// The data(pointer) now points to the new data
	myStudent->data = temp; 
	
	// Updating the capacity
	myStudent->capacity *= 2;

	return;
}
