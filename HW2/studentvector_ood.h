#ifndef STUDENTVECTOR //conditional preprocessor directive
#define STUDENTVECTOR //macro preprocessor directive 
//#pragma once - can also be used

#include<stdio.h>
#include<stdlib.h>

//write a function that returns whether array is full or not
typedef enum status{FALSE, TRUE} STATUS;
typedef enum outcome{FAILURE, SUCCESS} OUTCOME;

//void *  - pointer to anything

typedef void * MY_STUDENT; //opaque object - masking my struct

//this function should allocate all memory associate with the STUDENT struccture
//should initialize all variables and return the address of the struct
//Make sure to catch any errors associated with malloc/calloc etc
MY_STUDENT allocate(void);

/*
Create a function called deepCopy that performs a deep copy of the STRUCT student
this means it creates new memory blocks and copies all the data when it receives the STUDENT struct.
The function should receive an address of the opaque object and return an opaque object. 
Below please see the function declaration
*/
MY_STUDENT deepCopy(MY_STUDENT* currentStudent);



STATUS isFull(MY_STUDENT sGrades);

//function declaration
void printGrades(MY_STUDENT pGrades);

//function to push (insert) items to the array
OUTCOME  push(MY_STUDENT * pstudentGrades, int item);

void deallocate(MY_STUDENT * pStudentGrades);

#endif
