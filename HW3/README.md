BELOW IS THE RESULTS OF MY HOMEWORK SHOWN USING VALGRIND.
EVERYTHING WORKS AS EXPECTED.
-----------------------------------------------------------------------------
-bash-4.2$ valgrind ./stack_output 
==151216== Memcheck, a memory error detector
==151216== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==151216== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==151216== Command: ./stack_output
==151216== 
21 
49 
92 
86 
35 
93 
15 
77 
86 
83 
Top is 49: 
49 
92 
86 
35 
93 
15 
77 
86 
83 
==151216== 
==151216== HEAP SUMMARY:
==151216==     in use at exit: 0 bytes in 0 blocks
==151216==   total heap usage: 11 allocs, 11 frees, 168 bytes allocated
==151216== 
==151216== All heap blocks were freed -- no leaks are possible
==151216== 
==151216== For lists of detected and suppressed errors, rerun with: -s
==151216== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
