#include<stdio.h> // include preprocessor directive

//int main (); ok but Prof doesn't like it
//int maind (void); //Prof likes this

//like this we can pass things to main

int main(int argc, char * argv[]){

  int age = 0; // variable declaration and initialization
              // formal specifier is %d or %i
              // the screen is called the standard output
              // standard input is the keyboard

  //printf("What is this %s \n", argv[]);

  printf("Enter your Age: ");
  scanf("%d",&age) //look for an integer on the screen
  // scanf reads from std input and stored the value
  //& is the address of the operator

  printf("You dont look as old as : %d \n", age)
  printf("Age is stored at: %lu", &age) // %l is a named location in memory
                                  //long unsigned number
                                  // the adress associated with the variable age

// char needs to be ''
// str is ""
  middleInitial = 'M';
  printf("Your middle initial is: %d \n", middleInitial)
  //this doesnt work because its reading it a decimal , its stored as a ascii number
  //lets change it
  middleInitial is 'P';
  printf("Your middle initial is now: %c \n", middleInitial)

  return 0;
}
*/
