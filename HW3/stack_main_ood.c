/*
 Jonathan Mwaura
 
 This is the main driver to test a stack implemented using a linkedlist.
 the driver uses a header file which contains the stack api
 
https://cplusplus.com/reference/cstdlib/

*/
#include "stack_ood.h"


//main is just but a driver function

int main (void){

	STACK pStack= allocate();

	int item = 0;
	
	for (int i = 0; i<10; i++){
		item = rand()%100;
		//printf("item: %i %i \n", i, item); //(uncomment to see how items were added)
		push(&pStack, item);
	}
	
	printData(pStack);
	pop(pStack);
	int top = peek(pStack);
	printf("Top is %d: \n", top);
	printData(pStack);
	
	deallocate(&pStack);
	

return 0;
}

