/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/merge-two-sorted-lists
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int nodes_left(struct ListNode** next_to_insert, int listsSize);

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // keeping track of the next nodes that could be inserted
    struct ListNode** next_to_insert = (struct ListNode**)malloc(sizeof(struct ListNode*)*2);
    next_to_insert[0] = list1;
    next_to_insert[1] = list2;

    //for the first node to be inserted
    struct ListNode* head = NULL;
    struct ListNode* previous_node;
    int index_of_smallest_in_lists;

    //insert the nodes until there is none left to insert
    while (nodes_left(next_to_insert, 2) == 1){
        struct ListNode* smallest_node = NULL;
        int smallest_val = 999; // larger than the largest possible value
        int j;
        int index_of_smallest_in_lists;
        for (j = 0; j < 2; j++){
            if (next_to_insert[j] != NULL && smallest_val > next_to_insert[j]->val){
                smallest_node = next_to_insert[j];
                smallest_val = next_to_insert[j]->val;
                index_of_smallest_in_lists = j;
            }
        }
        // inserting the node
        if (head == NULL){
            head = smallest_node;
            previous_node = smallest_node;
        }
        else{
            previous_node->next = smallest_node;
            previous_node = smallest_node;
        }
        next_to_insert[index_of_smallest_in_lists] = next_to_insert[index_of_smallest_in_lists]->next;
    }
    free(next_to_insert);
    return head;
}


// will return 0 if there is no nodes left to insert and 1 if there is 
int nodes_left(struct ListNode** next_to_insert, int listsSize){
    int i;
    for (i = 0; i < listsSize; i++){
        if (next_to_insert[i] != NULL){
            return 1;
        }
    }
    // no nodes left to insert
    return 0;
}