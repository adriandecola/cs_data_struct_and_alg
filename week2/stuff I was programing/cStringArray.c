#include<stdio.h>
#include<cstring.c>//actual file to do this
//cplusplus.com -> this is a reference cite

int main(void){
  //An array is a collection of homogenious types
  //An array is a continous block in memory
  //The name of array refers to address of the first element in the array

  char lName[]={'P', 'E', 'T', 'E', 'R', '\0'};
  char fName[6];

  printf("Some Name \n");

  for(int i =0; i<6; i++){
    scanf("%c", &fName[i]);
    clearBuffer(); need to put this funciton in
  }

  for(int i =0; i<6; i++){
    printf("%c \n", fName[i]);
  }

  char mName[10]; //an array of charavters termination in '\0'
  // we know that we want to read a string
  printf("Enter Name: \n");
  scanf("%s", mName);
  printf("Entered name is: %s \n", mName);

  return 0;
}

//This is from the clearBuffer()
//Function Implementation

/*
Create a while loop that keeps reading until we encounter return character - \n
void function in a non value returning function
*/

void clearBuffer(void){

  char whatsinBuffer;
  scanf ("%c", &whatsinBuffer);
  while (whatsinBuffer != 'n'){
    printf("\t Buffer has: %c \n", whatsinBuffer);
    scanf("%c", &whatsinBuffer);
}
