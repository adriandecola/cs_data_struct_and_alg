#pragma once

//void *  - pointer to anything
typedef void * MY_NODE; //opaque object - masking my struct


/* function prototypes on linked lists (to be discussed prior to lab) */
MY_NODE makeNode(int n, MY_NODE myNextItem);
int    length(MY_NODE myList);
void   print(MY_NODE myList);
void   insertTail(int n, MY_NODE * myList);
MY_NODE find(int n, MY_NODE myList);
int    delete(MY_NODE myToDelete, MY_NODE * myListPtr);
void   insertHead(int n, MY_NODE * myList);
int    numPos(MY_NODE yList);

/* function prototypes on linked lists for lab */
int    lengthRec(MY_NODE myList);
void   freeList(MY_NODE myList);
MY_NODE copyList(MY_NODE myList);
MY_NODE mergeList(MY_NODE myList1, MY_NODE myList2);