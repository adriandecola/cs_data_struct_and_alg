#include "studentvector.h"


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



