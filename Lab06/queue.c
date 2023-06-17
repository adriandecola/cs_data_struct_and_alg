//the .c file is the implementation file

#include "queue.h"

//KNOWN data type

struct queue{
	int frontIndex; //this is index where we shall remove items
	int backIndex; //this is index where we shall add items
	int totalItems; // total items in the queue
	int capacity; //how many items our array/queue can hold
	int * data; //THE ARRAY where data is being kept.

};

typedef struct queue MY_QUEUE;

//hidden func definiton
Status resize(MY_QUEUE* pQueue);


//functions
//This is the initializer for all memory and variables
QUEUE queue_init_default(void){
	MY_QUEUE* pQueue = NULL; //pointer to an instance of a VECTOR

	pQueue = (MY_QUEUE*) malloc(sizeof(MY_QUEUE));

	if(pQueue == NULL){
		printf("No memory");
		exit(1);
	}
	pQueue->frontIndex = 0;
	pQueue->backIndex = 0;
	
	pQueue->capacity = 7;
	pQueue->totalItems = 0;

	pQueue->data = (int*) malloc(pQueue->capacity * sizeof(int));

	if(pQueue->data == NULL){
		printf("No memory for array");
		free(pQueue);
		pQueue = NULL;
	}
	
	return (QUEUE) pQueue;
}

//The hidden resize queue function
Status resize(MY_QUEUE* pQueue){
	//allocating for a new array twice the size of the original
	pQueue->capacity *= 2;
	int* temp_data = (int*) malloc(pQueue->capacity * sizeof(int));

	if (temp_data == NULL){
		printf("Not enough memory to hold more data");
		return Failure;
	}

	//Copying the old data into the new array but adding it
	//starting at the front
	int copyIndex = pQueue->frontIndex;
	for (int i = 0; i < pQueue->totalItems; i++){
		temp_data[i] = pQueue->data[copyIndex];
			
		//checking if we need to start copying from the front
		if (copyIndex + 1 == pQueue->capacity){
			copyIndex = 0;
		}
		else{
			copyIndex++;
		}
	}

	//Reassigning the new copied data, fixing our indices, 
	//and freeing the old data
	free(pQueue->data);
	pQueue->data = temp_data;

	pQueue->frontIndex = 0;
	pQueue->backIndex = pQueue->totalItems;

	return Success;
}





Status queue_enqueue (QUEUE hQueue, int item)///add items at the back
{

	MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type 

	//check whether it is full 
	if(pQueue->frontIndex == pQueue->backIndex){
		//making sure the resize worke
		Status status = resize(pQueue);
	
		if (status == Failure){
			return Failure;
		}	
	}
	
	//adding the item
	pQueue->data[pQueue->backIndex] = item; 
	
	//Checking if we need to start adding to the front of the array
	if (pQueue->backIndex + 1 == pQueue->capacity){
		 pQueue->backIndex = 0;
	}
	else{
		pQueue->backIndex++; 
	}	
	
	pQueue->totalItems++;
	
	return Success;
}

void printFrontItem(QUEUE hQueue){
 
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
  	//You may need to modify this to ensure it works with an extended array

 	if (pQueue->totalItems != 0){
		printf("Front is: %d \n", pQueue->data[pQueue->frontIndex]);
	}
	return;
}

void printTailItem(QUEUE hQueue){
 
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
 	//You may need to modify this to ensure it works with an extended array
 	if (pQueue->totalItems != 0){
		//if array is extended always works since our capacity will
		//always be >1
		if (pQueue->backIndex == 0){
			//in this case the tial is at the back of the array
			printf("Tail is: %d \n", pQueue->data[pQueue->capacity - 1]);
		}
		else{
		printf("Tail is: %d \n", pQueue->data[pQueue->backIndex-1]);
		}
	}
	return;
}

int queue_getTotalItems(QUEUE hQueue){
	 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
	 
	 return pQueue->totalItems;


}

Status queue_dequeue(QUEUE hQueue){
	//removes from the front
	MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type

	if (pQueue->totalItems != 0){
		//checking if the front of the list now needs to wrap around
		if (pQueue->frontIndex + 1 == pQueue->capacity){
			pQueue->frontIndex = 0;
		}
		else{
			pQueue->frontIndex++;
		}

		pQueue->totalItems--;
		return Success;
	}

	return Failure;
}


void printItems(QUEUE* phQueue){
	MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;

	printf("Front->"); //helps visualize	

	int printIndex = pQueue->frontIndex;	
	int i = 0;
	while (i < pQueue->totalItems){
		printf(" %d ", pQueue->data[printIndex]);
		//checking if we need ot wrap around
		if (printIndex + 1 == pQueue->capacity){
			printIndex = 0;
		}
		else{
			printIndex++;	
		}	
		i++;
	}
	
	printf("<-Back \n");
	return;
}


void queue_destroy(QUEUE* phQueue){

 MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;
 
 if(pQueue!=NULL){
 
 	free (pQueue->data);
 	free(pQueue);
 }
 *phQueue = NULL; 


}

