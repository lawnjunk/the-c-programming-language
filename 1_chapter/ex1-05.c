#include <stdio.h>

#define LOWER 0
#define UPPER 200
#define STEP 20

int main(){
  float fahr, celsius;

  celsius = UPPER;
  while(celsius >= LOWER){
    fahr = (9.0/5.0) * celsius + 32;
    printf("C: %3.0f F: %3.0f\n", celsius, fahr);
    celsius -= STEP;
  }
  return 0;
}

