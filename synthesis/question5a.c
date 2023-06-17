/*
Author: Adrian deCola
Date: March 18, 2023
Purpose: This program if for quesiton 5a of the synthesis, which should do the following:

Write a recursive function called sum that given a Node pointer to the head of a list will 
return the sum of all data in the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
struct node{
   int data;
   NODE* next;
};

//Function declaration
int sum(NODE* list);

int main(void){
    /*
    //Testing the sum function
    NODE* linkList = (NODE*) malloc(sizeof(NODE));
    linkList->data = 7;
    NODE* node2 = (NODE*) malloc(sizeof(NODE));
    node2->data = 2;
    linkList->next = node2;
    NODE* node3 = (NODE*) malloc(sizeof(NODE));
    node3->data = 5;
    node2->next = node3;
    NODE* node4 = (NODE*) malloc(sizeof(NODE));
    node4->data = 21;
    node3->next = node4;
    NODE* node5 = (NODE*) malloc(sizeof(NODE));
    node5->data = 3;
    node4->next = node5;
    NODE* node6 = (NODE*) malloc(sizeof(NODE));
    node6->data = 2;
    node5->next = node6;
    NODE* node7 = (NODE*) malloc(sizeof(NODE));
    node7->data = 4;
    node6->next = node7;
    NODE* node8 = (NODE*) malloc(sizeof(NODE));
    node8->data = 17;
    node7->next = node8;
    NODE* node9 = (NODE*) malloc(sizeof(NODE));
    node9->data = 39;
    node8->next = node9;
    node9->next = NULL;

    printf("sum: %d\n", sum(linkList));

    free(linkList);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    free(node8);
    free(node9);
    */

    return 0;
}



//Function implementation
int sum(NODE* list) {
    //base case
	if(list == NULL) {
		return 0;
	} 
	else{
		//makes list one shorter and adds value to the return expression
        int val = list->data;
		list = list->next;	
		return sum(list) + val;  
    }
}
