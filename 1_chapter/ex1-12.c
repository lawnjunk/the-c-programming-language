#include <stdio.h>
#define IN 1
#define OUT 0

int is_white_space(char c);

int main(){
  int c;
  int state = OUT;

  while((c = getchar()) != EOF){
    if (is_white_space(c)){
      if (!state){
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

int is_white_space(char c){
  return c == ' ' || c == '\n' || c == '\t';
}
