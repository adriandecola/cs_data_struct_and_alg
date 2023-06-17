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

void heapify(dataNode* data, int size);
void heapDown(dataNode* data, int start, int end);

int main(){

  Queue myQueue;
  myQueue.size=0;
  myQueue.capacity=9;
  myQueue.data = (dataNode*)malloc(sizeof(dataNode)*  myQueue.capacity);
  myQueue.data[0].priority = 7;
  myQueue.data[1].priority = 2;
  myQueue.data[2].priority = 13;
  myQueue.data[3].priority = 1;
  myQueue.data[4].priority = 20;
  myQueue.data[5].priority = 17;
  
  for (int i=0; i<myQueue.capacity;i++){
        myQueue.data[i].data=i;
        //myQueue.data[i].priority=rand()%20;
        myQueue.size+=1;
  }
  for (int i=0; i<myQueue.size;i++){
    printf("%d %d \n", myQueue.data[i].priority, myQueue.data[i].data );
  }
  

	//int data[] = {1, 3, 36, 2, 19, 25, 100, 17, 7};
	//int size = sizeof(data)/sizeof(data[0]);
  
	/*
	for (int i=0;i<size;i++){
  		printf("%d \n", data[i]);
  }
  printf("*******************************\n");
  */
   
  heapify(myQueue.data, myQueue.size);
	
	return 0;
}
 
void heapify(dataNode* data, int size) {
  // last index in the array
  int end = size -1;
  // start is assigned the index of the last parent node
  // which in our case is index[3] value(2)
  int start = (end - 1) / 2; // |2|binary heap
 
  while (start >= 0) {
    // sift down the node at index start to the proper place
    // such that all nodes below the start index are in heap
    // order
    heapDown(data, start, end - 1);
    // decrement to the next lowest parent node
    start--;
  }
  // after sifting down the root all nodes/elements
  //  are in heap 
  printf("****************************\n");
  for (int i=0;i<size;i++){
  	printf("%d %d\n", data[i].priority, data[i].data);
  
  }

}
 
void heapDown(dataNode* data, int start, int end) {
  int root = start;
  
  // while the root has at least one child
  while ((2 * root + 1) <= end) {
    // root*2+1 points to the left child
    int child = 2 * root + 1;
    // take the highest of the left or right child
    if (child + 1 <= end && data[child].priority < data[child + 1].priority) {
      // then point to the right child instead
      child = child + 1;
    }
 
    // out of max-heap order
    // swap the child with root if child is greater
    if (data[root].priority < data[child].priority) {
      dataNode tmp = data[root];
      data[root] = data[child];
      data[child] = tmp;
 
      // return the swapped root to test against
      //  it's new children
      root = child;
    } else {
      return;
    }
  } // End while
  
}