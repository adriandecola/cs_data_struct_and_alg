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


STATUS isFull(int i);

//function declaration
void printGrades(int * sGrades);

//function to push (insert) items to the array
OUTCOME  push(int * sGrades, int index, int item);

int Capacity = 10;

int main (void){

	//consider grades as integers - not always true- for static array
	int * studentGrades = (int *) calloc (sizeof(int), Capacity);
	//TEST if calloc did allocate memory
	if (studentGrades == NULL){
		return 0;
	}

	int item = 0;

	for (int i = 0; i<20; i++){
		item = rand()%100;
		push(studentGrades, i, item);
	}

	printGrades(studentGrades);

	free(studentGrades);
	studentGrades = NULL;


return 0;
}

//function definition
void printGrades(int * sGrades){
	int i = 0;
	while (isFull(i) == 0){
		printf("%d %lu \n", *(sGrades + i), (sGrades + i));
		i++;
	}

return;
}

STATUS isFull(int i) {
    if (i<Capacity){
        return FALSE;
      }

   return TRUE;
}

//function that pushes or inserts an item in the array
OUTCOME  push(int * sGrades, int index, int item){

	int * temp = NULL;

	if (isFull(index)){
		printf("Array is full, we are working on it \n");
		//array is full, how do we increase array size?
		temp = (int *) calloc (sizeof(int), Capacity * 2);
		//check whether increase size worked.
		if(temp == NULL){
			return FAILURE;
		}
		//copy items from old array into array
		for (int i = 0; i <index; i++){
			temp[i] = sGrades[i];
		}
		//deallocate memory from old array
		free(sGrades);

		//point old pointer to new pointer
		sGrades = temp;

		//double capacity
		Capacity = Capacity * 2;
	}

	sGrades[index] = item;


 return SUCCESS;
}
