#include<stdio.h>

//Name of array
//void printName(char * name);
void printName(char name[]){
	int i = 0;

	while (name[i] !='\0'){
		i++;
	}
	int size = i;

	printf("%d  %p \n", size, name);

	return;

}

void printGrades(int grades[], int size){


	printf("%d %p \n", size, grades);

	for (int i = 0; i<size; i++){
	    printf("%d %p  %p \n", grades[i], &grades[i], grades + i );

	}

	return;


}

void swap_ints(int *int1, int *int2){
	int *temp = *int1;
	*int1 = *int2;
	*int2 = temp;

	return;
}

//create a function that receives two integers and swaps them.
//note this swap should be seen in main as well.


int main (int argc, char * argv[]){

	int grades[] = {90,45,67,78,98};
	int size = sizeof grades / sizeof grades[0];

	/*
	int grades[10]
	for (int i =0; i<10; i++){
		grades[i] = rand()%100;
	}
	*/
	//printGrades(grades, size);

	//Pointers
	int num = 9;

	//Can I store addresses - Yes - store in a variable that can store address
	//A pointer - a variable that can store an address

	int * pNum;

	pNum = &num; //& is address of operator or Referencing operator

	int ** pPNum;
	pPNum = &pNum;

	//printf("num stores: %d but home address is %p or %p \n", num, &num, pNum);
	//printf(" pNum stores: %p but pNums home address is %p \n", pNum, &pNum);
	//printf(" pPNum stores: %p but pPNums home address is %p \n", pPNum, &pPNum);

	//How would use pointers in to effect change:
	printf("%d \n", num);
	num = num + 2;
	printf("%d \n", num);

	//using dereferencing operator (*)
	printf("Num is: %d and its address %p \n", *pNum,  pNum);

	num = *pNum + 5;

	printf("Num is: %d and its address %p \n", *pNum,  pNum);







return 0;
}
