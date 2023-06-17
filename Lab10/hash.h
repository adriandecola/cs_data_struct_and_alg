#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define DELETE "D"

/* hash table struct */
typedef struct HT {
  unsigned int size;     // max size of hash table
  unsigned int numItems; // num items in hash table
  char ** table;         // array of strings
} HT;

// prototypes
HT * initTable(int n);
void freeTable(HT * t);
int insert(char * key, HT * t);
int delete(char * key, HT * t);
unsigned int hash(char *key);

/*Lab Exercises*/
void printTable(HT * t); //Exercise 1
int find(char * key, HT * t); //Exercise 2



