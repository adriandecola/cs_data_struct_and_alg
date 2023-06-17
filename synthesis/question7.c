/*
Author: Adrian deCola
Date: March 19, 2023
Purpose: This program if for quesiton 5a of the synthesis, which should do the following:

Write a recursive function called createList that receives a number (an integer value). 
Using this number, the function creates a linked list made up of the given number of nodes. 
In each node, store the number in a decreasing order. 

For example i.e. if the function received 5, then the linked list should have 5 nodes, and 
each node should have values 5, then, 4, then 3, then 2 and then 1 where the 5 is at the 
head and the 1 is at the tail.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
struct node{
   int data;
   NODE* next;
};

//Function declaration
NODE* createList(int n);

int main(void){
    /*
    Testing the function:
    
   NODE* llist = createList(10);
   printf("HEAD-> ");
   while (llist != NULL){
        NODE* temp = llist;
        printf(" %d ", llist->data);
        llist = llist->next;
        free(temp);
   }
   printf(" <-TAIL \n");
    */

   return 0;
}

NODE* createList(int n){
    //Allocating space for a node
    NODE* node = (NODE*) malloc(sizeof(NODE));

    //Base case
    if (n ==1){
        //Creating and returning the tail node
        node->data = 1;
        node->next = NULL;
        return node;
    }
    else{
        node->data = n;
        node->next = createList(n-1);
        return node;
    }
}
