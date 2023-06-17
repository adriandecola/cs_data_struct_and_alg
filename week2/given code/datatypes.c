#include <stdio.h> //pre-processor directives
#include<stdbool.h>

int main (void){

//Variable is a named location in memory that stores a value.

long int year = 2023; // declare a variable and initilized

printf("The year is: %ld \n",year);
printf("How big is the size of variable year %lu: \n ", sizeof(year) );
print("This is cool \n");

//sizeof gives us size in terms of bytes. 
//How many bits make a byte -- 8 bits


/*
What forms would value take ---- Learning point (What are Data types in C)
- Boolean: a value that has only 2 values e.g Yes/ No, ON/OFF
(returns 1 for True and returns 0 for False)
*/

_Bool proposition = true; //variable declaration and initialization 

printf("Is this True is: %d \n",true);
printf("Size of proposition :%lu \n", sizeof (_Bool));

//characters - single letters or even numbers . Has to use single quotes to qualify

char middle_initial; //variable declaration

middle_initial = 'M'; //variable assignment 


printf("The character is: %c \n",middle_initial);
printf("Size of character :%lu \n", sizeof (char));
//String- a series of connected characters; it is an array of 
//characters that are terminated by a null character

char name[] = {'M', 'a', 'g', 'g','i','e','\0'};
printf("Size of the name variable is :%lu \n", sizeof (name));

//float is half the double
//to print a float use %f, how would I print double %lf
float grades[] = {2.3,4.5,6.7,8.0}

}




