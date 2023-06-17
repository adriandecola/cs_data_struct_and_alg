// AVL tree (Dynamic Balancing using AVL)
#include "AVLtree.h"
 

/* Driver program*/
int main(int argc, char** argv){
  TNode* root = NULL;
  int key;

  srand(time(NULL));
  /* create a tree now.*/
  for (int i =10; i<20;i++){
      key = rand()%100;
      printf("Adding a node with key: %d\n", key);
      root = insertNodes(root, key);
      breadthFirstTraversal(root);

  }
 
  printf("Preorder traversal : \n");
  preorderTraversal(root);
  printf("\n");

  printf("Inorder traversal (sorted tree): \n");
  inorderTraversal(root);
  printf("\n");

  printf("Level printing: \n");
  breadthFirstTraversal(root);
  printf("\n");

  printf("Postorder traversal : \n");
  postOrderTraversal(root);
  printf("\n");

  freeTree(root);

  return 0;
}

