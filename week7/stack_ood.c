#include "stack_ood.h"

//known type
typedef struct stack MY_STACK;//forward declaration

struct stack{
	
	int Capacity; //how much data we can keep
	int top; //no of items at a single point in time inside the array or index to access top of the stack
	int * data; //will hold adress of the array.

};

//returns an opaque object
STACK allocate(void){

	//consider grades as integers - not always true- for static array
	MY_STACK * pStack = (MY_STACK *)malloc(sizeof(MY_STACK));
	if (pStack == NULL){
		printf("No memory \n");
		exit(-1);
	}
	pStack->Capacity = 7;
	pStack->top=0;
	//allocate memory for array
	pStack->data = (int *) calloc (sizeof(int), pStack->Capacity);
	//TEST if calloc did allocate memory
	if (pStack->data == NULL){
		return 0;
	}
	
	//typecast to opaque	
	return (STACK) pStack;

}


//function definition
void printData(STACK pStack){
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	int i = 0;
	while (i<ppStack->top){
		printf("%d \n",ppStack->data[i]);
		i++;
	}

return;
}

STATUS isFull(STACK pStack) {

	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	
    if (ppStack->top<ppStack->Capacity){
        return FALSE; 
      }

   return TRUE;  
}

//function that pushes or inserts an item in the array
OUTCOME  push(STACK * pStack,int item){
		
	MY_STACK * ppStack = (MY_STACK *) *pStack;//dereferencing + typecasting

	int * temp = NULL;
	
	if (isFull(pStack)){
		//array is full, how do we increase array size?
		temp = (int *) calloc (sizeof(int), ppStack->Capacity * 2);
		//check whether increase size worked.
		if(temp == NULL){
			return FAILURE;
		}
		//copy items from old array into array
		for (int i = 0; i <ppStack->Capacity; i++){
			temp[i] = ppStack->data[i];
		}
		//deallocate memory from old array
		free(ppStack->data);
		
		//point old pointer to new pointer
		ppStack->data = temp;
		
		//double capacity
		ppStack->Capacity = ppStack->Capacity * 2;
	}
	
	ppStack->data[ppStack->top] = item;
    ppStack->top++;


 return SUCCESS;
}

//removes what is on top of the stack
OUTCOME  pop(STACK* pStack){
	
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 

	if(ppStack->top == 0){
	
		return FAILURE;
	}
	ppStack->top--;
	
	return SUCCESS;

}


//return what is ontop of the stack
int peek(STACK pStack){
	
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	
	if(ppStack->top == 0){
	
		return -111111111; //array is empty
	}
	return ppStack->data[ppStack->top-1];

}


void deallocate(STACK * pStack){
	
    MY_STACK * ppStack = (MY_STACK *) *pStack;//dereferencing + typecasting
    	
	if (*pStack != NULL){
		free(ppStack->data);
		free(ppStack);
	}
	*pStack = NULL;
	
	return;
}



