#include "unit_tests.h"
#include <stdlib.h>

Status test_init_default_returns_nonNULL(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	
	if(hQueue == NULL){
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
		"my_string_init_default returns NULL", length);
		return Failure;
	}
	else{
		queue_destroy(&hQueue);
		strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
		return Success;
	}
}

Status test_get_totalItems_on_init_default_returns_0(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	Status status;
	
	if(queue_getTotalItems(hQueue) != 0){
	status = Failure;
	printf("Expected a size of 0 but got %d\n", queue_getTotalItems(hQueue));
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	"Did not receive 0 from get_size after init_default\n", length);
   }
	else
	{
	status = Success;
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_adecola_adding_one_item_increases_total_number_of_items_by_one(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	Status status;

	queue_enqueue(hQueue, 7);
	
	if (queue_getTotalItems(hQueue) != 1){
		status = Failure;
		printf("Expected one item but got %d\n", queue_getTotalItems(hQueue));
		strncpy(buffer, "test_adecola_adding_one_item_increases_total_number_of_items_by_one\n"
		"Did not get a total number of items of one. \n", length);	
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_adding_one_item_increases_total_number_of_items_by_one\n"
		, length);
	}
	queue_destroy(&hQueue);
	return status;
}


Status test_adecola_adding_three_to_seven_items_multiple_times(char* buffer, int length){
	Status status;
	int i;
	for (i=0; i<20; i++){
	        QUEUE hQueue = NULL;
       		hQueue = queue_init_default();

		int num_items = rand()%5 + 3;
		int j;
		for (j = 0; j<num_items; j++){
			queue_enqueue(hQueue, rand()%100);		
		}

		if (queue_getTotalItems(hQueue) != num_items){
			status = Failure;
			printf("Expected to add %d items but got %d\n", num_items, queue_getTotalItems(hQueue));
			strncpy(buffer, "test_adecola_adding_three_to_seven_items_multiple_times \n"
			"Did not get the correnct total number of items. \n", length); 
			queue_destroy(&hQueue);
			return status;
		}
		else{
			queue_destroy(&hQueue);
		}
	}
	status = Success;
	strncpy(buffer, "test_adecola_adding_three_to_seven_items_multiple_times\n", length);
	return status;
}




Status test_adecola_dequeue_decreases_total_number_of_items_by_one(char* buffer, int length){
	Status status;
	int i;
        for (i=0; i<20; i++){
        	QUEUE hQueue = NULL;
        	hQueue = queue_init_default();
                
		int num_items = rand()%5 + 3;
                int j;
                for (j = 0; j< num_items; j++){
                        queue_enqueue(hQueue, rand()%100);
                }
		queue_dequeue(hQueue);		

                if (queue_getTotalItems(hQueue) != num_items - 1){
                        status = Failure;
                        printf("Expected to add %d items but got %d\n", num_items, queue_getTotalItems(hQueue));
                        strncpy(buffer, "test_adecola_adding_three_to_seven_items_multiple_times \n"
                        "Did not get the correnct total number of items. \n", length);
			queue_destroy(&hQueue);
                        return status;
                }
		else{
			queue_destroy(&hQueue);
		}
        }
        status = Success;
        strncpy(buffer, "test_adecola_adding_three_to_seven_items_multiple_times\n", length);
        return status;
}

Status test_adecola_testing_total_items_of_a_simple_resize_by_addding_eight_items(char* buffer, int length){
	QUEUE hQueue = NULL;
        hQueue = queue_init_default();
        Status status;

	int i;
	for (i = 0; i < 8; i++){
		queue_enqueue(hQueue, rand()%100);
	}

        if ((queue_getTotalItems(hQueue) != 8)){
                status = Failure;
                printf("Expected eight item but got %d\n", queue_getTotalItems(hQueue));
                strncpy(buffer, "test_adecola_testing_total_items_of_a_simple_resize_by_addding_eight_items\n"
                "Did not get a total number of items of eight. \n", length);
        }
        else{
                status = Success;
                strncpy(buffer, "test_adecola_testing_total_items_of_a_simple_resize_by_addding_eight_items\n"
                , length);
        }	
        queue_destroy(&hQueue);
        return status;
}

Status test_adecola_total_items_of_two_resizes_by_adding_fifteen_items(char* buffer, int length){
        QUEUE hQueue = NULL;
        hQueue = queue_init_default();
        Status status;

        int i;
        for (i = 0; i < 15; i++){
                queue_enqueue(hQueue, rand()%100);
        }

        if ((queue_getTotalItems(hQueue) != 15)){
                status = Failure;
                printf("Expected eight item but got %d\n", queue_getTotalItems(hQueue));
                strncpy(buffer, "test_adecola_total_items_of_two__resizes_by_addding_fifteen_items\n"
                "Did not get a total number of items of fifteen. \n", length);
        }
        else{
                status = Success;
                strncpy(buffer, "test_adecola_testing_items_of_two_resizes_by_addding_fifteen_items\n"
                , length);
        }
        queue_destroy(&hQueue);
        return status;
}


Status test_adecola_checking_print_front_item_on_one_element_list(char* buffer, int length){
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"queue_enqueue(hQueue, 7); \n"
					"printFrontItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the front item
	int frontItem;
	sscanf(output_line, "Front is: %d", &frontItem);

	//closing the file
	fclose(fp);

	//checking the front item is 7
	if (frontItem != 7){
		status = Failure;
		printf("Expected front item of 7 but got %d\n", frontItem);
		strncpy(buffer, "test_adecola_checking_print_front_item_on_one_element_list\n"
			"Did not get expected front item of 7", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_front_item_on_one_element_list\n"
		, length);
	}					

	return status;	
}


Status test_adecola_checking_print_tail_item_on_one_element_list(char* buffer, int length){
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"queue_enqueue(hQueue, 7); \n"
					"printTailItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the tail item
	int tailItem;
	sscanf(output_line, "Tail is: %d", &tailItem);

	//closing the file
	fclose(fp);

	//checking the tail item is 7 
	if (tailItem != 7){
		status = Failure;
		printf("Expected tail item of 7 but got %d\n", tailItem);
		strncpy(buffer, "test_adecola_checking_print_tail_item_on_one_element_list\n"
			"Did not get expected tail item of 7", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_tail_item_on_one_element_list\n"
		, length);
	}					

	return status;	
}





Status test_adecola_checking_print_front_item_on_multielement_list(char* buffer, int length){
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"printFrontItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the front item
	int frontItem;
	sscanf(output_line, "Front is: %d", &frontItem);

	//closing the file
	fclose(fp);

	//checking the front item is 2
	if (frontItem != 2){
		status = Failure;
		printf("Expected front item of 2 but got %d\n", frontItem);
		strncpy(buffer, "test_adecola_checking_print_front_item_on_multielement_list\n"
			"Did not get expected front item of 2", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_front_item_on_multielement_list\n"
		, length);
	}					

	return status;	
}









Status test_adecola_checking_print_tail_item_on_multielement_list(char* buffer, int length){
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"printTailItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the tail item
	int tailItem;
	sscanf(output_line, "Tail is: %d", &tailItem);

	//closing the file
	fclose(fp);

	//checking the tail item is 11 
	if (tailItem != 11){
		status = Failure;
		printf("Expected tail item of 11 but got %d\n", tailItem);
		strncpy(buffer, "test_adecola_checking_print_tail_item_on_multielement_list\n"
			"Did not get expected tail item of 11", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_tail_item_on_multielement_list\n"
		, length);
	}					

	return status;	
}







Status test_adecola_checking_print_front_item_after_dequeueing(char* buffer, int length){
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"queue_dequeue(hQueue);\n"
					"printFrontItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the front item
	int frontItem;
	sscanf(output_line, "Front is: %d", &frontItem);

	//closing the file
	fclose(fp);

	//checking the front item is 3
	if (frontItem != 3){
		status = Failure;
		printf("Expected front item of 3 but got %d\n", frontItem);
		strncpy(buffer, "test_adecola_checking_print_front_item_after_dequeueing\n"
			"Did not get expected front item of 3", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_front_item_after_dequeueing\n"
		, length);
	}					

	return status;	
}



Status test_adecola_checking_print_tail_after_dequeues(char* buffer, int length){
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"queue_dequeue(hQueue);\n"
					"queue_dequeue(hQueue);\n"
					"queue_dequeue(hQueue);\n"
					"printTailItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the tail item
	int tailItem;
	sscanf(output_line, "Tail is: %d", &tailItem);

	//closing the file 
	fclose(fp);

	//checking the tail item is 11
	if (tailItem != 11){
		status = Failure;
		printf("Expected tail item of 11 but got %d\n", tailItem);
		strncpy(buffer, "test_adecola_checking_print_tail_item_after_dequeues\n"
			"Did not get expected tail item of 11", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_tail_item_after_dequeues\n"
		, length);
	}					

	return status;	
}


Status test_adecola_checking_print_front_item_after_fully_wrapping_around(char* buffer, int length){
	//This function checks after may queues and dequeues, when we have wrapped fully around the 
	//underlying array, if the front item pointer is still correct, to check its logic is correct
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i=0; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"for (int j=0; j < 8; j++){ \n"
					"queue_dequeue(hQueue); \n"
					"}\n"
					"for (int k=0; k < 3; k++){ \n"
					"queue_enqueue(hQueue, k+17); \n"
					"}\n"
					"for (int s=0; s < 3; s++){ \n"
					"queue_dequeue(hQueue); \n"
					"}\n"
					"printFrontItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the front item
	int frontItem;
	sscanf(output_line, "Front is: %d", &frontItem);

	//closing the file
	fclose(fp);

	//checking the front item is 18
	if (frontItem != 18){
		status = Failure;
		printf("Expected front item of 18 but got %d\n", frontItem);
		strncpy(buffer, "test_adecola_checking_print_front_item_after_fully_wrapping_around\n"
			"Did not get expected front item of 18", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_front_item_after_fully_wrapping_around\n"
		, length);
	}					

	return status;	
}





Status test_adecola_checking_print_tail_item_after_fully_wrapping_around(char* buffer, int length){
	//This function checks after may queues and dequeues, when we have wrapped fully around the 
	//underlying array, if the tail item pointer is still correct, to check its logic is correct
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i=0; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"for (int j=0; j < 8; j++){ \n"
					"queue_dequeue(hQueue); \n"
					"}\n"
					"for (int k=0; k < 4; k++){ \n"
					"queue_enqueue(hQueue, k+17); \n"
					"}\n"
					"for (int s=0; s < 3; s++){ \n"
					"queue_dequeue(hQueue); \n"
					"}\n"
					"printTailItem(hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the tail item
	int tailItem;
	sscanf(output_line, "Tail is: %d", &tailItem);

	//closing the file  
	fclose(fp);

	//checking the tail item is 20
	if (tailItem != 20){
		status = Failure;
		printf("Expected tail item of 20 but got %d\n", tailItem);
		strncpy(buffer, "test_adecola_checking_print_tail_item_after_fully_wrapping_around\n"
			"Did not get expected tail item of 20", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_tail_item_after_fully_wrapping_around\n"
		, length);
	}					

	return status;	
}


Status test_adecola_checking_print_items(char* buffer, int length){
	//This function checks after may queues and dequeues, when we have wrapped fully around the 
	//underlying array, if the print items works as expected, since we have rigorously tested 
	//print front and print tail this test should suffice as it relies heavily on keeping track
	//of the head and tail
	Status status;

	//this line creates a sting which is the file that runs the command that prints
	//the front item of a one element list 
	//this file remainds hidden so its ok to include hidden implementation
	//so we don't have to compile so much
	const char* file_contents = "#include <stdio.h>\n"
					"#include <stdlib.h>\n"
					"#include \"../queue.h\"\n"
					"#include \"../queue.c\"\n"
					"int main(void){\n"
					"QUEUE hQueue = NULL;\n"
					"hQueue = queue_init_default();\n"
					"for (int i=0; i < 10; i++){ \n"
					"queue_enqueue(hQueue, i + 2); \n"
					"}\n"
					"for (int j=0; j < 8; j++){ \n"
					"queue_dequeue(hQueue); \n"
					"}\n"
					"for (int k=0; k < 4; k++){ \n"
					"queue_enqueue(hQueue, k+27); \n"
					"}\n"
					"for (int s=0; s < 3; s++){ \n"
					"queue_dequeue(hQueue); \n"
					"}\n"
					"printItems(&hQueue); \n"
					"queue_destroy(&hQueue);\n"
					"return 1; \n"
					"}\n";
	//writing this string to a file in tmp/ directory
	const char* fname = "file_to_create_output.c";
	FILE* pFile = fopen(fname, "w" );
	if (pFile == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	fputs(file_contents, pFile);
	fclose(pFile);
	system("mv file_to_create_output.c tmp");

	//executing the file we wrote
	system("gcc -Wall --std=c99 tmp/file_to_create_output.c -o tmp/output");
	//reading the output of the file
	system("./tmp/output > tmp/output.txt");
	
	//reading the output file
	const char* output_file = "tmp/output.txt";
	FILE* fp = fopen(output_file, "r");
	if (fp == NULL){
		printf("Couldn't open file \n");
		return Failure;
	}
	char output_line[100];

	fgets(output_line, sizeof(output_line), fp);  // read the  line of file into a string
		
	//getting the 3 items that should be in the list
	int firstItem;
	int secondItem;
	int thirdItem;
	sscanf(output_line, "Front-> %d  %d  %d", &firstItem, &secondItem, &thirdItem);

	//closing the file  
	fclose(fp);

	//checking the items are 28, 29, 30 in order
	if (firstItem != 28){
		status = Failure;
		printf("Expected first item of 28 but got %d\n", firstItem);
		strncpy(buffer, "test_adecola_checking_print_items\n"
			"Did not get expected first item of 28", length);
	}
	else if (secondItem != 29){ 
		status = Failure;
		printf("Expected second item of 29 but got %d\n", secondItem);
		strncpy(buffer, "test_adecola_checking_print_items\n"
			"Did not get expected second item of 29", length);
	}
	else if (thirdItem != 30){ 
		status = Failure;
		printf("Expected third item of 30 but got %d\n", thirdItem);
		strncpy(buffer, "test_adecola_checking_print_items\n"
			"Did not get expected third item of 30", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_checking_print_items\n"
		, length);
	}					

	return status;	
}


Status test_adecola_destroy_returns_null_pointer(char* buffer, int length){
	Status status;
	QUEUE hQueue = queue_init_default();

	queue_destroy(&hQueue);

	if (hQueue != NULL){
		status = Failure;
		printf("Expected hQueue to be NULL\n");
		strncpy(buffer, "test_adecola_destroy_returns_null_pointer\n"
			"Did not get expected hQueue of NULL", length);
	}
	else{
		status = Success;
		strncpy(buffer, "test_adecola_destroy_returns_null_pointer\n"
		, length);
	}
	return status;
}



