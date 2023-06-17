/*
Author: Adrian deCola
Date: March 19, 2023
Purpose: This program if for quesiton 5a of the synthesis, which should do the following:

The code fragment given defines a NODE type that has been used in a circularly singly 
linked list. Please complete the following function to concatenate two circularly singly 
linked list into one circularly singly linked list. The function signature is as follows:
NODE concatenate(NODE list1, NODE list2)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
struct node{
   int data;
   NODE next;
};


//Function declaration
NODE concatenate(NODE list1, NODE list2);

int main(void){
    /*
    //Testing the concatenate function
    int size_node = sizeof(int) + sizeof(NODE);
    NODE linkList1 = (NODE) malloc(size_node);
    linkList1->data = 7;
    NODE node2 = (NODE) malloc(size_node);
    node2->data = 2;
    linkList1->next = node2;
    NODE node3 = (NODE) malloc(size_node);
    node3->data = 5;
    node2->next = node3;
    NODE node4 = (NODE) malloc(size_node);
    node4->data = 21;
    node3->next = node4;
    node4->next = linkList1;

    NODE linkList2 = (NODE) malloc(size_node);
    linkList2->data = 3;
    NODE node6 = (NODE) malloc(size_node);
    node6->data = 2;
    linkList2->next = node6;
    NODE node7 = (NODE) malloc(size_node);
    node7->data = 4;
    node6->next = node7;
    NODE node8 = (NODE) malloc(size_node);
    node8->data = 17;
    node7->next = node8;
    NODE node9 = (NODE) malloc(size_node);
    node9->data = 39;
    node8->next = node9;
    node9->next = linkList2;

    printf("LL1 HEAD-> ");
    int i;
    NODE temp = linkList1;
    for (i=0; i < 8; i++){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" <-TAIL \n");

    printf("LL2 HEAD-> ");
    temp = linkList2;
    for (i=0; i < 10; i++){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" <-TAIL \n");

    NODE linkList3 = concatenate(linkList1, linkList2);

    printf("LL3 HEAD-> ");
    temp = linkList3;
    for (i=0; i < 18; i++){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" <-TAIL \n");    

    free(linkList1);
    free(node2);
    free(node3);
    free(node4);
    free(linkList2);
    free(node6);
    free(node7);
    free(node8);
    free(node9);
    */

    return 0;
}


NODE concatenate(NODE list1, NODE list2){
    /*
    For this I will concatenate such that the head pointes to list1 and list2 follows 
    after list1. We return a list that uses these two lists so list1 and list2 should 
    no longer be used. 
    */

    //Starting the concatenated list with list1
    NODE list3 = list1;
    
    //Getting to the tail of list1
    NODE temp1 =  list1;
    while (temp1->next != list1){
        temp1 = temp1->next;
    }
    //temp is now a pointer to the tail of list1
    //Getting to the tail of list 2
    NODE temp2 = list2;
    while (temp2->next != list2){
        temp2 = temp2->next;
    }
    //temp is now a pointer to the tail of list2
    
    //We will make the tail of list1 point to the head of list2
    temp1->next = list2;
    //We will also make the tail of list2 point the head of list1
    temp2->next = list1;

    return list3;
}
