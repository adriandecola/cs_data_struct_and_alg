#include "AVLtree.h"
/*
insert key in subtree rootedwith node and returns new root of subtree.
*/
TNode* insertNodes(TNode* node, int key){
    /*BST insertion -usual technique , refer to notes */
    if (node == NULL)
        return(createNode(key));
 
    if (key < node->key)
        node->lChild  = insertNodes(node->lChild, key);
    else if (key > node->key)
        node->rChild = insertNodes(node->rChild, key);
    else // No duplicates in a BST
        return node;
    
    /* A update height of the node */
    node->nodeHeight = 1 + findmax(getHeight(node->lChild),getHeight(node->rChild));
 
    /* B. calculate balance factor (hLeft-hRigh)*/
    int balance = getBalancefactor(node);
 
    /*IF Node is unbalance, i.e balance is >1 or <-1, then it could be: */
 
    // 1. LEFT LEFT CASE (In this case, just rotate once on the RIGHT)
    if (balance > 1 && key < node->lChild->key)
        return rightRotation(node);
 
    // 2. RIGHT RIGHT CASE (In this case, just rotate once on the left)
    if (balance < -1 && key > node->rChild->key)
        return leftRotation(node);
 
    // 3. LEFT - RIGHT CASE ()
    if (balance > 1 && key > node->lChild->key)
    {
        node->lChild =  leftRotation(node->lChild); //To make it a LEFT LEFT CASE
        return rightRotation(node);
    }
 
    // 4. RIGHT - LEFT CASE
    if (balance < -1 && key < node->rChild->key)
    {
        node->rChild = rightRotation(node->rChild);//To make it a RIGHT RIGHT CASE
        return leftRotation(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
 
}

/* Create a new node with the given key and NULL lChild and rChild pointers. */
TNode* createNode(int key){
    TNode* node = (TNode*) malloc(sizeof(TNode));
    node->key   = key;
    node->lChild   = NULL;
    node->rChild  = NULL;
    node->nodeHeight = 0;  //assume that node is added at leaf has height = 1
    return(node);
}

// A get method for height of the node.
int getHeight(TNode *node){
    if (node == NULL)
        return -1;
    return node->nodeHeight;
}


// This should show a sorted out tree(recall from last class)
void inorderTraversal(TNode *root){
    if(root != NULL)
    {
        inorderTraversal(root->lChild);
        printf("%d ", root->key);
        inorderTraversal(root->rChild);
    }
    
    return;
}
// This should show tree with root first (recall from last class)
void preorderTraversal(TNode *root){
    if(root != NULL)
    {
         printf("%d ", root->key);
         preorderTraversal(root->lChild);
         preorderTraversal(root->rChild);
    }
   return;
}

// return the largest value (used for height comparison)
int findmax(int x, int y){
    return (x > y)? x : y;
}

//This uses printNodeAtLevel to do a BFS traversal
void breadthFirstTraversal(TNode* root){

    for (int i=0; i<=getHeight(root); ++i ){
        printf("Level %d: ", i);
        printNodeAtLevel(root, i);
        printf("\n");

    }

} 
void printNodeAtLevel(TNode* node, int nodeLevel){
	//Print N (for Null) so that an entire complete tree can be visualized
    if (node == NULL) {
     printf("N  ");
     return;
     }
    if (nodeLevel ==0){
        printf("%d  ", node->key);
    }
    else if(nodeLevel > 0){
        printNodeAtLevel(node->lChild, nodeLevel-1);
        printNodeAtLevel(node->rChild, nodeLevel-1);
    }
 return;
}

// Exercise 1 (5 points)
int getBalancefactor(TNode* node){
	if (node == NULL){
		printf("Balance factor of NULL node will be defined as 0.\n");
		return 0;
	}
	int balance = getHeight(node->lChild) - getHeight(node->rChild);
	return balance;	
}

// Exercise 2 (5 points)
void postOrderTraversal(TNode *root){
	if (root != NULL){
		postOrderTraversal(root->lChild);
		postOrderTraversal(root->rChild);
		printf("%d ", root->key);
	} 
   return;
}

 
// Exercise 3 (10 points)
TNode *rightRotation(TNode* nodeY){
	// Right rotation
	TNode* tempLR = nodeY->lChild->rChild;
	TNode* newRoot = nodeY->lChild;

	newRoot->rChild = nodeY;
	newRoot->rChild->lChild = tempLR;

	// Updating the height of the affected nodes	
	newRoot->rChild->nodeHeight = getHeight(newRoot->rChild->rChild)+ 1;
	if (newRoot->lChild != NULL){
		newRoot->lChild->nodeHeight = getHeight(newRoot->lChild->rChild) + 1;
	}
	newRoot->nodeHeight = getHeight(newRoot->rChild) + 1;

	// Returning the new root
	return newRoot;
}


// Exercise 4 (10 points)
TNode* leftRotation(TNode* nodeX){
	//Left rotation
	TNode* tempRL = nodeX->rChild->lChild;
	TNode* newRoot = nodeX->rChild;

	newRoot->lChild = nodeX;
	newRoot->lChild->rChild = tempRL;

	//Updating the height of the affected nodes
	newRoot->lChild->nodeHeight = getHeight(newRoot->lChild->lChild) + 1;
	if (newRoot->rChild != NULL){
		newRoot->rChild->nodeHeight = getHeight(newRoot->rChild->lChild) + 1;
	}
	newRoot->nodeHeight = getHeight(newRoot->lChild) + 1;

	// Returning the new root
	return newRoot;
}

// Funciton to recursively free tree
void freeTree(TNode* node){
	if (node == NULL){
		return;
	}
	freeTree(node->lChild);
	freeTree(node->rChild);
	free(node);

	return;
}


/* Never actually needed this
 *
 *
// This function recursively updated the height of all the nodes an a (sub)tree passed in
void updateHeightRec(TNode* subTree, int heightChange)
	// Base case
	if (subTree == NULL){
		return;
	}
	// Updating the height of the current node
	subTree-> nodeHeight += heightChange;

	// Recursively updating the height of the left and right children
	updateHeightRec(subTree->lChild, heightChange);
	updateHeightRec(subTree->rChild, heightChange);

	return;
}
 *
 *
 */











