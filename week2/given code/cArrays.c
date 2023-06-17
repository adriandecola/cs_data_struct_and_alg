#include<stdio.h>
/*
A function that returns student with highest exam score
*/

double getHighestScore(double scores[], int size);



int main(void){

//An array is a collection of homogenous type (data type)
//An array is a contiguous block in memory
//The name of array refers to address of the first element in the array


// one way to work with this.
double stdGrades[]= {78.1, 98.2, 14.7,89.3};


printf("How many bytes in StdGrades %lu \n", sizeof (stdGrades));
printf("How many bytes in StdGrades %lu \n", sizeof (stdGrades[0]));

//How to determine how big my Array is
int size = (sizeof stdGrades) / (sizeof stdGrades[0]);

printf("Okay, how many do we have %d\n", size);

//Another way:
double myStdGrades[5] = {78,89,52,42,100}; //declaration and initilization

double myStudentGrades[5]; //declared and no initilization

int i = 0;
//populate array using a for loop
printf("Enter the Grades \n");
for (i=0; i<5; i++){
	scanf("%lf", &myStudentGrades[i]);
}

printf("Print Grades \n");
for (i=0; i<5; i++){
	printf("Value is: %lf and Address is: %lu and Address is %lu \n", myStudentGrades[i], &myStudentGrades[i], myStudentGrades + i );
}

printf("What is the name of Array %lu \n", myStudentGrades);

double highScore = getHighestScore(myStudentGrades, 5);

printf("Highest Grade is %.2lf \n", highScore);



return 0;
}
//Always pass the size of the Array to know the size of the array
double getHighestScore(double scores[], int size){

	double highscore = 0.0;
	
	for (int i =0; i <size; i++){
		if (scores[i]>highscore){
			highscore = scores[i];
		}
	}

   return highscore;
}



