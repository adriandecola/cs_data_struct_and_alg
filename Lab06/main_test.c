#include <stdio.h>
#include <stdlib.h>
#include "unit_tests.h"

int main(int argc, char* argv[]) {
	//creating a temporary directory for writing files to 
	//for testing output of print functions
	system("mkdir tmp");	
	Status (*tests[])(char*, int) = {
		test_init_default_returns_nonNULL,
		test_get_totalItems_on_init_default_returns_0,
		test_adecola_adding_one_item_increases_total_number_of_items_by_one,
		test_adecola_adding_three_to_seven_items_multiple_times,
		test_adecola_dequeue_decreases_total_number_of_items_by_one,	
		test_adecola_total_items_of_two_resizes_by_adding_fifteen_items,
		test_adecola_checking_print_front_item_on_one_element_list,
		test_adecola_checking_print_tail_item_on_one_element_list,
		test_adecola_checking_print_front_item_on_multielement_list,
		test_adecola_checking_print_tail_item_on_multielement_list,
		test_adecola_checking_print_front_item_after_dequeueing,
		test_adecola_checking_print_tail_after_dequeues,
		test_adecola_checking_print_front_item_after_fully_wrapping_around,
		test_adecola_checking_print_tail_item_after_fully_wrapping_around,
		test_adecola_checking_print_items,
		test_adecola_destroy_returns_null_pointer
	};
	
	int number_of_functions = sizeof(tests) / sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;
	for(i=0; i<number_of_functions; i++){
	
		if(tests[i](buffer, 500) == Failure){
			printf("FAILED: Test %d failed miserably\n", i+1);
			printf("\t%s\n", buffer);
			failure_count++;
		}
		else{
			printf("PASS: Test %d passed\n", i+1);
			printf("\t%s\n", buffer);
		success_count++;
		}
	}
	printf("Total number of tests: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count,number_of_functions,failure_count,number_of_functions);
	
	//deleting the temporary directory and its files
	system("rm -r tmp");
	return 0;
	
}
