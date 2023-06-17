#include "graph.h"

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



int time = 0;  // note that this is a global variable (not great programming
               // practice) but need to have a global time count for DFS
               // it would be better to pass in a pointer to a variable that
               // stores the time that dfs could access and update, but
               // for the purpose of keeping this lab simple, we have a
               // global variable

/* createEmptyGraph sets up the graph data structure with numVertices */
Graph * createEmptyGraph(int numVertices) {
  if(numVertices <= 0) {
    return NULL;
  }
  Graph * g = (Graph *)malloc(sizeof(Graph));
  if(g == NULL) {
    return NULL;
  }
  g->V = numVertices;
  g->M = (int **) malloc(sizeof(int *) * numVertices);
  int i;
  if(g->M != NULL) {
    for(i = 0; i < numVertices; i++) {
      g->M[i] = (int *) malloc(sizeof(int) * numVertices);
      if(g->M[i] == NULL) {
	freeGraph(g);
	return NULL;
      }
    }
  }
  int j;
  for(i = 0; i < numVertices; i++) {
    for(j = 0; j < numVertices; j++) {
      g->M[i][j] = 0;
    }
  }
  return g;
}

/* freeGraph frees all memory associated with the graph */
void freeGraph(Graph * g) {
  if(g == NULL) {
    return;
  }
  int i;
  for(i = 0; i < g->V; i++) {
    free(g->M[i]);
  }
  free(g->M);
  free(g);
  g = NULL;
}

/* addEdge should do error-checking of the parameters and put a
   1 in the adjacency matrix at M[src][dest] */
int addEdge(Graph * g, int src, int dest) {
	// Checking that graph is not NULL
	if (g == NULL){
		printf("The graph is NULL, edge was not added.\n");
		return 0;
	}
	// Checking src and dest are valis
	if (src < 0 || src >= g->V || dest < 0 || dest >= g->V){
		printf("src or dest vertex invalid\n");
		return 0;
	}
	// Checking if the edge already exists
	if (g->M[src][dest] == 1){
		printf("edge aready exists between %d and %d\n", src, dest);
		return 0;
	}
	// Adding the edge
	g->M[src][dest] = 1;
	return 1;
}

/* outDegree returns the out degree of a vertex v */
int outDegree(Graph * g, int v) {
	if (g == NULL){
		printf("The graph is NULL, out-degree cannot be printed.\n");
		return 0;
	}
	if (v < 0 || v >= g->V){
		printf("The given vertex is invalid.\n");
		return 0;
	}
	// Counting the number of edges from V
	int count = 0;
	int i;
	for (i = 0; i <g->V; i++){
		if (g->M[v][i] == 1){
			count++;
		}
	}
	return count;
}

/* inDegree returns the in degree of a vertex v */
int inDegree(Graph * g, int v) {
	if (g == NULL){ 
		printf("The graph is NULL, out-degree cannot be printed.\n");
		return 0;
	}
	if (v < 0 || v >= g->V){
		printf("The given vertex is invalid.\n");
		return 0;
	}
	// Counting the number of edges towards v
	int count = 0;
	int i;
	for (i = 0; i < g->V; i++){
		if (g->M[i][v] ==1){
			count++;
		}
	}
	return count;
}

/* degree returns the degree of a vertex v */
int degree(Graph * g, int v) {
  return inDegree(g, v) + outDegree(g, v);
}

/* printGraph prints the graph as a matrix */
void printGraph(Graph * g) {
  if(g == NULL) {
    return;
  }
  int i, j;
  printf("Matrix for graph:\n");
  for(i = 0; i < g->V; i++) {
    for(j = 0; j < g->V; j++) {
      printf("%d\t", g->M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* isNeighbor returns 1 if edge (x, y), x to y, exists; 0 otherwise */
int isNeighbor(Graph * g, int x, int y) {
	if (g == NULL){   
		printf("The graph is NULL, out-degree cannot be printed.\n");
		return 0;
	}
	if (x < 0 || x>= g->V || y < 0 || y >= g->V){
		printf("x or y is an invalid vertex number.\n");
		return 0;
	}
	// Checking if there is an edge from x to y
	if (g->M[x][y] == 1 ){
		return 1;
	}
	return 0;
}

/* dfsInit initializes the array of DFS structs, so that the parent
   is -1 for all nodes, color is white for all nodes, and discover and finish
   times are -1 */ 
DFS * dfsInit(Graph * g) {
  if(g == NULL || g->V <= 0) {
    time = 0;
    return NULL;
  }
  DFS * arr = malloc(sizeof(DFS) * g->V);
  int i;
  for(i = 0; i < g->V; i++) {
    arr[i].parent = -1;
    arr[i].color = white;
    arr[i].discover = -1;
    arr[i].finish = -1;
  }
  time = 0;
  return arr;
}

/* dfs does depth-first search of the graph from src, filling in the arr
   of DFS structs as it processes, should be recursive. 
   Looking back, I could have also implemented this depth first search in 
   different ways but this way works and is recursive */
void dfs(Graph * g, DFS arr[], int src) {
	// do DFS from src node in graph g
	if(g == NULL || arr == NULL) {
		return;
	}
	if(src < 0 || src >= g->V) {
		return;
	}
	
	// Visit the vertex if it's not visited
	if (arr[src].color == white){
		arr[src].discover = time;
		time++;
		arr[src].color = gray;
	}
	// Finding the next vertex we can visit
	int i;
	for (i = 0; i <= g->V; i++){ 
		if (g->M[src][i] == 1 && arr[i].color == white){
			// Updating the current vertex
			arr[src].color = black; 
			// Visiting the next vertex
			arr[i].parent = src;
			dfs(g, arr, i);
		}
	}
	// Getting through this list means that src has no 
	// new (not already visited) verticies to visit
	arr[src].color = black;
	if (arr[src].finish == -1){
		arr[src].finish = time;
		time++;
	}
	dfs(g, arr, arr[src].parent);
	return;
}

/* printReversePath prints the path from dest <- node <- node <- src <-
   note that you may assume that dfs has already filled in arr when
   doing dfs from the src */
void printReversePath(Graph * g, DFS arr[], int src, int dest) {
  // print path from dest to src
  // note: assuming arr has values set from dfs from src
  if(g == NULL || arr == NULL) {
    printf("graph or arr is invalid. No path.\n");
    return;
  }
  // start with dest and put it into an array
  printf("PATH: %d <-", dest);
  int current = dest;

  while (current != src){
    current = arr[current].parent;
    printf("%d <-", current);
  }
  printf("\n");
}

/* bfsInit initializes the array of BFS structs, so that the parent
   is -1 for all nodes and the color is white for all nodes*/ 
BFS * bfsInit(Graph * g) {
  if(g == NULL || g->V <= 0) {
    time = 0;
    return NULL;
  }
  BFS * arr = malloc(sizeof(BFS) * g->V);
  int i;
  for(i = 0; i < g->V; i++) {
    arr[i].parent = -1;
    arr[i].color = white;
  }
  return arr;
}

/* bfs does breadth-first search of the graph from src, filling in the arr
   of BFS structs as it processes, bfs is certain to find the shortest path 
   for bfs gray indicates a vertex has been added to the queue and black 
   means it has been searched and all its neighbors added to the queue
   if not already*/
void bfs(Graph * g, BFS arr[], int src) {
	// do DFS from src node in graph g
	if(g == NULL || arr == NULL) {
		printf("Graph or BFS are NULL.\n");
		return;
	}
	if(src < 0 || src >= g->V) {
		printf("src is not a valid vertex.\n");
		return;
	}
	
	QUEUE q= NULL; // initializing
	q = queue_init_default();

	queue_enqueue(q, src);
	arr[src].color = gray;
	
	int vertex;
	while (queue_getTotalItems(q) != 0){
		vertex = queue_dequeue(q);

		// searching the vertex for neighbors
		int i;
		for (i = 0; i< g->V; i++){
			// if a path exits and we havent searched or added the vertex
			// to the queue
			if (g->M[vertex][i] == 1 && arr[i].color == white){
				queue_enqueue(q, i);
				arr[i].color = gray;
				arr[i].parent = vertex;
			}
		}
		arr[vertex].color = black;
	}

	//queue_destroy(q);
	return;
}


/* printReversePath prints the path from dest <- node <- node <- src <-
   note that you may assume that dfs has already filled in arr when
   doing dfs from the src */
void printReversePathBFS(Graph * g, BFS arr[], int src, int dest) {
  // print path from dest to src
  // note: assuming arr has values set from dfs from src
  if(g == NULL || arr == NULL) {
    printf("graph or arr is invalid. No path.\n");
    return;
  }
  // start with dest and put it into an array
  printf("PATH: %d <-", dest);
  int current = dest;

  while (current != src){
    current = arr[current].parent;
    printf("%d <-", current);
  }
  printf("\n");
}


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


// returns front item or -1 if empty
int queue_dequeue(QUEUE hQueue){
	//removes from the front
	MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type

	if (pQueue->totalItems != 0){
		//checking if the front of the list now needs to wrap around
		int item = pQueue->data[pQueue->frontIndex];
		if (pQueue->frontIndex + 1 == pQueue->capacity){
			pQueue->frontIndex = 0;
		}
		else{
			pQueue->frontIndex++;
		}

		pQueue->totalItems--;
		return item;
	}

	return -1;
}

void queue_destroy(QUEUE* phQueue){

 MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;
 
 if(pQueue!=NULL){
 
 	free (pQueue->data);
 	free(pQueue);
 }
 *phQueue = NULL; 


}

int queue_getTotalItems(QUEUE hQueue){
	 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type
	 
	 return pQueue->totalItems;


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