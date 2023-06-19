All of my tests passed and my print function worked as expected.


Here is the  result of the "valgrind ./tests":
----------------------------------------------

==120753== Memcheck, a memory error detector
==120753== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==120753== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==120753== Command: ./tests
==120753== 
========unitTest 1========
passed test
========unitTest 2========
passed test
========unitTest 3========
passed test
========unitTest 4========
passed test
========unitTest 5========
passed test
========unitTest 6========
passed test
========unitTest 7========
passed test
========unitTest 8========
passed test
========unitTest 9========
passed test
9 of 9 tests passed


Testing the bst_print() function: 

Printing the BST in ascending order: 
Printing the BST in ascending order: -6, -3, 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 
Printing the BST in decending order: 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, -3, -6, 
==120753== 
==120753== HEAP SUMMARY:
==120753==     in use at exit: 0 bytes in 0 blocks
==120753==   total heap usage: 429 allocs, 429 frees, 13,552 bytes allocated
==120753== 
==120753== All heap blocks were freed -- no leaks are possible
==120753== 
==120753== For lists of detected and suppressed errors, rerun with: -s
==120753== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
