/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head){
    // base case
    if (head == NULL){
        return NULL;
    }
    //recursive
    // iterate through the list finding the end and middle
    int i = 0;
    struct ListNode* prev_middle = NULL;
    struct ListNode* middle = head;
    struct ListNode* tmp = head;
    while (tmp != NULL){
        tmp = tmp->next;
        // only moves once every two iterations
        if (i%2 == 1){
            prev_middle = middle;
            middle = middle->next;
        }
        i++;
    }
    // making the middle node a TreeNode*
    struct TreeNode* retNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    retNode->val = middle->val;

    if (prev_middle == NULL){
        retNode->left = NULL;
        if (middle->next == NULL){
            retNode->right = NULL;
        }
        else{
            retNode->right = sortedListToBST(middle->next);
        }
    }

    else{
        prev_middle->next = NULL;
        // making it so the left side is its on sub linked list
        retNode->left = sortedListToBST(head);
        retNode->right = sortedListToBST(middle->next);
    }
    return retNode;
}