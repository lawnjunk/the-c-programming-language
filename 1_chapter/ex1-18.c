#include <stdio.h>   

/* writea a program that removes trailing blanks and tabs from each line
 * of input, and to delete entirely blank lines */

#define MAXLINE 1000
#define IN 1   
#define OUT 0

int is_white_space(char c);

int main(){
  int i, c;   
  int state = OUT;
  int blank_count = 0;
  char white_space_buf[MAXLINE];

  // accumulate wite space until a \n or no white space char
  // if \n dont print it
  // if non white space char print accumulated white space
  while((c = getchar()) != EOF){
    if (is_white_space(c)){
      state = IN;
      white_space_buf[blank_count] = c;
      ++blank_count;

      if (c == '\n'){
        state = OUT;
        blank_count = 0;
        printf("\n");
      }
      continue;
    }

    state = IN;
    if (blank_count > 0){ // encountered a non white space char
      white_space_buf[blank_count] = '\0';
      printf("%s", white_space_buf);
      blank_count = 0;
    }

    printf("%c", c);
  }
  return 0;
}

int is_white_space(char c){
  return c == ' ' || c == '\t' || c == '\n';
}
