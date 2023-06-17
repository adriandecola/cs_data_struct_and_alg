/**************************************************
 * CS 5008
 * Lab on linked lists
 * Implements a linked list of ints and some operations
 * on the list
 * Jonathan Mwaura
 **************************************************/
#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>



/* main function */
int main(void) {
  // LAB EXERCISE: update main to test the new functions
  MY_NODE lst1 = NULL;
  MY_NODE lst2 = NULL;
  
  insertHead(16, &lst1);
  insertHead(8, &lst1);
  insertHead(7, &lst1);
  insertHead(5, &lst1);
  insertHead(4, &lst1);

  insertHead(25, &lst2);
  insertHead(21, &lst2);
  insertHead(18, &lst2);
  insertHead(8, &lst2);
  insertHead(7, &lst2);
  insertHead(6, &lst2);
  insertHead(4, &lst2);
  insertHead(2, &lst2);

  printf("Printing lst1: \n");
  print(lst1);
  printf("\n");

  printf("Printing lst2: \n");
  print(lst2);
  printf("\n");

  printf("lst1 length: %d\n", length(lst1));
  printf("lst1 length (rec): %d\n\n", lengthRec(lst1));
  printf("lst2 length: %d\n", length(lst2));
  printf("lst2 length (rec): %d\n\n", lengthRec(lst2));

  MY_NODE lst3 = copyList(lst1);
  printf("Printing lst3, a copy of lst1: \n");
  print(lst3);
  printf("\n");

  MY_NODE mergedList = mergeList(lst1, lst2);

  printf("Printing mergedList: \n");
  print(mergedList);

  printf("mergedList length: %d\n", length(mergedList));  

  freeList(lst1);
  freeList(lst2);
  freeList(lst3);
  freeList(mergedList);

/////////////////// Printing Responses //////////////////////////
  printf("\nPart 3: We must free list->next before freeing list \n");
  printf("because if we do not do so we will lose the only \n");
  printf("pointer we have to list->next, will not be able to \n");
  printf("free it, and have a memeory leak. \n");
  printf("\n");
  printf("Part 4: The running time of copyList is O(N).\n");
  printf("\n");
  printf("Part5: The recurisve calls to mergeList eventually reach\n");
  printf("a base case because they keep mergeing the two list \n");
  printf("without the smaller value node of one of the list. \n");
  printf("Eventually one of the lists will run out of nodes \n");
  printf("and will only contain a NULL value. \n");
  printf("Supposing both lists had 200 items, in the worst \n");
  printf("case scenerio we go keep merging the list until \n");
  printf("we are left with one of the lists with length 0 and \n");
  printf("the other with length 1. In this case we made 400 \n");
  printf("calls to mergeList as each call we shorten one of  \n");
  printf("the list by one and we called the function once in \n");
  printf("the beginning. \n");
 
  return EXIT_SUCCESS;

}
