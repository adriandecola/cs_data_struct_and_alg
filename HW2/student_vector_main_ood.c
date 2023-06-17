/*
In this section, considering Prof Mwaura's class - 
He needs to store grade data belonging to his student. He currently has 10 student. 

Ref:

https://cplusplus.com/reference/cstdlib/

a) What is the difference between static and dynamic arrays ? 
static - size of array is fixed while dynamic - array can be resized. 

b) Where is the memory for static array and where is that for dynamic arrays?
-static array memory  is in Stack memory and dynamic array on Heap. 

c) Using the C language shows how both these arrays can be formulated for Prof Mwaura's class
 
d) What do we notice about the array specifically; if we are designing an array what items/parameters would we need?

*/
#include "studentvector_ood.h"
#include "studentvector_ood.h" //testing the file works when copied twice

//main is just but a driver function

int main (void){

	MY_STUDENT pStudent= allocate();

	int item = 0;

	for (int i = 0; i<20; i++){
		item = rand()%100;
		push(&pStudent, item);
	}

	printf("Printing pStudent: \n");
	printGrades(pStudent);

	MY_STUDENT newStudent = deepCopy(&pStudent);

	printf("Printing newStudent: \n");
	printGrades(newStudent);

	deallocate(&pStudent);
	

return 0;
}

