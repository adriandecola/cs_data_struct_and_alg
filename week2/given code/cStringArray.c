#include<stdio.h>

//Function Declarations
void clearBuffer(void); // a function that will clear the buffer.

int main(void){

//An array is a collection of homogenous type (data type)
//An array is a contiguous block in memory
//The name of array refers to address of the first element in the array
//C strings are character arrays which are null terminated


// one way to work with this.
char lName[]={'P','E','T','E','R','\0'};

char fName[6];

printf("Some Name \n");

for (int i =0; i<6;i++){
	scanf("%c", &fName[i]);
	clearBuffer();
}

for (int i =0; i<6;i++){
	printf("%c \n", fName[i]);
}

char mName[10]; //We know that we want to read a string
printf("Enter Name: ");
scanf("%s", mName);

printf("Entered name is %s \n", mName);



return 0;
}

//Function Implementations

/*
Create a while loop that keeps reading until we encounter return character - \n
void function is a non value returning function

*/
void clearBuffer(void){

	char whatsinBuffer;
	scanf("%c", &whatsinBuffer);
	while (whatsinBuffer != '\n'){
		printf("\t Buffer has: %c \n", whatsinBuffer);
		scanf("%c", &whatsinBuffer);
	}
return;

}