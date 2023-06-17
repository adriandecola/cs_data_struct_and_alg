// Compile with: gcc -g -Wall args.c -o args
// Try running with:
//          - ./args
//          - ./args somefile.c
//          - ./args argv1 argv2
#include <stdio.h>
#include <stdlib.h>
// The parameters to the main function are read in
// when you execute your program on the terminal.
// argc: is the argument count
// argv: is a 'variable' number of arguments provided
//
// This program shows how to iterate through all of the arguments
int main(int argc, char* argv[]){
    //int i;

    //printf("argc is the argument count: %d\n",argc);

    // This loop will print out all of the arguments
   	/*for(i=0; i < argc; i++){
        printf("argv[%d] is %s\n",i,argv[i]);
    }*/
    FILE* pFile = fopen(argv[1], "r");
    FILE* nFile = fopen("newFile.txt", "w");
    
    
    if (pFile == NULL){
    	printf("This file does not exist!\n");
    	exit(-1);
    }
    
    char student[15];
    int grade = 0;
    
    printf("What is your name: ");
    fscanf(stdin, "%s", student);
    
    fprintf(stdout, "Welcome %s \n \n", student);
    
    while (!feof(pFile)){
    	
        fgets(student, 100, pFile);
    	fprintf(nFile,"%s", student); 
    	
    }
    
   
   	fclose(pFile);
   	fclose(nFile);

    // Then you can use the argv's as needed.
    // example: If argv[1] is suppose to be a particular (like the filename), 
    //      you can make use of it.
    // So your next step would be to use FILE* input = fopen(argv[1],"r");
    // Then read every line in that file, and 'parse' the first few characters

    return 0;
}
