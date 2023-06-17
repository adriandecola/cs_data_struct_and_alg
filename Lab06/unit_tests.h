#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "queue.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_totalItems_on_init_default_returns_0(char* buffer, int length);

Status test_adecola_adding_one_item_increases_total_number_of_items_by_one(char* buffer, int length);

Status test_adecola_adding_three_to_seven_items_multiple_times(char* buffer, int length);

Status test_adecola_dequeue_decreases_total_number_of_items_by_one(char* buffer, int length);

Status test_adecola_total_items_of_two_resizes_by_adding_fifteen_items(char* buffer, int length);

Status test_adecola_checking_print_front_item_on_one_element_list(char* buffer, int length);

Status test_adecola_checking_print_tail_item_on_one_element_list(char* buffer, int length);

Status test_adecola_checking_print_front_item_on_multielement_list(char* buffer, int length);

Status test_adecola_checking_print_tail_item_on_multielement_list(char* buffer, int length);

Status test_adecola_checking_print_front_item_after_dequeueing(char* buffer, int length);

Status test_adecola_checking_print_tail_after_dequeues(char* buffer, int length);

Status test_adecola_checking_print_front_item_after_fully_wrapping_around(char* buffer, int length);

Status test_adecola_checking_print_tail_item_after_fully_wrapping_around(char* buffer, int length);

Status test_adecola_checking_print_items(char* buffer, int length);

Status test_adecola_destroy_returns_null_pointer(char* buffer, int length);

#endif
