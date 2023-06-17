// Adrian deCola
// March 3, 2023
// CS5008 Lab07
/////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	// Let's first check that a file was passed into argv
	if (argc != 2){
		printf("This program requires one and only one file to be passed as an arguement.\n");
		exit(-1);
	}
	// Checks that the inputted file is a .s file
	if (strcmp( argv[1] + strlen(argv[1])-2 , ".s") != 0){
		printf("%s", argv[1] + strlen(argv[1])-2);
		printf("This program requires a '.s' file. \n");
		exit(-1);
	}

	// Initializing counters
	int add = 0;
	int sub = 0;
	int mul = 0;
	int div = 0;
	int mov = 0;
	int lea = 0;
	int push = 0;
	int pop = 0;
	int ret = 0;

	// Opening the file
	FILE* pFile = fopen(argv[1], "r");
	if (pFile == NULL){
		printf("This file doesn't exist");
		exit(-1);
	}
	
	// Reading through the file line by line and storing each line in buffer
	// as a string. 
	// We want to get the first 3 characters in each line and see if they match
	// any of the specified assembly commands
	char buffer[250];

	while (fgets(buffer, 250, pFile)){
		// Making the buffer all lowercase as assembly is case insensitive
		int len = strlen(buffer);
		for(int i = 0; i < len; i++) {
                        buffer[i] = tolower(buffer[i]);
                }

		// Getting the first four non-whitespace characters
        	char first_three_char[4]; //four so we can convert it to a string  
		char fourth_char = '\0'; // in case its needed  
	        int index = 0;    

		for (int i = 0; i < len; i++){
			char chr = buffer[i];
			if (chr != ' ' && chr != '\n' && chr != '\t' &&
			    chr != 'r' && chr != '\f' && chr != '\v' ){
				
				first_three_char[index] = chr;
				index++;
				if (index ==3){ 
					if (i + 1 < len){
						fourth_char = buffer[i + 1];
					}
					break;
				}
			}
		}
		
		// Comparing the first three letters to the list of specified commands
		first_three_char[3] = '\0'; // converting to a string so we can easily compare
		
		if (strcmp(first_three_char, "add") == 0){
		        add++;
		}
		else if (strcmp(first_three_char, "sub") == 0){
		        sub++;
		}
		else if (strcmp(first_three_char, "mul") == 0){
		        mul++;
		}
		else if (strcmp(first_three_char, "imu") == 0 && fourth_char == 'l'){
		        mul++;
		}
		else if (strcmp(first_three_char, "div") == 0){
		        div++;
		}
		else if (strcmp(first_three_char, "idi") == 0 && fourth_char == 'v'){
		        div++;
		}
		else if (strcmp(first_three_char, "mov") == 0){
		        mov++;
		}
		else if (strcmp(first_three_char, "lea") == 0){
		        lea++;
		}
		else if (strcmp(first_three_char, "pus") == 0 && fourth_char == 'h'){
		        push++;
		}
		else if (strcmp(first_three_char, "pop") == 0){
		        pop++;
		}
		else if (strcmp(first_three_char, "ret") == 0){
		        ret++;
		}
	}

	// Closing the file
	fclose(pFile);


	// Calcuating the number of instructions and cyclea
	int nInstructions = add + sub + mul + div + mov + lea + push + pop + ret;
	int nCycles = add + sub + 3*mul + 24*div + mov + 3*lea + push + pop + ret;	

	// Printing the results as instructed
	printf("********************** SUMMARY OF INSTRUCTIONS *************************\n");
	
	if (add != 0){
		printf("ADD %d\n", add);
	}
	if (sub != 0){
		printf("SUB %d\n", sub);
	}
	if (mul != 0){
		printf("MUL %d\n", mul);
	}
	if (div != 0 ){
		printf("DIV %d\n", div);
	}
	if (mov != 0){
                printf("MOV %d\n", mov);
        }
        if (lea != 0){
                printf("LEA %d\n", lea);
        }
        if (push != 0){
                printf("PUSH %d\n", push);
        }
        if (pop != 0 ){
                printf("POP %d\n", pop);
        }
	if (ret != 0){
		printf("RET %d\n", ret);
	}

	printf("Total Instructions = %d\n", nInstructions);
	printf("Total Cycles = %d\n", nCycles);

	return 0;
}



