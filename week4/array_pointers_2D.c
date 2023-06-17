#include<stdio.h>
#include<stdlib.h>

//function - take an array and return largest item
int returnMax(int * class, int r, int c);

int main(int argc, char * * argv){

	int class[2][2];
	//int ** pClass = class;

	for (int i=0; i<2; i++){
		for (int j = 0; j<2; j++){
		//*(pClass + i) = rand()%100;
		 class[i][j] = rand()%100;
		 printf("%2d \t %p \t", class[i][j], &(class[i][j]));
		 }
		 printf("\n");

	}
	printf("Address of first element is: %p \n", class);
	printf("Address of of Array is : %p \n", &class);

	printf("Max item is: %d \n", returnMax(class, 2, 2));

return 0;

}
//Complete function that will return the max item

int returnMax(int * class, int row, int col){
//Whenever we pass an array, we are passing by reference - i.e. we are passing address of first element only.
	printf("Address of passed element is: %p \n", class);
	int max = *((class +0)+0);


	for (int i = 1; i<row; i++){
		for (int j = 1; j<col; j++){
			if (*(class + i+j)>max)
			  max = *(class + i+j);
			}
	}

	return max;

}
