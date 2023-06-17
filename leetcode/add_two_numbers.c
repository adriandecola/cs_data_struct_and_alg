/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/two-sum
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int index1 = -1;
    int index2 = -1;
    for (i = 0; i < numsSize; i++){
        for (j = 0; j < numsSize; j++){
            if (nums[i] + nums[j] == target && i != j){
                index1 = i;
                index2 = j;
            }
        }
    }
    *returnSize = 2;
    int* indicies = (int*)malloc(sizeof(int)*2);
    indicies[0] = index1;
    indicies[1] = index2;
    return indicies;
}