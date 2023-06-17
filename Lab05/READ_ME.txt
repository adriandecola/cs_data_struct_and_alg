BELOW INCLUDES THE OUTPUT OF MY PROGRAM USING VALGRIND AND SHOWS THERE IS NO MEMORY LEAKS


-bash-4.2$ valgrind ./link_list_output 
==64221== Memcheck, a memory error detector
==64221== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==64221== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==64221== Command: ./link_list_output
==64221== 
Printing lst1: 
Linked list contents: 4 5 7 8 16 

Printing lst2: 
Linked list contents: 2 4 6 7 8 18 21 25 

lst1 length: 5
lst1 length (rec): 5

lst2 length: 8
lst2 length (rec): 8

Printing lst3, a copy of lst1: 
Linked list contents: 4 5 7 8 16 

Printing mergedList: 
Linked list contents: 2 4 4 5 6 7 7 8 8 16 18 21 25 
mergedList length: 13

Part 3: We must free list->next before freeing list 
because if we do not do so we will lose the only 
pointer we have to list->next, will not be able to 
free it, and have a memeory leak. 

Part 4: The running time of copyList is O(N).

Part5: The recurisve calls to mergeList eventually reach
a base case because they keep mergeing the two list 
without the smaller value node of one of the list. 
Eventually one of the lists will run out of nodes 
and will only contain a NULL value. 
Supposing both lists had 200 items, in the worst 
case scenerio we go keep merging the list until 
we are left with one of the lists with length 0 and 
the other with length 1. In this case we made 400 
calls to mergeList as each call we shorten one of  
the list by one and we called the function once in 
the beginning. 
==64221== 
==64221== HEAP SUMMARY:
==64221==     in use at exit: 0 bytes in 0 blocks
==64221==   total heap usage: 31 allocs, 31 frees, 496 bytes allocated
==64221== 
==64221== All heap blocks were freed -- no leaks are possible
==64221== 
==64221== For lists of detected and suppressed errors, rerun with: -s
==64221== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
