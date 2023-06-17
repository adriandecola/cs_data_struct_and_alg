#include "queue.h"

/*
If we are implementing a dynamic array (or any array) ; 
what in terms of variables do we need
1) Pointer - which shall keep the address of the first of the array
2) Variable - to inform us the CAPACITY of the array
3) An Iterating variable - total no_items in the array at a certain time
*/


int main(void){

QUEUE hQueue= NULL; //opaque handle -- a pointer to an opaque object that conceals the known data type.
hQueue = queue_init_default();

queue_enqueue(hQueue, 5);
queue_enqueue(hQueue, 8);
queue_enqueue(hQueue, 4);

printFrontItem(hQueue);
printTailItem(hQueue);

queue_enqueue(hQueue, 7);

printFrontItem(hQueue);
printTailItem(hQueue);

queue_dequeue (hQueue);
queue_dequeue (hQueue);

queue_enqueue(hQueue, 20);
printFrontItem(hQueue);
printTailItem(hQueue);
queue_enqueue(hQueue, 40);
queue_enqueue(hQueue, 50);
queue_enqueue(hQueue, 6);
queue_enqueue(hQueue, 14);

printItems(&hQueue);

printf("****************\n");
queue_dequeue (hQueue);

printFrontItem(hQueue);
printTailItem(hQueue);

queue_destroy(&hQueue);


return 0;
}



