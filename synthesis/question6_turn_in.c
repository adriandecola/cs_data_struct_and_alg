/*
Author: Adrian deCola
Date: March 19, 2023
Purpose: This program if for quesiton 5a of the synthesis, which should do the following:

In class we created an opaque object for a type called VECTOR that had an internal structure 
called MY_VECTOR consisting of an integer size, an integer capacity, and an integer pointer 
data that held the address of the first element of a dynamic array of integers. Write a 
function called copyVECTOR that receives an opaque object (of type VECTOR) and returns the 
address of an exact copy of the passed opaque object upon success and NULL otherwise.
NOTE: Your function must return an opaque object.
*/

#include <stdio.h> 
#include <stdlib.h> 


//Function declaration
VECTOR copyVECTOR(VECTOR);




int main(void){
    /*I tested this in another file.
      NOTE: This fuction will not compile without the proper dependencies 
            It is just meant to answer a question in the synthesis. */

    return 0; 
}






VECTOR copyVECTOR(VECTOR vector){
    //Typecasting to hidden type
    MY_VECTOR* vector_to_copy = (MY_VECTOR*) vector;
    
    //returning NULL if the vector is NULL
    if (vector_to_copy == NULL){
        return NULL;
    }

    //Allocating space for the new vector
    MY_VECTOR* copied_vector = (MY_VECTOR*) malloc(sizeof(MY_VECTOR));
    if (copied_vector == NULL){
    return NULL;
    }

    //Copying size and capacity
    copied_vector->size = vector_to_copy->size;
    copied_vector->capacity = vector_to_copy->capacity;

    //Allocating space for the new vectors data
    copied_vector->data = (int*)malloc(sizeof(int) * copied_vector->capacity);
    if (copied_vector->data == NULL){
        return NULL;
    }

    //Copying the vector data
    int i;
    for (i = 0; i < copied_vector->size; i++){
        copied_vector->data[i] = vector_to_copy->data[i];
    }

    //Returning the copied vector as opaque object
    return (VECTOR) copied_vector;
}
