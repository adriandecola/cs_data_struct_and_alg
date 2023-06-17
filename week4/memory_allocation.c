#include<stdio.h>
#include<stdlib.h>

//declare macro
#define MAX_ARRAY_SIZE 20

void sortwithBubble(int * myArray);


//Dynamic memory allocation - allocate memory from the heap part of memory when we need it.
//malloc or calloc - allocates memory
//re-alloc - extends memory
//free - de allocates the memory
//malloc, calloc, and realloc returns a void pointer (void *)




int main (void){
	int max = 10;


	printf("%d %f \n", max, (float) max); //typecasting - temporary change type


	int * grades = NULL;

	//malloc ONLY takes in one argument
	//grades = (int *) malloc ( MAX_ARRAY_SIZE * sizeof(int));

	//calloc takes in 2 arguments
	grades = (int *) calloc (sizeof(int), MAX_ARRAY_SIZE);

	//[MAX_ARRAY_SIZE];

	for (int i =0 ; i< MAX_ARRAY_SIZE; i++){
		*(grades + i) = rand()%100;
	}

	sortwithBubble(grades);

	for (int i =0 ; i< MAX_ARRAY_SIZE; i++){
	  printf("%d ", *(grades + i));

	}
	printf("\n");

	free(grades);
	grades = NULL;


	return 0;


}

void sortwithBubble(int * myArray){
	//sorting algorithm goes here: bubble sort
	int temp = 0;

	for (int i = 0; i< MAX_ARRAY_SIZE; i++){
		for (int j = 0; j< MAX_ARRAY_SIZE -i; j++)
			if (myArray[j] <myArray[j+1]){
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
		}
}
