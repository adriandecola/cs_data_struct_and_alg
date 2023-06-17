#ifndef STACKFILE //conditional preprocessor directive
#define STACKFILE //macro preprocessor directive 
//#pragma once - can also be used

#include<stdio.h>
#include<stdlib.h>

//write a function that returns whether array is full or not
typedef enum status{FALSE, TRUE} STATUS;

typedef enum outcome{FAILURE, SUCCESS} OUTCOME;

//void *  - pointer to anything

typedef void * STACK; //opaque object - masking my struct

//this function should allocate all memory associate with the STUDENT struccture
//should initialize all variables and return the address of the struct
//Make sure to catch any errors associated with malloc/calloc etc
STACK allocate(void);

STATUS isFull(STACK pStack);

//function declaration
void printData(STACK pStack);

//function to push (insert) items to the array
OUTCOME  push(STACK* pStack, int item);

//removes what is on top of the stack
OUTCOME  pop(STACK* pStack);


//return what is ontop of the stack
int peek(STACK pStack);


void deallocate(STACK * pStack);

#endif