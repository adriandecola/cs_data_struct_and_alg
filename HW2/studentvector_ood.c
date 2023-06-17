#include "studentvector_ood.h"
#include "studentvector_ood.h" //testing the header file doesn't copy twice

//known type
typedef struct student STUDENT;//forward declaration

struct student{
	
	int Capacity; //how much data we can keep
	int total; //no of items at a single point in time inside the array
	int * studentData; //will hold adress of the array.

};

//returns an opaque object
MY_STUDENT allocate(void){

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
	
	//typecast to opaque	
	return (MY_STUDENT) studentGrades;

}

//returns an opaque object
MY_STUDENT deepCopy(MY_STUDENT* currentStudent){
	//typecasing the opaque object to a STUDENT one
	STUDENT* currStudent = (STUDENT*)*currentStudent;	

	//allocating memory
	STUDENT* newStudent = (STUDENT*)malloc(sizeof(STUDENT));
	if (newStudent == NULL){
		printf("No memory \n");
		exit(-1);
	}
	
	//Copying the capacity and total number of elements
	newStudent->Capacity = currStudent->Capacity;
	newStudent->total = currStudent->total;
	
	//Allocating the memory for new student objects data
	newStudent->studentData = (int*)calloc(sizeof(int), newStudent->Capacity);
	if (newStudent->studentData == NULL){
		printf("Not enough memory \n");
		exit(-1);
	}
	
	//Copying the old data(integers)
	int i;
	for (i = 0; i < newStudent->total; i++){
		newStudent->studentData[i] = currStudent->studentData[i];
	}

	//typecasting to opaque
	return (MY_STUDENT) newStudent;
}


//function definition
void printGrades(MY_STUDENT pStudentGrades){
	STUDENT * sGrades = (STUDENT *) pStudentGrades;//dereferencing 
	int i = 0;
	while (i<sGrades->total){
		printf("%d \n",sGrades->studentData[i]);
		i++;
	}

return;
}

STATUS isFull(MY_STUDENT pStudentGrades) {

	STUDENT * pStudent = (STUDENT *) pStudentGrades;
	
    if (pStudent->total<pStudent->Capacity){
        return FALSE; 
      }

   return TRUE;  
}

//function that pushes or inserts an item in the array
OUTCOME  push(MY_STUDENT * pStudentGrades,int item){
		
	STUDENT * sGrades = (STUDENT *) *pStudentGrades;//dereferencing 

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


void deallocate(MY_STUDENT * pStudentGrades){
	
	STUDENT * sGrades = (STUDENT *) *pStudentGrades;//dereferencing 
	
	if (*pStudentGrades != NULL){
		free(sGrades->studentData);
		free(sGrades);
	}
	*pStudentGrades = NULL;
	
	return;
}



