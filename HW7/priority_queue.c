#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int priority;
	int data;
}
dataNode; 


typedef struct qnode{
	int size;
	int capacity;
	dataNode* data;

}Queue;

//////////// USEFUL HIDDEN FUNCITONS ////////////  
void swap(dataNode *x, dataNode *y);
int getParentIndex(int index);
Status queue_resize(Queue* q);

/*
 * Precondition: Creates an empty priority queue that can store integer data items
 *       with different integer priority. Higher integer values indicate higher priority in the queue. For example, consider the
 *       priority and the data value to be key-value pairs where the priority is the key and the data is the value. The queue could hold 21,10 and 35, 5 so that the 
 *       first item to be removed from the queue would be the data value 5 because
 *       it has higher priority (35) than the data value 10 which only has (21).
 * Postcondition: Returns the handle to an empty priority queue with a capacity of 10.
 */
PRIORITY_QUEUE priority_queue_init_default(void){
	// Allocating memory
	Queue* q = (Queue*) malloc(sizeof(Queue));
	if (q == NULL){
		printf("Memory could not be allocated \n");
		exit(-1);
	}

	q->size = 0;
	q->capacity = 10; // This can be changed 

	q->data = (dataNode*) malloc(sizeof(dataNode)*  q->capacity);
	if (q->data== NULL){
		printf("Memory could not be allocated \n");
		exit(-1);
	}

	return (PRIORITY_QUEUE) q;
}


/*
 * Precondition: hQueue is a handle to a valid priority queue opaque object
 *       Higher priority_level values indicate higher priority in the queue.
 *       data_item is simply a value we are storing in the queue
 *
 * Postcondition: returns SUCCESS if the item was successfully added to the queue
 *       and FAILURE otherwise.
 */
Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item){
	Queue* q = (Queue*) hQueue;
	if (q->size == q->capacity){
		Status status = queue_resize(q);
		if (status == FAILURE){
			return FAILURE;
		}
	}

	// Insert the data at end of the array
    int i = q->size;
    q->data[i].priority = priority_level;
    q->data[i].data = data_item;
    q->size+=1;

	// Fixing the heap property
    while (i != 0 && q->data[getParentIndex(i)].priority < q->data[i].priority)
    {
       swap(&q->data[i], &q->data[getParentIndex(i)]);
       i = getParentIndex(i);
    }
	return SUCCESS;
}
	



/*
 * Precondition: hQueue is a handle to a valid priority queue opaque object. 
 * Postcondition: returns SUCCESS if the highest priority item was removed from the queue 
 *        and FAILURE if the queue was empty.
 */
Status priority_queue_service(PRIORITY_QUEUE hQueue){
	Queue* q = (Queue*) hQueue;
	
	// making sure there is items in the queue
	if (q->size ==0){
		printf("The priority queue is empty. \n");
		return FAILURE;
	}

	// Swapping the first and last item, this still works if there is only one item
	swap(&q->data[0], &q->data[getParentIndex(q->size - 1)]);

	// Updating the size
	q->size += -1;

	return SUCCESS;
}

/*
 * Precondition: hQueue is a handle to a valid priority queue opaque object. 
 * Postcondition: returns a copy of the data value for the 
 *        highest priority item in the queue. Sets status to SUCCESS if there is 
 *        at least one item in the queue and FAILURE otherwise. If status is 
 *        passed in as NULL then the status value is ignored for this run of the 
 *        function. 
 */

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status){
	Queue* q = (Queue*) hQueue;
	
	// checking if there is at least one item in the queue
	if (q->size == 0){
		if (status != NULL){
			*status = FAILURE;
		}
		return -999999;
	}
	if (status != NULL){
		*status = SUCCESS;
	}

	int front_data = q->data[q->size - 1].data;

	return front_data;
}

/*
 * Precondition: hQueue is a handle to a valid priority queue opaque object. 
 * Postcondition: returns TRUE if the priority_queue is empty and FALSE otherwise. 
 */

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue){
	Queue* q = (Queue*) hQueue;

	if (q->size == 0){
		return TRUE;
	}
	return FALSE;
}

/*
 * Precondition: phQueue is a pointer to the handle of a valid priority queue opaque object. 
 * Postcondition: The opaque object will be free'd from memory and the handle pointed to 
 *        by phQueue will be set to NULL. 
 */

void priority_queue_destroy(PRIORITY_QUEUE* phQueue){
	Queue** ppQ = (Queue**) phQueue;

	free((*ppQ)->data);
	free(*ppQ);
	*ppQ = NULL;
}













//////////// USEFUL HIDDEN FUNCITONS ////////////


Status queue_resize(Queue* q){
	q->capacity *= 2; // We double the size of underlying data array
	dataNode* tmp = malloc(sizeof(dataNode)*  q->capacity);
	if (tmp == NULL){
		return FAILURE;
	}
	
	// Copying the data
	int i;
	for (i = 0; i < q->size; i++){
		tmp[i].priority = q->data[i].priority;
        tmp[i].data = q->data[i].data;
	}
	free(q->data);
	q->data = tmp;

	return SUCCESS;
}


//Given an index, return index of its parent
int getParentIndex(int index){
    return (index -1)/2; // |2|binary heap
}


//Function to help swap items.
void swap(dataNode *x, dataNode *y)
{
    dataNode temp = *x;
    *x = *y;
    *y = temp;
}
