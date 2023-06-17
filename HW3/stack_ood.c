#include "stack_ood.h"

//define a NODE type
typedef struct node NODE;

struct node{
	int data;
	NODE* next;
};


//Known type - the stack, keeps only the top node
typedef struct stack MY_STACK;//forward declaration

struct stack{
	NODE *top;
};


//returns an opaque object after creating all required memory for the stack
STACK allocate(void){

	//consider grades as integers - not always true- for static array
	MY_STACK * pStack = (MY_STACK *)malloc(sizeof(MY_STACK));//first bookend
	if (pStack == NULL){
		printf("No memory \n");
		exit(-1);
	}
	//We do not have any nodes yet, so top is NULL
	pStack->top=NULL;
		
	//typecast to opaque	
	return (STACK) pStack;

}


//prints all data items in our stack
void printData(STACK pStack){
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	NODE * temp = ppStack->top;
	
	while (temp != NULL){
		printf("%d \n",temp->data);
		temp = temp->next;
	}

return;
}

STATUS isFull(STACK pStack) {
	 //this is a stack implemented as linked list, it can never be full!!!
	 return FALSE;  
}

/*
This function should imitate the insertHead function, why is that? 
The function should receive address of the stack and some data value. 
The function should allocate memory for a node which becomes part of the stack
Some starter code is provide to provide a way for a new NODE to be created. 
You need to show how this is inserted into the stack.
*/
OUTCOME  push(STACK * pStack,int item){
		
	MY_STACK * ppStack = (MY_STACK *) *pStack;//dereferencing + typecasting
	
	NODE* newNode = (NODE*) malloc (sizeof (NODE));
	if(!newNode){
		return FAILURE;
	}
	newNode->data = item;
	//makes the new node point to the node at the top of the stack
	newNode->next = ppStack->top;
	//makes the top of the stack point to the new node
	ppStack->top = newNode;
	
 return SUCCESS;
}

/*
This function should remove what is on top of the stack. 
Remember we are now dealing with nodes, so what is on top of the stack is actually a node. 
*/
OUTCOME  pop(STACK* pStack){
	
	MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 
	NODE * temp = ppStack->top;
	
	if(ppStack->top == NULL){
		return FAILURE;
	}
	//assigning the top of the stack to be the node right after the current top
	ppStack->top = temp->next;
	//deleting the old node
	free(temp);
	
	return SUCCESS;

}


//This function returns the data held by the node which is ontop of the stack. 
int peek(STACK pStack){
	
		MY_STACK * ppStack = (MY_STACK *) pStack;//typecasting 

	return ppStack->top->data;

}

/*
How would we go about deallocating the memory? 
Notice that for this data structure, everything is held by multiple nodes and therefore all created memory must be freed
also the stack memory allocated in the first function must be deallocated too.
*/

void deallocate(STACK * pStack){
	
	MY_STACK * ppStack = (MY_STACK *) *pStack;//dereferencing + typecasting
	NODE * temp = ppStack->top;

	//recursively deleting the top node until the stack only has one node left
	if (ppStack->top->next != NULL){
		ppStack->top = temp->next;
		free(temp);
		deallocate( (STACK*) &ppStack );
	}
	
	else{
		//freeing the last node
		free(ppStack->top);

		//freeing the empty stack	
		free(ppStack);
	
		//making the STACK pointer null so we don't get a segmetation fault
		*pStack = NULL;
	}
	
	return;
}



