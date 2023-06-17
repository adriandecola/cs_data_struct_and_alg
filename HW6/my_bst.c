// Adrian deCola
// April 6, 2023
//
// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Allociating memory to the binary search tree
    bst_t* myBST= (bst_t*) malloc(sizeof(bst_t));
    if (myBST == NULL){
        printf("Could not allocate memory for BST.\n");
	exit(-1);
    }

    //Initalizing
    myBST->size = 0;
    myBST->root = NULL; 

    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
	if (t == NULL){
		printf("BST is NULL. \n");
		exit(-1);
	}

	if (t->size == 0){
		return 1;
	}

	return 0;
}

// Adds a new node containg item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
/*** To get this to run in O(log(n)) time we will implemenet the BST as an AVL tree ***/
int bst_add(bst_t* t, int item){
	if (t == NULL){
		printf("BST is NULL. \n");
		return -1;
	}
	// Creating the new node
	bstnode_t* new_node = (bstnode_t*)malloc(sizeof(bstnode_t));
	if (new_node == NULL){
		printf("Could not allocate memory for BST node. \n");
		return -1;
	}
	new_node->data = item;
	new_node->leftChild = NULL;
	new_node->rightChild = NULL;
	new_node->nodeHeight = 0; // The height will initially be zero though we may rotate

	// Inserting the node with a recursive function that preserves the tree as and AVL tree
	t->root = insertNode(t->root, new_node);

	// Updating the BST size
	t->size += 1;

    return 1;
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// A BST that is NULL should print "(NULL)"
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
	if(NULL == t){
		printf("(NULL)");
	}
	else{
		if (order == 0){ 
			//print in ascending order using inorder traversal
			printf("Printing the BST in ascending order: ");
			LCR_print(t->root);
			printf("\n");
		}
		else{
			//print in decending order using inorder traversal
			printf("Printing the BST in decending order: ");
			RCL_print(t->root);
			printf("\n");
		}
	}
	return;
}


// Returns the sum of all the nodes in the bst. 
// A BST that is NULL exits the program.
// It should run in O(n) time.
int bst_sum(bst_t *t){
	if (t == NULL){
		printf("BST is NULL");
		exit(-1);
	}

	// Using a recursive function that sums all of values in a subtree starting at the root
	int sum = sumSubTree(t->root);

	return sum;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree -- exit the program. 
// It should run in O(log(n)) time.
// We won't use recursion this time, for a change
int bst_find(bst_t * t, int value){
	if (t->root == NULL){
		printf("BST is NULL");
		exit(-1);
	}

	bstnode_t* node = t->root; 
	// Looping through until the node has the value we are looking for 
	// or until we reach the end of the tree when the value should be
	// located
	// putting the node null expression first so that we first check if 
	// it is null and don't cause a segmentation fault
	// this is more of a test I know theres an easier way to do this
	// loop structure
	while (node != NULL && node->data != value){
		if (value > node->data){
			node = node->rightChild; // we search down the right subtree
		}
		else{
			node = node->leftChild; // we search down the left subtree
		}
	}
	// If the node is not null we have found the value
	if (node != NULL){
		return 1;
	}

	// If we reached the end of the tree
	return 0;
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
	if (t == NULL){
		printf("BST is NULL");
		exit(-1);
	}

	return t->size;
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.

void bst_free(bst_t* t){
	if (t->root == NULL){
		free(t);
		return;
	}
	// This funciton uses postOrder traversal to recursively free the deepest 
	// node first
	freeNodesRec(t->root);

	// Freeing the tree
	free(t);

	return;
}


















/*
insert key in subtree rooted with node and returns new root of subtree.
*/
bstnode_t* insertNode(bstnode_t* node, bstnode_t* new_node){
    /*BST insertion -usual technique , refer to notes */
    if (node == NULL)
        return(new_node);
 
    if (new_node->data < node->data)
        node->leftChild  = insertNode(node->leftChild, new_node);
    else if (new_node->data > node->data)
        node->rightChild = insertNode(node->rightChild, new_node);
    else // No duplicates in a BST
        return node;
    
    /* A update height of the node */
    node->nodeHeight = 1 + findmax(getHeight(node->leftChild),getHeight(node->rightChild));
 
    /* B. calculate balance factor (hLeft-hRigh)*/
    int balance = getBalancefactor(node);
 
    /*IF Node is unbalance, i.e balance is >1 or <-1, then it could be: */
 
    // 1. LEFT LEFT CASE (In this case, just rotate once on the RIGHT)
    if (balance > 1 && new_node->data < node->leftChild->data)
        return rightRotation(node);
 
    // 2. RIGHT RIGHT CASE (In this case, just rotate once on the left)
    if (balance < -1 && new_node->data > node->rightChild->data)
        return leftRotation(node);
 
    // 3. LEFT - RIGHT CASE ()
    if (balance > 1 && new_node->data > node->leftChild->data)
    {
        node->leftChild =  leftRotation(node->leftChild); //To make it a LEFT LEFT CASE
        return rightRotation(node);
    }
 
    // 4. RIGHT - LEFT CASE
    if (balance < -1 && new_node->data < node->rightChild->data)
    {
        node->rightChild = rightRotation(node->rightChild);//To make it a RIGHT RIGHT CASE
        return leftRotation(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
 
}

// A get method for height of the node.
int getHeight(bstnode_t* node){
    if (node == NULL)
        return -1;
    return node->nodeHeight;
}

// return the largest value (used for height comparison)
int findmax(int x, int y){
    return (x > y)? x : y;
}

// Finds the balance factor of a node
int getBalancefactor(bstnode_t* node){
	if (node == NULL){
		printf("Balance factor of NULL node will be defined as 0.\n");
		return 0;
	}
	int balance = getHeight(node->leftChild) - getHeight(node->rightChild);
	return balance;	
}

// Preforms a right rotation on a node
bstnode_t* rightRotation(bstnode_t* nodeY){
	// Right rotation
	bstnode_t* tempLR = nodeY->leftChild->rightChild;
	bstnode_t* newRoot = nodeY->leftChild;

	newRoot->rightChild = nodeY;
	newRoot->rightChild->leftChild = tempLR;

	// Updating the height of the affected nodes	
	newRoot->rightChild->nodeHeight = getHeight(newRoot->rightChild->rightChild)+ 1;
	if (newRoot->leftChild != NULL){
		newRoot->leftChild->nodeHeight = getHeight(newRoot->leftChild->rightChild) + 1;
	}
	newRoot->nodeHeight = getHeight(newRoot->rightChild) + 1;

	// Returning the new root
	return newRoot;
}


// Preforms a left rotation on a node
bstnode_t* leftRotation(bstnode_t* nodeX){
	//Left rotation
	bstnode_t* tempRL = nodeX->rightChild->leftChild;
	bstnode_t* newRoot = nodeX->rightChild;

	newRoot->leftChild = nodeX;
	newRoot->leftChild->rightChild = tempRL;

	//Updating the height of the affected nodes
	newRoot->leftChild->nodeHeight = getHeight(newRoot->leftChild->leftChild) + 1;
	if (newRoot->rightChild != NULL){
		newRoot->rightChild->nodeHeight = getHeight(newRoot->rightChild->leftChild) + 1;
	}
	newRoot->nodeHeight = getHeight(newRoot->leftChild) + 1;

	// Returning the new root
	return newRoot;
}




// A recursive function to sum all of the data in a given subtree
int sumSubTree(bstnode_t* node){
	// Base case
	if (node == NULL){
		return 0;
	}
	
	// Recursion
	return (node->data + sumSubTree(node->leftChild) + sumSubTree(node->rightChild));
}






// Helper function for printing the tree in ascending 
// order using inorder traversal
void LCR_print(bstnode_t* node){
	if (node != NULL){
		LCR_print(node->leftChild);
		printf("%d, ", node->data);
		LCR_print(node->rightChild);
	}
	return;
}

// Helper function for prinding the tree in decending
// order using inorder traversal
void RCL_print(bstnode_t* node){
	if (node != NULL){
		RCL_print(node->rightChild);
		printf("%d, ", node->data);
		RCL_print(node->leftChild);
	}
	return;
}

// This recursive function uses postorder traversal
// to recursively free all the nodes under the passed in
// node, likely the root
void freeNodesRec(bstnode_t* node){
	// Base Case
	if (node == NULL){
		return;
	}

	// Recursion- postorder traversal
	freeNodesRec(node->leftChild);
	freeNodesRec(node->rightChild);
	free(node);

	return;
}
