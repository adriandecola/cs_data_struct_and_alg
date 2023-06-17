#include <stdio.h>
#include <stdlib.h>

/* CS 5008 Lecture 4* * in-class exercise, pointer fun*/
/* main
determine what is printed and draw pictures to show pointers and data
assume memory address of myArray is 1000
assume memory address of anArray is 2000
assume memory address of name is 3000
*/
int main(void) {
  int my_array[] = {1, 5, 10, 15};
  int *an_array[] = { &my_array[2], &my_array[0] };
  char name[] = "MwauraJ";

  int *p = my_array;
  char *pc =name;
  int **pp = &an_array[0];

  (*p)++;
  printf("Value of *p: %d\n", *p);

  p++;
  printf("Value of p: %p\n", p);

  p++;
  *p = 30;
  printf("Value of my_array[2]: %d\n", my_array[2]);

  // draw picture for activity
  printf("DRAW FIRST DATA PICTURE\n\n");

  pp++;
  printf("Value of *pp: %p\n", *pp);
  printf("Value of **pp: %d\n", **pp);

  pp--;
  (*p)++;
  printf("Values in an_array: %p, %p\n", an_array[0], an_array[1]);
  printf("Deferencing values in an_array: %d, %d\n", *an_array[0], *an_array[1]);

  // draw picture for activity
  printf("DRAW SECOND DATA PICTURE\n\n");

  printf("Value of *pc: %c\n", *pc);

  (*pc)++;
  printf("Value of *pc: %c\n", *pc);

  pc++;
  printf("Value of *pc: %c\n", *pc);

  printf("DRAW THIRD DATA PICTURE\n\n");
  return EXIT_SUCCESS;
}
