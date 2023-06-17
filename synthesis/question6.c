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


//Defining structs
typedef struct vector_t{
  int* data;
  int size;
  int capacity;
} MY_VECTOR;

//opaque object
typedef void* VECTOR;

//Defining constructor
VECTOR makeVector (int initCapacity){
  MY_VECTOR* vector = (MY_VECTOR*)malloc(sizeof(MY_VECTOR));
  if ( vector == NULL ){
    return NULL;
  }

  //Allocate memory for our data array.
  vector->data = (int*)malloc(sizeof(int) * initCapacity); 
  vector->size = 0;
  vector->capacity = initCapacity;
  return (VECTOR) vector;
}


//Defining the deconstructor
void freeVector (VECTOR vector){
   MY_VECTOR* vector_= (MY_VECTOR*) vector;
  if (vector_ == NULL){
    return;
  }
  //First delete the data array, then delete the vector
  if (vector_->data != NULL){
    free(vector_->data);
  }
  free(vector_);
}



int resize(VECTOR vector_){
  MY_VECTOR* vector = (MY_VECTOR*) vector_;
  if (vector==NULL){
    return 0;
  }

  vector->capacity = vector->capacity * 2;
  int* newData = (int*)malloc(sizeof(int) * vector->capacity);
  //make sure it succeded and we had the memory
  if (newData == NULL || vector->data == NULL){
    return 0;
  }

  //copy data
  int i;
  for (i = 0; i < vector->size; i++){
    newData[i] = vector->data[i];
  }

  //deleting the old data
  free(vector->data);
  vector->data = newData;

  return 1;
}


int push_back(VECTOR vector_, int element){
  MY_VECTOR* vector = (MY_VECTOR*) vector_;
  if (vector == NULL){
    return 0; //indicates something went wrong
  }

  if (vector->data == NULL){
    return 0;
  }

  //check if we have to resize our array
  if  ( vector->size == vector->capacity){
    int resizeSuccess = resize(vector);
    if ( resizeSuccess == 0){
        return 0;
    }
  }

  //Lets append to the back of the array now
  vector->data[vector->size] = element;
  vector->size += 1;
  return 1;
}

int insert(VECTOR vector_, int pos, int element){
  MY_VECTOR* vector = (MY_VECTOR*) vector_;
  if (vector == NULL || pos < 0){
    return 0;
  }

  if ( pos == vector->size){
    push_back(vector, element);
    return 1; //I added this put it seems neccesary
  }

  //shift all the elements starting from the room
  if (vector->size == vector->capacity){
    int resizeSuccess = resize(vector);
    if ( resizeSuccess == 0){
        return 0;
    }
  }

  if (vector->data == NULL){
    return 0;
  }

  //shifting
  int i;
  for (i = vector->size - 1; i>=pos; i--){
    vector->data[i+1] = vector->data[i];
  }

  //put new element
  vector->data[pos] = element;
  vector->size += 1;

  return 1;
}

int push_front(VECTOR vector_, int element){
  MY_VECTOR* vector = (MY_VECTOR*) vector_;
  return insert(vector, 0, element);
}


void print(VECTOR vector_){
  MY_VECTOR* vector = (MY_VECTOR*) vector_;
  if (vector == NULL){
    return;
  }

  //   This one is seperate because if vector is NULL then vector->data will return
  // an error
  if (vector->data == NULL){
    return;
  }
	
  printf("SIZE: %d\n", vector->size);
  printf("CAPACITY %d\n", vector->capacity);

  int i;
  for ( i = 0 ; i < vector->size; i++){
    printf("%d ", vector->data[i]);
  }
  printf("\n");
}




















//Function declaration
VECTOR copyVECTOR(VECTOR);

int main(void){
    /*I tested this in another file.
      NOTE: This fuction will not compile without the proper dependencies 
            It is just meant to answer a question in the synthesis. */
    VECTOR vector = makeVector(10);
    push_front(vector, 10);
    push_front(vector, 9);
    push_front(vector, 14);
    push_front(vector, 3);
    push_front(vector, 7);
    push_front(vector, 11);
    push_front(vector, 100);
    push_front(vector, 6);
    print(vector);

    VECTOR copied_v = copyVECTOR(vector);

    freeVector(vector);
    print(copied_v);
    freeVector(copied_v);    

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
