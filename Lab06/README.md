----------------------------------------- NOTE TO SELF --------------------------------------
I had make the test executable a dependency in the queue executable or it wouldn't be created.
I could have also had a make all function and put both executables under all but this way
seemed easier and faster for lots of testing. 
------------------------------------------- ANSWERS  ----------------------------------------
Part 1
------
	2. Right after 14 is enqueued I think the list looks like this:
	  
	  Front of Queue-> 4, 7, 20, 40, 50, 6, 14 <-Back of Queue

	4. My prediction was correct. 

	5. 
	  a. 0 
	  b. 3
	  c. 2
	  d. 5

	9. These preproccessor directives make sure you don't accidentely copy the function 
	   declarations and typedefs twice, by only copying the file to the head of the file,
	   and defining QUEUE_H, if QUEUE_H is not defined. 





Here is the valgrind result of queue_output:


==263121== Memcheck, a memory error detector
==263121== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==263121== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==263121== Command: ./queue_output
==263121== 
Front is: 5 
Tail is: 4 
Front is: 5 
Tail is: 7 
Front is: 4 
Tail is: 20 
Front-> 4  7  20  40  50  6  14 <-Back 
****************
Front is: 7 
Tail is: 14 
==263121== 
==263121== HEAP SUMMARY:
==263121==     in use at exit: 0 bytes in 0 blocks
==263121==   total heap usage: 3 allocs, 3 frees, 108 bytes allocated
==263121== 
==263121== All heap blocks were freed -- no leaks are possible
==263121== 
==263121== For lists of detected and suppressed errors, rerun with: -s
==263121== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


Here is the valgrind result on unit_test:

==264891== Memcheck, a memory error detector
==264891== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==264891== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==264891== Command: ./unit_test
==264891== 
PASS: Test 1 passed
        test_init_default_returns_nonNULL

PASS: Test 2 passed
        test_get_size_on_init_default_returns_0

PASS: Test 3 passed
        test_adecola_adding_one_item_increases_total_number_of_items_by_one

PASS: Test 4 passed
        test_adecola_adding_three_to_seven_items_multiple_times

PASS: Test 5 passed
        test_adecola_adding_three_to_seven_items_multiple_times

PASS: Test 6 passed
        test_adecola_testing_items_of_two_resizes_by_addding_fifteen_items

PASS: Test 7 passed
        test_adecola_checking_print_front_item_on_one_element_list

PASS: Test 8 passed
        test_adecola_checking_print_tail_item_on_one_element_list

PASS: Test 9 passed
        test_adecola_checking_print_front_item_on_multielement_list

PASS: Test 10 passed
        test_adecola_checking_print_tail_item_on_multielement_list

PASS: Test 11 passed
        test_adecola_checking_print_front_item_after_dequeueing

PASS: Test 12 passed
        test_adecola_checking_print_tail_item_after_dequeues

PASS: Test 13 passed
        test_adecola_checking_print_front_item_after_fully_wrapping_around

PASS: Test 14 passed
        test_adecola_checking_print_tail_item_after_fully_wrapping_around

PASS: Test 15 passed
        test_adecola_checking_print_items

Total number of tests: 15
15/15 Pass, 0/15 Failure
==264891== 
==264891== HEAP SUMMARY:
==264891==     in use at exit: 0 bytes in 0 blocks
==264891==   total heap usage: 149 allocs, 149 frees, 14,976 bytes allocated
==264891== 
==264891== All heap blocks were freed -- no leaks are possible
==264891== 
==264891== For lists of detected and suppressed errors, rerun with: -s
==264891== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


