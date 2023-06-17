#include "graph.h"

/* main creates a graph and processes it (degrees, neighbors, DFS, paths) */
int main(void) {
  // create graph
  printf("Creating graph.\n");
  Graph * g = createEmptyGraph(6);
  int ok1 = addEdge(g, 0, 5);
  int ok2 = addEdge(g, 0, 3);
  int ok3 = addEdge(g, 1, 2);
  int ok4 = addEdge(g, 3, 5);
  int ok5 = addEdge(g, 4, 3);
  int ok6 = addEdge(g, 2, 1);
  int ok7 = addEdge(g, 2, 3);
  int ok8 = addEdge(g, 1, 0);
  int ok9 = addEdge(g, -2, 0);
  int ok10 = addEdge(g, 2, 4);
  int ok11 = addEdge(g, 5, 4);
  int ok12 = addEdge(g, 4, -1);
  int ok13 = addEdge(g, 5, 1);
  int ok14 = addEdge(g, 7, 2);
  int ok15 = addEdge(g, 3, 1);
  int ok16 = addEdge(g, 2, 1);

  int list_ok_var[] = {ok1,ok2,ok3,ok4,ok5,ok6,ok7,ok8,ok9,ok10,ok11,ok12,ok13,ok14,ok15,ok16}; 

  int j;
  for (j =0; j < 16; j++){
    printf("ok%d is %d\n", j+1, list_ok_var[j]);
  }

  printf("\n");
  printGraph(g);

  // print degree information
  printf("out degree of 0: %d\n", outDegree(g, 0));
  printf("in degree of 0: %d\n", inDegree(g, 0));
  printf("total degree of 0: %d\n", degree(g, 0));
  printf("\n");

  // print neighbor information
  printf("Neighbors of 0:\t");
  int i;
  for(i = 0; i < g->V; i++) {
    if(isNeighbor(g, 0, i)) {
      printf("%d  ", i);
    }
  }
  printf("\n\n");

  // print DFS information
  printf("------------------ DFS ------------------\n");
  DFS * arr = dfsInit(g);
  dfs(g, arr, 0);
  for(i = 0; i < g->V; i++) {
    printf("Node %d: %d/%d, parent: %d\n", i, arr[i].discover, arr[i].finish, arr[i].parent);
  }

  // print DFS paths
  printReversePath(g, arr, 0, 1);
  printReversePath(g, arr, 0, 2);
  printReversePath(g, arr, 0, 3);
  printReversePath(g, arr, 0, 4);
  printReversePath(g, arr, 0, 5);

  printf("\n");

  // print BFS information
  printf("------------------ BFS ------------------\n");
  BFS * arr_bfs = bfsInit(g);
  bfs(g, arr_bfs, 0);
  for(i = 0; i < g->V; i++) {
    printf("Node %d:        parent: %d\n", i, arr_bfs[i].parent);
  }

  // print BFS paths
  printReversePathBFS(g, arr_bfs, 0, 1);
  printReversePathBFS(g, arr_bfs, 0, 2);
  printReversePathBFS(g, arr_bfs, 0, 3);
  printReversePathBFS(g, arr_bfs, 0, 4);
  printReversePathBFS(g, arr_bfs, 0, 5);

  free(arr);
  freeGraph(g);
  free(arr_bfs);
  return EXIT_SUCCESS;
}
