#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct nodeTag Node;
/* similar to the textbook -- a Node represents one node in the linked list */
struct nodeTag {
  int num; // value stored in node
  Node * next; // pointer to next node in list
};

// book also defines Node * as NodePtr
// Jonathan prefers to use type Node * instead of NodePtr for the reminder
// of the pointer type






/******************** function definitions new for lab *****/

/* lengthRec
 * parameter -- list
 * returns the length of the list (# nodes)
 */
int lengthRec(MY_NODE myList) {
    Node* list = (Node*) myList;  
	if(list == NULL) {
		return 0;
	} 
	else{
		//makes list one shorter and adds that to return expression
		list = list->next;	
		return lengthRec(list) + 1;  
	}
}

/* freeList
 * parameter -- list
 * frees all nodes in the list
 */
void freeList(MY_NODE myList) {
    Node* list = (Node*) myList;  
	if(list == NULL) {
		return;
	}
	else{
		freeList(list->next);
		//once we've gotten here we are at the end of list
		//(list->next is NULL)
		free(list);	   
	}
}

/* copyList
 * parameter -- list
 * returns a copy of the list
 */
MY_NODE copyList(MY_NODE myList) {
    Node* list = (Node*) myList;  
	Node * ret = NULL;
	if(list == NULL) {
		return NULL;
	}
	else{
		// Goes all the way to the end of the list then
		// recursively makes nodes from there that point
		// to the correct next node
		ret = makeNode(list->num, copyList((MY_NODE) list->next));
		return ret; 
	}
}

/* mergeList
 * parameters: list1 and list 2
 * merges the two lists, keeping the values in ascending order
 * NOTE: only works if list1 and list2 are sorted
 */
MY_NODE mergeList(MY_NODE myList1, MY_NODE myList2) {
    Node* list1 = (Node*) myList1;  
    Node* list2 = (Node*) myList2;  
	if (list1 == NULL) {
		return copyList( (MY_NODE) list2);
	}
	else if (list2 == NULL) {
		return copyList( (MY_NODE) list1);
	}
	else if (list1->num < list2->num) {
		//Makes a new node of the smaller value node and which 
		//then recursively points to the merged node result 
		//of list 2 and list 1 without this smaller node
		return makeNode(list1->num, mergeList((MY_NODE) list1->next , (MY_NODE) list2)); 
	}
	else {
		return makeNode(list2->num, mergeList((MY_NODE) list1, (MY_NODE) list2->next));
	}
}


/********************* function definitions from lecture ****/

/* makeNode
 * parameters -- n (the number to store in the node)
 *            -- nextItem (the next link of the node)
 * slightly different than textbook version */
MY_NODE makeNode(int n, MY_NODE myNextItem) {
  Node * nextItem = (Node*) myNextItem;
  Node * ret = (Node * ) malloc(sizeof(Node));
  ret->num = n;
  ret->next = nextItem;
  return (MY_NODE) ret;
}

/* length
 * parameter -- list (the linked list)
 * returns the length (# nodes) in the linked list
 * implemented iteratively */
int length(MY_NODE myList) {
  Node* list = (Node*) myList;  
  int len = 0;
  while(list != NULL) {
    len++;
    list = list->next;
  }
  return len;
}

/* print
 * parameter -- list (the linked list)
 * prints the values of the nodes (in order) of the list
 */
void print(MY_NODE myList) {
  Node* list = (Node*) myList;  
  printf("Linked list contents: ");
  while(list != NULL) {
    printf("%d ", list->num);
    list = list->next;
  }
  printf("\n");
}

/* insertTail
 * parameters -- n (the value of the node to insert)
 *            -- list (the linked list)
 * inserts new node at the end with value n
 * note: this is done by passing the pointer to list, so
 * when the function returns, the list object that was
 * passed to this function has been altered
 */
void insertTail(int n, MY_NODE * myListPtr) {
  Node** listPtr = (Node**) myListPtr;  
  Node* list =  *listPtr;
  if(list == NULL) {
    // create a 1-node list
    *listPtr = makeNode(n, NULL);
    return;
  }
  while(list != NULL) {
    if(list->next == NULL) {
      // insert new node here since we found the last node
      list->next = makeNode(n, NULL);
      return;
    }
    list = list->next;
  }
}

/* find
 * parameters -- n (the value to search for)
 *            -- list (the linked list)
 * returns a pointer to the first node found with value n
 * if no such value is found, returns NULL
 */
MY_NODE find(int n, MY_NODE myList) {
  Node* list = (Node*) myList;
  while(list != NULL) {
    if(list->num == n) {
      return (MY_NODE) list;
    }
    list = list->next;
  }
  // no node with value n found
  return NULL; // or could return list, since list has value NULL
}

/* delete
 * parameters -- toDelete (the node to find and delete)
 *            -- listPtr (pointer to the list)
 * note: must pass listPtr in case the first element of the list
 * is deleted -- passing the list by reference, so the address
 * to the first item in the list can get updated if necessary
 *
 * returns 0 if no item found and deleted
 * returns 1 if a node is deleted
 */
int delete(MY_NODE myToDelete, MY_NODE * myListPtr) {
  Node* toDelete = (Node*) myToDelete;
  Node ** listPtr = (Node**) myListPtr;
  Node * list = *listPtr;  // list is the linked list
  // case: either toDelete or list is null -- will not be deleting
  if(toDelete == NULL || list == NULL) {
    return 0;  // indicates no change to the list
  }

  // special case: toDelete is first node in list
  if(toDelete == list) {
     *listPtr = list->next;   // now list->next becomes first node in list
                              // returning new first address via pointer
     free(toDelete);
    return 1;  // indicates that a node was deleted
  }

  // case: need to find toDelete somewhere other than first node in list
  Node * before = list;
  list = list->next;
  while(list != NULL) {
    if(toDelete == list) {
      // redo pointers and then free memory
      before->next = list->next;
      free(list);
      return 1;
    }
    before = list;  // update for next iteration
    list = list->next;
  }
  return 0;  // toDelete not found
}

/* insertHead
 * parameters -- n (the value of the new node)
 *            -- listPtr (a pointer to the linked list for the insertion)
 *
 * inserts the new node at the front of the list
 */
void insertHead(int n, MY_NODE * myListPtr) {
  Node** listPtr = (Node**) myListPtr;
  // create new node

  *listPtr = (Node*) makeNode(n, (MY_NODE) *listPtr);
}

/* numPos
 * parameters -- list (list to search)
 *
 * returns the number of positive ints in the list
 */
int numPos(MY_NODE myList) {
  Node* list = (Node*) myList;
  int countPos = 0;
  if(list == NULL) {
    return 0;
  }
  while(list != NULL) {
    if(list->num > 0) {
      countPos++;
    }
    list = list->next;
  }
  return countPos;
}
    
