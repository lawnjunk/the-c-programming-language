#include <stdio.h>

#define LOWER -100
#define UPPER 100
#define STEP 20

float ctof(float celsius);

int main(){
  float celsius = LOWER;
  
  while(celsius <= UPPER){
    printf("C %3.0f: F: %3.0f\n", celsius, ctof(celsius));
    celsius += STEP;
  }

  return 0;
}

float ctof(float celsius){
  return (9.0/ 5.0) * celsius + 32;
}
