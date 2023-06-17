#include<stdio.h> // include preprocessor directive

//Function Declarations
void clearBuffer(void); // a function that will clear the buffer.



//int main (); //Ok but Prof doesnt like it
//int main (void); //Prof likes if not including any argument
int main (int argc, char * argv[]){

char mid, mid2, mid3;
printf("Enter a character:");
scanf("%c", &mid);
printf("my character is: %c \n", mid);
clearBuffer();

printf("Enter another character:");
scanf("%c", &mid2);
printf("my second character is %c \n", mid2);
clearBuffer();



printf("Enter another character:");
scanf("%c", &mid3);
printf("my second character is %c \n", mid3);
clearBuffer();



//To avoid this problem, make sure that the buffer (or spool) is empty. 
//Create some C code that reads all items in the spool?

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