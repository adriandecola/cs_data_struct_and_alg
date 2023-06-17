#include <stdio.h> //for printing
#include <stdlib.h> //for memory allocating






//Defining structs
typedef struct vector{
  int* data;
  int size;
  int capacity;
}vector_t;







//Defining constructor
vector_t* makeVector (int initCapacity){
  vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
  if ( vector == NULL ){
    return NULL;
  }

  //Allocate memory for our data array.
  vector->data = (int*)malloc(sizeof(int) * initCapacity); vector->size = 0;
  vector->size = 0;
  vector->capacity = initCapacity;
  return vector;
}






//Defining the deconstructor
void freeVector (vector_t* vector){
  if (vector == NULL){
    return;
  }
  //First delete the data array, then delete the vector
  if (vector->data != NULL){
    free(vector->data);
  }
  free(vector);
}





int resize(vector_t* vector){
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


int push_back(vector_t* vector, int element){
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


int insert(vector_t* vector, int pos, int element){
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




int push_front(vector_t* vector, int element){
  return insert(vector, 0, element);
}






void print(vector_t* vector){
  if (vector == NULL){
    return;
  }

  //   This one is seperate because if vector is NULL then vector->data will return
  // an error
  if (vector->data == NULL){
    return;
  }

  int i;
  for ( i = 0 ; i < vector->size; i++){
    printf("%d ", vector->data[i]);
  }
  printf("\n");
}




int main(){
  //Construct vector on the heap
  vector_t* vector = makeVector(2);

  push_back(vector, 2);
  push_back(vector, 4);
  push_back(vector, 6);
  push_back(vector, 8);
  push_back(vector, 9);

  print(vector);

  push_front(vector, 1);
  print(vector);
  push_front(vector, 0);
  print(vector);
  insert(vector, 3, 3);
  print(vector);
  insert(vector, 5, 5);
  print(vector);
  insert(vector, vector->size, 10);
  print(vector);

  //Delete vector from the heap
  freeVector(vector);
  return 0;
}
