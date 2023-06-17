#include<stdio.h> //Preprocessor directive includes standard input and output

//creating this STATUS variable in main so it is accessable everywhere
typedef enum status{SUCCESS, FAILURE} STATUS;

typedef struct student{
  char lastName[15];
  int age;
  float gpa;
  float finalExamScore;
  char grade;
  STATUS status;
} STUDENT;


///////////////////////////
// Function Declarations //
///////////////////////////
void inputLastName(char studentLastName[]);
int inputAge(void);
float input_gpa(void);
float inputFinalExamScore(void);
char determineGrade(float finalExamScore);
STATUS determineStatus(float finalExamScore);
//were not using this one
//void printData(char studentLastName[], int studentAge, float gpa, float finalExamScore);
void printStudentData(STUDENT student);






int main(void) {
  STUDENT s1;

  //Collecting the student's last name
  inputLastName(s1.lastName);

  //Collecting the student's age
  s1.age = inputAge();

  //Collecting the student's GPA
  s1.gpa = input_gpa();

  //Collecting the student's final exam score
  s1.finalExamScore = inputFinalExamScore();

  //Determining the student's grade and storing it
  s1.grade = determineGrade(s1.finalExamScore);

  //Deterniming the student's status
  s1.status = determineStatus(s1.finalExamScore);

  //Printing the student's information
  printStudentData(s1);


  return 0;
}















//////////////////////////////
// Function Implementations //
//////////////////////////////
void inputLastName(char studentLastName[]) {
  /*
  Prompts the user to enter a student's last name, and stores it in the string member
  called lastName of the STUDENT struct. This array is 15 characters long so we
  expect their last name to be 14 characters or less. Of course the last name
  should have no spaces so we can read it in using the scanf function.
  */

  printf("What is the student's last name?\n");
  scanf("%s", studentLastName);
  //we don't need to return it since we passed in an address/the name of an array
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

/*
void printData(char studentLastName[], int studentAge, float gpa, float finalExamScore){
  //This function prints the data asked in Task 1 in Lab 1
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
*/

STATUS determineStatus(float finalExamScore){
  /*
  This function determines if a student has succeeded or failed on their final
  exam. A success is considered an 80 or higher and anything less is a failure.
  This function then returns the enum type STATUS.
  */
  STATUS studentStatus;

  if (finalExamScore >= 80){
    studentStatus = SUCCESS;
  }
  else{
    studentStatus = FAILURE;
  }

  return studentStatus;
}

void printStudentData(STUDENT student_){
  /*
  This function prints the data in a STUDENT struct.
  */
  ///Printing the inputted information///
  printf("\n");
  printf("Student's Last Name: %s \n", student_.lastName);
  printf("Student's Age: %d \n", student_.age);
  //We round in the second decimal
  printf("Student's GPA: %.2f \n", student_.gpa);
  //We round in the first decimal
  printf("Student's Final Exam Score: %.1f \n", student_.finalExamScore);
  printf("Student's Grade: %c \n", student_.grade);
  //Printing the student's success on the final exam
  if (student_.status == 0){
    printf("Student's Success on Final Exam: SUCCESSFUL \n");
  }

  else if (student_.status ==1){
    printf("Student's Success on Final Exam: FAILURE \n");
  }
  printf("\n");

  return;
}
