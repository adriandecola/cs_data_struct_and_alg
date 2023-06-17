#ifndef STUDENTVECTOR //conditional preprocessor directive
#define STUDENTVECTOR //macro preprocessor directive 
//#pragma once - can also be used

#include<stdio.h>
#include<stdlib.h>

//write a function that returns whether array is full or not
typedef enum status{FALSE, TRUE} STATUS;
typedef enum outcome{FAILURE, SUCCESS} OUTCOME;

typedef struct student STUDENT;//forward declaration

struct student{
	
	int Capacity; //how much data we can keep
	int total; //no of items at a single point in time inside the array
	int * studentData; //will hold adress of the array.

};

//this function should allocate all memory associate with the STUDENT struccture
//should initialize all variables and return the address of the struct
//Make sure to catch any errors associated with malloc/calloc etc
STUDENT * allocate(void);

STATUS isFull(STUDENT * sGrades);

//function declaration
void printGrades(STUDENT * pGrades);

//function to push (insert) items to the array
OUTCOME  push(STUDENT ** pstudentGrades, int item);

void deallocate(STUDENT ** pStudentGrades);

#endif