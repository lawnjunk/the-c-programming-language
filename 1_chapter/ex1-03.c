#include <stdio.h>

#define LOWER 0
#define UPPER 150
#define STEP 20

/* write a program to print a heading above the temp
 * conversion program */

int main(){
  float fahr, celsius;
  int lower = LOWER;
  int upper = UPPER;
  int step = STEP;
  fahr = (float) lower;

  printf("Fahreneit to Celsius\n");
  while (fahr <= upper){
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("F: %3.0f C:%6.1f\n", fahr, celsius);
    fahr += (float) step;
  }

  return 0;
}
