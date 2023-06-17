// AVL tree (Dynamic Balancing using AVL)
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 //forward declarations
 typedef struct Node TNode;
// An AVL tree node (we have just added a height attribute to a normal BST)
struct Node{
    int key; //this could also be the data
    TNode *lChild;
    TNode *rChild;
    int nodeHeight; // recall height of node as number of edges to the farthest leaf.
};

//Function declarations
TNode* insertNodes(TNode* node, int key);
TNode* createNode(int key);
int getHeight(TNode* node);
int findmax(int x, int y);

void inorderTraversal(TNode* root);
void preorderTraversal(TNode* root);
void breadthFirstTraversal(TNode* root);
void printNodeAtLevel(TNode* node, int nodeLevel);

int getBalancefactor(TNode* node); //lab exercise   1
void postOrderTraversal(TNode *root); //lab exercise  2
TNode* rightRotation(TNode* nodeY); //lab exercise  3
TNode* leftRotation(TNode* nodeX); //lab exercise 4
void freeTree(TNode* node);
