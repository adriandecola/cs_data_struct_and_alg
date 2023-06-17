#include<stdio.h>

///////Function Headers/Definitions///////
int return_larger_int(int int1, int int2);

int main (void){
  int int1 = 9;
  int int2 = 2;
  printf("return_larger_int(%d, %d): %d \n", int1, int2, return_larger_int(int1, int2));

  return 0;
}


///////Function Implementation////////

int return_larger_int(int int1, int int2){
  if (int1 > int2){
    return int1;
  }
  else{
    return int2;
  }
}
