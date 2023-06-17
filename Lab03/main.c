#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int** array_2D; //Declaring a two dimansional array
			//we will make it an array of pointer to integer pointers
			//that is dynamically defined in memory
	//An array of pointers that will point to integer pointers/
	//the start of each row array
	array_2D = (int**)malloc(20*sizeof(int*));
	
	int r; //the number of rows
	int c; //the number of columns	

	for (r= 0; r<20; r++)
	{
		array_2D[r] = (int*)malloc(30*sizeof(int));
	}

	//Filling in the data-- we need a nested for loop
	for (r = 0; r<20; r++)
	{
		for (c = 0; c<30; c++)
		{
			array_2D[r][c] = r + c;
		}
	}
	
	//Printing the array
	for (r = 0; r<20; r++)
	{
		for (c = 0; c<30; c++)
		{
			printf("%2d ", array_2D[r][c]);
		} 
		printf("\n");
	}
	printf("Hello world! I have created a dynamic 2D array of  integers!\n");

	//Freeing the arrays; cleans the space
	for (r=0; r<20; r++)
	{
		free(array_2D[r]);
	}
	free(array_2D);

	return 0;
}
