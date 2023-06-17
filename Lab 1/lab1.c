#include<stdio.h> //Preprocessor directive includes standard input and output

///////////////////////////
// Function Declarations //
///////////////////////////
void inputLastName(char studentLastName[]);
int inputAge(void);
float input_gpa(void);
float inputFinalExamScore(void);
char determineGrade(float finalExamScore);
void printData(char studentLastName[], int studentAge, float gpa, float finalExamScore);


int main(void) {
  //Collecting the student's last name
  char studentLastName[15];
  inputLastName(studentLastName);

  //Collecting the student's age
  int studentAge;
  studentAge = inputAge();

  //Collecting the student's GPA
  float gpa;
  gpa = input_gpa();

  //Collecting the student's final exam score
  float finalExamScore;
  finalExamScore = inputFinalExamScore();

  //Determining the student's grade as we use it in Task 2
  char grade = determineGrade(finalExamScore);

  //Printing the data for Task 1
  printData(studentLastName, studentAge, gpa, finalExamScore);

  //////////////////////////// Task 2 /////////////////////////////

  ///Printing the addresses of our variable///
  printf("Address of studentLastName variable: %p \n", studentLastName);
  printf("Address of studentAge variable: %p \n", &studentAge);
  printf("Address of gpa variable: %p \n", &gpa);
  printf("Address of finalExamScore variable: %p \n", &finalExamScore);
  printf("Address of grade variable: %p \n \n", &grade);

  ///Storing the size of our variables///
  int size_last_name = sizeof studentLastName;
  int size_age = sizeof studentAge;
  int size_gpa = sizeof gpa;
  int size_exam_score = sizeof finalExamScore;
  int size_grade = sizeof grade;

  ///Printing the size of our variables///
  printf("Size of studentLastName variable: %d bytes \n", size_last_name);
  printf("Size of studentAge variable: %d bytes \n", size_age);
  printf("Size of gpa variable: %d bytes \n", size_gpa);
  printf("Size of finalExamScore variable: %d bytes \n", size_exam_score);
  printf("Size of grade variable: %d bytes \n \n", size_grade);

  ///Printing the first and last byte address of studentLastName
  int elements_std_last_name = sizeof(studentLastName)/sizeof(studentLastName[0]);
  //we already knew this was 15 but good for practive

  printf("First byte address of studentLastName: %p \n", studentLastName);
  //Printing the last character address of studentLastName (a char = a byte)
  printf("Last byte address of studentLastName: %p \n \n", &studentLastName[elements_std_last_name-1]);

  //Printing the interpretation
  printf("This means that even if the student's last name is less that 15 characters\n");
  printf("the size of the studentLastName array is still the size we initialized it \n");
  printf("to which is 15 characters and since each character is one byte, the size \n");
  printf("of the studentLastName string/array of characters remains 15 bytes. \n \n ");


  /////////////////////////////////////
  // Printing Task 3 Interpretations //
  /////////////////////////////////////
  printf("----------------------------------------------------------------------------\n");
  printf("                             Task 3 Interpretations                         \n");
  printf("----------------------------------------------------------------------------\n");
  //inputLastName function
  printf("I implemented the inputLastName function by passing in the studentLastName \n");
  printf("array which is really its starting memory address. This allows the fuction \n");
  printf("to go and replace it with the last name starting at that address. \n");
  printf("Printing the address of studentLastName in main and in the function gives \n");
  printf("the same memory address. This makes sense as we are actually passing in its \n");
  printf("address. ");
  printf("I have learned that array variables need to be sized and told what data type\n");
  printf("they will be storing. I also see that array variables store their memory \n");
  printf("address and so we can pass them into function and change them without the \n");
  printf("need for pointers or to return anything. \n");

  return 0;
}


//////////////////////////////
// Function Implementations //
//////////////////////////////
void inputLastName(char studentLastName[]) {
  /*
  Prompts the user to enter a student's last name, store in the studentLastName
  array. This array is 15 characters long so we expect their last name to be
  14 characters or less.
  */

  printf("What is the student's last name?\n");
  scanf("%s", studentLastName);

  return;
}

int inputAge(void){
  /*
  Prompts the user to enter the student's age then stores and returns it as an
  integer.
  */
  int studentAge;
  printf("What is the student's age? \n");
  scanf("%d", &studentAge);

  return studentAge;
}

float input_gpa(void){
  /*
  Prompts the user to enter the student's gpa then stores and returns it as a
  float.
  */
  float gpa;
  printf("What is the student's GPA? \n");
  scanf("%f", &gpa);

  return gpa;
}

float inputFinalExamScore(void){
  /*
  Prompts the user to enter the student's final exam score then stores and returns
  it as a float.
  */
  float finalExamScore;
  printf("What is the student's final exam score? \n");
  scanf("%f", &finalExamScore);

  return finalExamScore;
}

char determineGrade(float finalExamScore){
  /*
  Takes in a students final exam score and determines their letter grade by the
  criteria given in the lab 1 pdf
  */
  //Determining the student's final grade based on their exam score
  char grade;
  if (finalExamScore >= 90){
    grade = 'A';
  }
  //will only test if the score <90
  else if (85 <= finalExamScore){
    grade = 'B';
  }
  //will only test if the score <85
  else if (80 <= finalExamScore){
    grade = 'C';
  }
  //will only test if the score <80
  else if (75 <= finalExamScore){
    grade = 'D';
  }
  //will only enter if the score <75
  else{
    grade = 'S';
  }

  return grade;
}

void printData(char studentLastName[], int studentAge, float gpa, float finalExamScore){
  /*
  This function prints the data asked in Task 1
  */
  //Determining the student's grade
  char grade = determineGrade(finalExamScore);

  ///Printing the inputted information///
  printf("Student's Last Name: %s \n", studentLastName);
  printf("Student's Age: %d \n", studentAge);
  //We round in the second decimal
  printf("Student's GPA: %.2f \n", gpa);
  //We round in the first decimal
  printf("Student's Final Exam Score: %.1f \n", finalExamScore);
  printf("Student's Grade: %c \n \n", grade);
  printf("\n");

  return;
}
