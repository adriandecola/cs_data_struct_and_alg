/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* recArrayToBST(int* nums, int start, int end);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return (recArrayToBST(nums, 0, numsSize - 1));
}

struct TreeNode* recArrayToBST(int* nums, int start, int end){
    //base cases
    if (start > end){
        return NULL;
    }
    else if (start == end){
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = nums[start];
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    //recursion
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int m = (start + end) / 2;
    node->val = nums[m];
    node->left = recArrayToBST(nums, start, m-1);
    node->right = recArrayToBST(nums, m+1, end);
    return node;
}