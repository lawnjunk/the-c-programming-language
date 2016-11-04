#include <stdio.h>

/* write a program to copy its input to its output,
 * replacing each tabe by \t, each backspace by \b,
 * and each backslack by \\. This makes tabs and 
 * backspaces visible in an unambiguous way. */

int main(){
  int c;

  while((c = getchar()) != EOF){
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\n')
      printf("\\n");
    else 
      printf("%c", c);
  }

  return 0;
}
