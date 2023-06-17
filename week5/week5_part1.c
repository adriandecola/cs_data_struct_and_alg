/*
In this section, considering Prof Mwaura's class -
He needs to store grade data belonging to his student. He currently has 10 student.

Ref:

https://cplusplus.com/reference/cstdlib/

a) What is the difference between static and dynamic arrays ?
static - size of array is fixed while dynamic - array can be resized.

b) Where is the memory for static array and where is that for dynamic arrays?

c) Using the C language shows how both these arrays can be formulated for Prof Mwaura's class

d) What do we notice about the array specifically; if we are designing an array what items/parameters would we need?

*/
#include<stdio.h>  //Include preprocessor directive
#include<stdlib.h>

#define MAXNUM 10  //macro preprocessor directive

//write a function that returns whether array is full or not
typedef enum status{FALSE, TRUE} STATUS;

STATUS isFull(int i);

//function declaration
void printGrades(int * sGrades);


int main (void){

	//consider grades as integers - not always true- for static array
	int studentGrades[MAXNUM] = {0};

	int i = 0;

	while (isFull(i) == 0){
		studentGrades[i] = rand()%100;
		i = i + 1;
	}
	printGrades(studentGrades);


return 0;
}

//function definition
void printGrades(int * sGrades){
	int i = 0;
	while (isFull(i) == 0){
		printf("%d %lu \n", *(sGrades + i), (sGrades + i));
		i++;
	}

return;
}

STATUS isFull(int i) {
    if (i<MAXNUM){
        return FALSE;
      }

   return TRUE;
}
