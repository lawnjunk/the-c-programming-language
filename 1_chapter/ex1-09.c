#include <stdio.h>

#define IN 1
#define OUT 0

/* write a program to remove duplicate blank lines */

int main(){
  int c, state;
  state = OUT;

  while((c = getchar()) != EOF){
    if (c == '\n'){
      if (state == OUT){
        state = IN;
        printf("\n");
      }
      continue;
    }
    state = OUT;
    printf("%c", c);
  }

  return 0;
}
