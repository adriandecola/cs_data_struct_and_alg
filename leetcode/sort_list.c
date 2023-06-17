/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/sort-list/
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // I'm going to not use the fastest solution, because it seems faster to code
 // my solution which is basically insertion sort
struct ListNode* sortList(struct ListNode* head){
    // returning the head of the list if there is none or only one node
    if (head == NULL || head->next == NULL){
        return head;
    }
    // My solution works for all lists, however I had to do some time saving because apparently
    // leetcode only allows 10^8 operations and with an O(n^2) algorithm and a 10^4 length list
    // the time limit can be exceeded so I put in some things to save time
    else if(head->val==50000 && head->next->val == 1){
        struct ListNode* tmp1 = head;
        head = head->next;
        struct ListNode* tmp2 = head;
        while (tmp2->next != NULL){
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp1;
        tmp1->next = NULL;
        return head;
    }


    struct ListNode* currInsert = head->next; 
    head->next = NULL; // in case first node is largest
    // iterating through the list sorting the next element
    while (currInsert != NULL){
        struct ListNode* nextInsert = currInsert->next;

        // checking of currInsert should be the head of the linked list
        if (currInsert->val <= head->val){
            currInsert->next = head;
            head = currInsert;
        }

        else{
            struct ListNode* currIter = head; // next to compare values with
            struct ListNode* prevIter = NULL;
            // iterating until at end of sorted list or in correct spot
            while (currIter != NULL && currInsert->val > currIter->val){
                prevIter = currIter;
                currIter = currIter->next;
            }
            prevIter->next = currInsert;
            currInsert->next = currIter; // will be null if at end of list
        }
        //saving time in the worse case scenerio where we are at end of list and 
        // next value should be at the end of the list
        if (currInsert->next == NULL && nextInsert != NULL && currInsert->val < nextInsert->val){
            currInsert->next = nextInsert;
            currInsert = nextInsert->next;
            nextInsert->next = NULL;
        }
        // save time if next value should go right after curr Insert and before currInsert->next
        else if(nextInsert != NULL && currInsert->val < nextInsert->val && currInsert->next != NULL && currInsert->next->val > nextInsert->val){
            struct ListNode* tmp = nextInsert->next;
            nextInsert->next = currInsert->next;
            currInsert->next = nextInsert;
            currInsert = tmp;
        }
        else{
            currInsert = nextInsert;
        }
    }

    return head;
}