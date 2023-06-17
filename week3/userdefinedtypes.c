#include<stdio.h> 

/*
Objectives and Outcomes - User defined types
1) typedef
2) enum
3) struct

*/

/*
TASK1
Create an enum structure that stores student SUCCSESS or FAILURE.
You can call it STATUS;

Create a variable whose type is your enum type.

Create a function that on passing a student exam score returns to
main whether Success or failure (remember to use your enum) based on a score of 80;
Scores lower than 80 is Fail and Score higher than or equal to 80 is Success.

*/


typedef enum DayofWeek DAY;

enum DayofWeek{Sun, Mon, Tue, Wed, Thu, Fri, Sat};// enum is an integer type.

typedef enum status{FALSE, TRUE} STATUS;


int main(void){

//Lets say Grades are store as integers

typedef int GRADES;
typedef int AGE;

GRADES mygrade = 98;
AGE  studentAge = 19;
printf("%d \n", mygrade);


DAY hDay = Fri;

STATUS mystatus = FALSE;

printf("Which day: %d \n", hDay);
printf("Which Status: %d \n", mystatus);

return 0;

}
