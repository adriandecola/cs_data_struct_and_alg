#include<stdio.h>

//void printName(char * name);
void printName(char name[]){
	int i = 0;

	while (name[i] !='\0'){
		i++;
	}
	int size = i;

	printf("%d  %u \n", size, name);

	return;

}

void printGrades(int grades[], int size){

	int size2 = sizeof grades;

	printf("%d %lu \n", size2, grades);

	return;


}


int main (int argc, char * argv[]){

	char name[] = {'p','e','t','e','r','\0'};

	int size = sizeof name;


	printName(name);

	int grades[] = {90,45,67,78,98};

	printf("%lu \n", grades);

	int size2 = sizeof grades/ (sizeof grades[0]);
	printf("%d \n", size2);

	printGrades(grades, size2);


return 0;
}
