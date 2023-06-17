Everything works as expected and I tested functions multiple times in my main file.
Here is the result of running valgrind on my output to show there are no memory leaks:
--------------------------------------------------------------------------------------
-bash-4.2$ valgrind ./priority_queue_output 
==176104== Memcheck, a memory error detector
==176104== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==176104== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==176104== Command: ./priority_queue_output
==176104== 
If there is no other print statments and no memory leaks with valgrind,
then everything works as expected. 
==176104== 
==176104== HEAP SUMMARY:
==176104==     in use at exit: 0 bytes in 0 blocks
==176104==   total heap usage: 3 allocs, 3 frees, 256 bytes allocated
==176104== 
==176104== All heap blocks were freed -- no leaks are possible
==176104== 
==176104== For lists of detected and suppressed errors, rerun with: -s
==176104== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

