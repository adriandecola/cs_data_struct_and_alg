// Adrian deCola
// April 6, 2023
//
// Compile this assignment with: gcc -Wall bst_tests.c -o tests
//
// This is a great assignment to practice debugging.
// First compile with debugging symbols
// Compile with: gcc -Wall -g bst_tests.c my_bst.c -o tests
// Run with: gdb ./tests --tui
// Then type 'start'
// Then type 'next' or 'n' and enter
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// You may add as many unit tests as you like here
// A few have been provided for your convenience.
// We will use our own test suite (i.e. replacing this file)
// in order to test your implementation from my_bst.

// Testing allocation
int unitTest1(){
    int result;
    bst_t * testBST = bst_create();
    if (testBST!=NULL){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;    
}

// Add and find a node
int unitTest2(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST,78);
    result = bst_find(testBST,78);
    bst_free(testBST);    
    return result;
}

// Sums the nodes in a BST
int unitTest3(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==5){ 
        return 1;
    }
    return 0;
}


// Testing summing 100 nodes
int unitTest4(){
	int result;
	bst_t* testBST = bst_create();
	
	int i;
	for (i = 0; i < 101; i ++){
		bst_add(testBST, i);
	}
	
	result = bst_sum(testBST);

	bst_free(testBST);
	if (result == 5050){
		return 1;
	}
	return 0;
}

// Testing finding a node in 100 when its there
int unitTest5(){
	int result;
	bst_t* testBST = bst_create();

	int i;
	for (i = 0; i < 101; i ++){
		bst_add(testBST, i);
	}
	
	result = bst_find(testBST, 77);
	bst_free(testBST);
	return result;
}

// Testing finding a node in 100 when its not there
int unitTest6(){
	int result;
	bst_t* testBST = bst_create();

	int i;
	for (i = 0; i < 101; i ++){
		bst_add(testBST, i);
	}

	result = bst_find(testBST, 112);
	bst_free(testBST);

	if (result == 0){
		return 1;
	}
	return 0;
}

// Testing the bst_empty funciton
int unitTest7(){
	int result;
	bst_t* testBST = bst_create();

	result = bst_empty(testBST);
	bst_free(testBST);
	
	return result;
}

// Testing the size of an empty BST
int unitTest8(){
	int result;
	bst_t* testBST = bst_create();

	result = bst_size(testBST);

	bst_free(testBST);
	if (result == 0){
		return 1;
	}
	return 0;
}

// Testing the size of a large BST
int unitTest9(){
	int result;
	bst_t* testBST = bst_create();

	int i;
	for (i = 0; i < 100; i ++){
		bst_add(testBST, 3*i+9);
	}

	result = bst_size(testBST);

	bst_free(testBST);
	if (result == 100){
		return 1;
	}
	return 0;
}






int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    NULL
};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter] != NULL){
		printf("========unitTest %d========\n",counter + 1);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
			testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
        counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);




	// Testing the print funciton in a much easier way, where I know what to expect
	// and don't have to write to other files, that took a very long time last time

	printf("\n\nTesting the bst_print() function: \n\n");

	
	//Testing printing an empty BST tree
	bst_t* testBST1 = bst_create(); 
	bst_print(testBST1, 0);

	// Testing printing in ascending order
	bst_t* testBST2 = bst_create();
	
	int i;
	for (i = -2; i < 11; i++){
		bst_add(testBST2, 3*i);
	}

	bst_print(testBST2, 0);
	// Testing printing in decending order
	bst_print(testBST2, 1);

	bst_free(testBST1);
	bst_free(testBST2);




    return 0;
}
