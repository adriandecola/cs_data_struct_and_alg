/*
Author: Adrian deCola
Date: March 18, 2023
Purpose: This program is for Quesiton 4 of the synthesis, which should do the following:

Write a complete program to ask the user for a positive integer n, allocate enough space on the heap for 
an array of integers that has n elements and then fill that array with random values using the function 
rand( ).  Pass the array to a function called find_max that will return the index of the largest element 
of your array.  Your main program should print the index of the largest element of the array on the screen. 
Remember to free up memory before terminating the program.  You can use additional space on the next page 
for your solution.  The function rand( ) is a library function that returns a value between 0 and RAND_MAX 
and can be called to get random values for each element of your dynamic array.

*/

#include <stdio.h>
#include <stdlib.h>

//Function declarations
int find_max(int* arr, int size);


int main(void) {
	// Asking the user for a positive integer n and storing it
	int n;	
	printf("Please give a positive integer: ");
	scanf("%d", &n);

	// Allocating the space for an array of n integers
	int* arr = (int*) malloc(n * sizeof(int));
	
	//Filling the array
	int i;
	for (i = 0; i < n; i++){
		arr[i] = rand();
	}

	/*
	//Printing the array to make sure the find_max function works correctly
	printf("Printing the array: \n");
	for (i = 0; i < n; i++){
		printf("%d \n", arr[i]);
	}
	*/

	//Calling the find_max function storing and printing the index
	int maxIndex = find_max(arr, n);
	printf("The index of the largest element is %d.\n", maxIndex); 

	//Freeing the array
	free(arr);

	return 0;
}



//Function implementation
int find_max(int* arr, int size){
	/*
	This function returns the first index of the largest element in an array of positive integers.
	If the array is empty it return -1.
	*/
	int i;
	int maxIndex = -1;
	int maxValue = -1;
	for (i = 0; i < size; i++){
		if (arr[i] > maxValue){
			maxIndex = i;
			maxValue = arr[i];
		}
	}
	return maxIndex;
}

