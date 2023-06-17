/*
Author: Adrian deCola
Date: March 19, 2023
Purpose: This program if for quesiton 5a of the synthesis, which should do the following:

Write a complete C program that will search a file of numbers of type int (named numbers.txt) 
for the smallest number and then write that value to the screen.  Assume that the file 
contains nothing but numbers of type int separated by blank spaces or line breaks, and that 
the file contains at least one number.  You may not use any type of array for this problem.  
Remember to include all necessary code so that your answer would successfully compile.
*/

#include <stdio.h>
#include <stdlib.h>

//Function declaration
void printMaxNum(void);


int main(void){
    //Testing printMaxNum
    //printMaxNum();


    return 0;
}





void printMaxNum(void){
    //Opening the file
    FILE* pFile = fopen("numbers.txt", "r");
    if (pFile ==NULL){
        printf("File could not be opened.\n");
        exit(-1);
    }

    int maxNum = -999999;
    int temp; 
    //Reading throught the file
    while (fscanf(pFile, "%d", &temp) != EOF){
        //Updating the maxNum if a larger is read
        if (temp > maxNum){
            maxNum = temp;
        }
    }

    //Outputing the maxNum
    printf("The largest integer found in 'numbers.txt' is %d. \n", maxNum);

    //Cosing the file
    fclose(pFile);
    
    return;
}
