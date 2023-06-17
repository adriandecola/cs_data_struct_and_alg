/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/remove-element
*/



int removeElement(int* nums, int numsSize, int val){
    int i; // to iterate through the list
    int j; // to swap a val to the end of the list
    int tmp;
    int k = 0;
    for (i = 0; i < numsSize; i++){
        if (nums[i] == val){
            // Swap nums[i] to the end of the list
            j = i;
            while (j < numsSize - 1){
                tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
                j++;
            }
            i--; // we swapped so we still need to check the same index
            numsSize--; // we want to check one less item at the end of the array
        }
        else{
            k++;
        }
    }
    return k;
}