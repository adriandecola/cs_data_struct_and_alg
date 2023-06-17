#include<stdio.h>
#include<stdlib.h>

//function - take an array and return largest item
int returnMax(int class[], int size);

int main(int argc, char * argv[]){

	int class[10];
	for (int i=0; i<10; i++){
		class[i] = rand()%100;
		//printf("%d ", class[i]);
	}


printf("Max item is: %d \n", returnMax(class, 10));

return 0;

}
//Complete function that will return the max item
int returnMax(int class[], int size){

	int max;
	max = class[0];

	for (int i = 1; i<size; i++){
		if (class[i] > max){
			max = class[i];
		}
	}

	return max;
}
