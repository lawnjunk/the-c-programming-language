#include <stdio.h>

#define LOWER 0.0
#define UPPER 200.0
#define STEP 20.0

int main(){
  float fahr, celsius;
  celsius = LOWER;

  printf("Celsius to Fahrenheit\n");
  while(celsius <= UPPER){
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("C:%4.0f --> F:%4.1f\n", celsius, fahr);
    celsius += STEP;
  }

  return 0;
}
