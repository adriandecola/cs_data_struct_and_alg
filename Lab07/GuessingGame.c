/*
Author: Adrian deCola
Class: CS 5008
Purpose: To create a guessing game that practices using arrays, loops, variables,
and more.
*/

#include <stdio.h>  //This is an include preprocessor directive
#include <stdlib.h>
#include <stdbool.h> //Allows us to use booleans
#include <time.h> //use time to set random seed

/////////////////////////
//Function Declarations//
/////////////////////////
int guessingGame(void);



int main (void){
  srand((int)time(0)); //makes sure we get different random numbers each game

  int numGuessesArray[5]; //an array to hold the number of gueses each round

  //playing the game 5 times and keeping track of the number of guesses
  int i;
  for (i=0; i<5; i++){
    numGuessesArray[i]= guessingGame();
  }

  printf("=================================================== \n"); //prints a nice
  printf("| Here are the results of your guessing abilities | \n"); //header for the
  printf("=================================================== \n"); //results

  for (i=0; i<5; i++){
    printf("Game %d took you %d guesses. \n", i, numGuessesArray[i]);
  }

  return 0;
}




////////////////////////////
//Function Implementations//
////////////////////////////
int guessingGame(void){
  /*
  This function prints a header instructing the player to print a number from 1 to
  10. It then creates a random number from 1 to 10 and asks you to guess at it until
  you are correct. Each guess it will either tell you that you guessed the
  number or to guess higher or lower. It keeps track of the number of guesses
  the player made and returns it. This function assumes the user will enter an
  integer in the correct form. 
  */

  printf("======================================== \n"); //prints a nice header
  printf("|         Pick a number 1-10           | \n");
  printf("======================================== \n");

  int numGuesses = 0; //initializing a variable corresponding to the number of guesses

  int randNum = (rand() % 10) + 1; //this assignes randNum an int from 1 to 10
  int guess; //declaring an intefer for the players guess

  //A boolean corresponding to if the player has correctly guessed the number
  bool correctGuess = false;

  //This runs until the user guesses correctly
  while (correctGuess == false){
    //Collecting the guess
    printf("Make a guess: ");
    scanf("%d", &guess);

    numGuesses += 1; //incrementing the number of guesses

    //Hinting it the guess is too high or too low and returning if its correct
    if (guess == randNum){
      correctGuess = true;
      printf("You got it! \n");
    }

    else if (guess > randNum){
      printf("No guess lower! \n");
    }

    else{
      printf("No guess higher! \n");
    }

  }

  return numGuesses;
}
