#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void* QUEUE;

typedef enum status{Failure, Success}Status;
typedef enum {white, gray, black} COLOR;


typedef struct Graph {
  int V;     //number of vertices in G
  int ** M;  //2D array of ints, adjacency matrix
} Graph;

typedef struct DFS {
  COLOR color;  // white, gray, or black
  int parent;
  int discover;
  int finish;
} DFS;

typedef struct BFS {
  COLOR color;
  int parent;
} BFS;



// prototypes
Graph * createEmptyGraph(int numVertices);
void printGraph(Graph * g);
void freeGraph(Graph * g);
int degree(Graph * g, int v);
DFS * dfsInit(Graph * g);
BFS * bfsInit(Graph * g);

//You will need to finalize the following functions
int addEdge(Graph * g, int src, int dest);
int outDegree(Graph * g, int v);
int inDegree(Graph * g, int v);
int isNeighbor(Graph * g, int x, int y);
void dfs(Graph * g, DFS arr[], int src);
void bfs(Graph * g, BFS arr[], int src);
void printReversePath(Graph * g, DFS arr[], int src, int dest);
void printReversePathBFS(Graph * g, BFS arr[], int src, int dest);

QUEUE queue_init_default();

Status queue_enqueue (QUEUE hQueue, int item); ///add items at the back
int queue_dequeue(QUEUE hQueue); //remove items at the front
void queue_destroy(QUEUE* phQueue);
int queue_getTotalItems(QUEUE hQueue);
void printItems(QUEUE* phQueue);

#endif
