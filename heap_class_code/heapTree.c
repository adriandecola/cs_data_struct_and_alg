#include<stdio.h>
#include<stdlib.h>

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

void heapify(Queue* myQueue);
void heapDown(dataNode* data, int start, int end);
void insertData(Queue* myQueue, int priority, int data);
int  getParentIndex(int index);
void swap(dataNode *x, dataNode *y);

int main(){
    int seed =time (NULL);
    srand(seed);

    Queue* myQueue;
    myQueue->size=0;
    myQueue->capacity=10;
    myQueue->data = (dataNode*)malloc(sizeof(dataNode)*  myQueue->capacity);

    for (int i=0; i<myQueue->capacity;i++){
        //insertData(myQueue, rand()%50, rand()%100);
        myQueue->data[i].priority=rand()%50;
        myQueue->data[i].data=rand()%100;
        myQueue->size+=1;
       
    }


    for (int i=0; i<myQueue->size;i++){
        printf("%d %d \n", myQueue->data[i].priority, myQueue->data[i].data );
    }
  

   heapify(myQueue);
	
	return 0;
}

void insertData(Queue* myQueue, int priority, int data)
{
    if (myQueue->size == myQueue->capacity)
    {
        //Note in the spirit of dynamic allocation, we could increase memory.
        printf("Failed\n");
        return;
    }
 
    // Insert the data at end of the array component,
    int i = myQueue->size - 1;
    myQueue->data[i].priority = priority;
    myQueue->data[i].data = data;
    myQueue->size+=1;

    // Fix the heap property if it is violated
    while (i != 0 && myQueue->data[getParentIndex(i)].priority < myQueue->data[i].priority)
    {
       swap(&myQueue->data[i], &myQueue->data[getParentIndex(i)]);
       i = getParentIndex(i);
    }
}
//Given an index, return index of its parent
int getParentIndex(int index){
    return (index -1)/2; // |2|binary heap
}

void heapify(Queue* myQueue) {
  // last index in the array
  dataNode* data = myQueue->data;
  int finalIndex = myQueue->size -1;
  printf("LastIndex %d \n", finalIndex);
  // start is assigned the index of the last parent node
  // which in our case is index[3] value(2)
  int nodeParent =getParentIndex(finalIndex);
 
  while (nodeParent >= 0) {
    // sift down the node at index start to the proper place
    // such that all nodes below the start index are in heap order
    // finalIndex -1 will give us the left item.
    heapDown(data, nodeParent, finalIndex);
    // decrement to the next lowest parent node
    nodeParent--;
  }
  // after sifting down the root all nodes/elements
  //  are in heap 
  printf("****************************\n");
  for (int i=0;i<myQueue->size;i++){
  	printf("%d %d\n", data[i].priority, data[i].data);
  
  }

}
 
void heapDown(dataNode* data, int parentIndex, int finalIndex) {
  int root = parentIndex;
  
  // while the root has at least one child
  while ((2 * root + 1) <= finalIndex) {
    // root*2+1 points to the left child
    int child = 2 * root + 1;
    // take the highest of the left or right child
    if (child + 1 <= finalIndex && data[child].priority < data[child + 1].priority) {
      // then point to the right child instead
      child = child + 1;
    }
 
    // out of max-heap order
    // swap the child with root if child is greater
    if (data[root].priority < data[child].priority) {
       swap(&data[root], &data[child]);
 
      // return the swapped root to test against
      //  it's new children
      root = child;
    } else {
      return;
    }
  } // End while
  
}
//Function to help swap items.
void swap(dataNode *x, dataNode *y)
{
    dataNode temp = *x;
    *x = *y;
    *y = temp;
}