// I only provide the function definition as the question asks
// testing was done in another file


/*
This function returns 1 if the nodes passed in are identical and 
0 if not. This function is recursive and assumes all the left and
right node pointers have been initialized to NULL if they don't 
point to a node
*/
int identical_tree_nodes(BinaryNode_Ptr node1, BinaryNode_Ptr node2){
    // checking if either passed in node pointer is NULL
    if (node1 == NULL || node2 == NULL){
        if (node1 == NULL && node2 == NULL){
            return 1;
        }
        return 0; //only one node is NULL
    }
    //checking they hold the same item
    if (node1->item != node2->item){
        return 0;
    }
    // THe fallowing will evaluate to 0 if the left or right children are not the same
    return (identical_tree_nodes(node1->left, node2->left) * identical_tree_nodes(node1->right, node2->right));
}
