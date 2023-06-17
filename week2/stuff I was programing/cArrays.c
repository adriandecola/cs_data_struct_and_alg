#include<stdio.h>

/*
A function that returns the highest exam score
*/

double getHighestScore(double scores[]);


int main(void){
  //An array is a collection of homogenious types
  //An array is a continous block in memory

  double stdGrades[] = {78.1, 98.2, 14.7, 89.3};//one way to work with this
  //student types is an array of doubles


  printf("How many bytes in StdGrades %lu \n", sizeof (stdGrades));
  printf("How many bytes in StdGrades[0] %lu \n", sizeof (stdGrades[0]));
  int size = (sizeof stdGrades) / (sizeof stdGrades[0]);

  printf("Ok how many do we have to do: %d \n", size);

  //Another way:
  // you either need to initialize it or make it an actual size
  double myStdGrades[5] = {78, 89, 52, 42, 100}; //declaration and initialization

  double myStudentGrades[10]; //declared and no initialization

  int i = 0; //c is indexed starting at zero
  //populate array using a for loop
  printf("Enter the Grades: \n");
  for (i=0; i<10; i++){
    scanf("%lf", &myStudentGrades[i]);
  }
  printf("Printing Grades \n");
  for (i=0; i<10; i++){
    printf("Value is: %lf and Address is: %lu and the Address is: %lu \n", myStudentGrades[i], &myStudentGrades[i], myStudentGrades + i);
  }
  //how we expect an array to work: it prints the first bit in memory location
  //there is memory address mathe here were printing from the start starting at 0
  printf("What is the name of Array %lu \n", myStudentGrades);
  //the name of the array refers to the address of the first item

  double highScoree = getHighestScore(myStudentGrades);

  return 0;
}
//Always pass the size of the Array to know the size of the array
double getHighestScore(double scores[], int size){

  double highscore = 0.0;

  //How to determine how big the array is
  /* THis was from showing that it doesnt work why not
  int size = sizeof scores / sizeof scores[0];
  */
  printf("Size is: %d \n", size);

  for (int i=0; i<size; i++){
    if (scores[i]>highscore){
      highscore = scores[i];
    }
  }
  return highscore;
}
