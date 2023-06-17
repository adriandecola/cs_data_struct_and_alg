/*
In this section, considering Prof Mwaura's class - 
He needs to store grade data belonging to his student. He currently has 10 student. 

Ref:

https://cplusplus.com/reference/cstdlib/

a) What is the difference between static and dynamic arrays ? 
static - size of array is fixed while dynamic - array can be resized. 

b) Where is the memory for static array and where is that for dynamic arrays?
-static array memory  is in Stack memory and dynamic array on Heap. 

c) Using the C language shows how both these arrays can be formulated for Prof Mwaura's class
 
d) What do we notice about the array specifically; if we are designing an array what items/parameters would we need?

*/
#include<stdio.h>  //Include preprocessor directive
#include<stdlib.h>


//write a function that returns whether array is full or not
typedef enum status{FALSE, TRUE} STATUS;
typedef enum outcome{FAILURE, SUCCESS} OUTCOME;

typedef struct student STUDENT;

struct student{
	
	int Capacity; //how much data we can keep
	int total; //no of items at a single point in time inside the array
	int * studentData; //will hold adress of the array.

};

//this function should allocate all memory associate with the STUDENT struccture
//should initialize all variables and return the address of the struct
//Make sure to catch any errors associated with malloc/calloc etc
STUDENT * allocate(void);

STATUS isFull(STUDENT * sGrades);

//function declaration
void printGrades(STUDENT * pGrades);

//function to push (insert) items to the array
OUTCOME  push(STUDENT ** pstudentGrades, int item);

void deallocate(STUDENT ** pStudentGrades);


//main is just but a driver function

int main (void){

	STUDENT * myGrades = allocate();

	int item = 0;
	
	for (int i = 0; i<100; i++){
		item = rand()%100;
		push(&myGrades, item);
	}
	
	printGrades(myGrades);

	deallocate(&myGrades);
	

return 0;
}

STUDENT * allocate(void){

	//consider grades as integers - not always true- for static array
	STUDENT * studentGrades = (STUDENT *)malloc(sizeof(STUDENT));
	if (studentGrades == NULL){
		printf("No memory \n");
		exit(-1);
	}
	studentGrades->Capacity = 7;
	studentGrades->total=0;
	//allocate memory for array
	studentGrades->studentData = (int *) calloc (sizeof(int), studentGrades->Capacity);
	//TEST if calloc did allocate memory
	if (studentGrades->studentData == NULL){
		return 0;
	}
	
	return studentGrades;

}
//function definition
void printGrades(STUDENT * pStudentGrades){
	STUDENT * sGrades = pStudentGrades;//dereferencing 
	int i = 0;
	while (i<sGrades->total){
		printf("%d \n",sGrades->studentData[i]);
		i++;
	}

return;
}

STATUS isFull(STUDENT * pStudent) {

    if (pStudent->total<pStudent->Capacity){
        return FALSE; 
      }

   return TRUE;  
}

//function that pushes or inserts an item in the array
OUTCOME  push(STUDENT ** pStudentGrades,int item){
		
	STUDENT * sGrades = *pStudentGrades;//dereferencing 

	int * temp = NULL;
	
	if (isFull(sGrades)){
		//array is full, how do we increase array size?
		temp = (int *) calloc (sizeof(int), sGrades->Capacity * 2);
		//check whether increase size worked.
		if(temp == NULL){
			return FAILURE;
		}
		//copy items from old array into array
		for (int i = 0; i <sGrades->Capacity; i++){
			temp[i] = sGrades->studentData[i];
		}
		//deallocate memory from old array
		free(sGrades->studentData);
		
		//point old pointer to new pointer
		sGrades->studentData = temp;
		
		//double capacity
		sGrades->Capacity = sGrades->Capacity * 2;
	}
	
	sGrades->studentData[sGrades->total] = item;
	sGrades->total++;


 return SUCCESS;
}

void deallocate(STUDENT ** pStudentGrades){
	
	STUDENT * sGrades = *pStudentGrades;//dereferencing 
	
	if (*pStudentGrades != NULL){
		free(sGrades->studentData);
		free(sGrades);
	}
	*pStudentGrades = NULL;
	
	return;
}



