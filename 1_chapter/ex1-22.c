#include <stdio.h>

#define FOLD_BREAK 79
#define IN 1
#define OUT 0

/* write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

/* fold on words less than 10 char in length and hefinate longer words */
int is_white_space(char c);
int is_alphabet_char(char c);

int main(){
  int c;
  int state = OUT;
  int line_length = 0;
  int last_state = OUT;
  int last_char = '\0';
  int word_count = 0;

  while((c = getchar()) != EOF){
    // check if the current char is in a word
    // and keep track of the length
    if(!is_alphabet_char(c)){
      state = OUT;
      word_count = 0;
    } else {
      word_count++;
      state = IN;
    }

    if( line_length == FOLD_BREAK - 1){
      // if the current character or last_char was whitespace print a newline
      // else if check if the current word has
      // then rest the line length
      if (!state || !last_state)
        printf("\n");
      else 
          printf("-\n");

      line_length = 0;
      continue;
    }

    last_state = state;

    // skip new lines
    if(c == '\n') continue;
    
    // not print a spacebar for first char of line
    if (is_white_space(c) && line_length == 0) 
      continue;

    printf("%c", c);
    line_length++;
  }
  printf("\n");

  return 0;
}


int is_alphabet_char(char c){
  return c > 64 && c < 124;
}

int is_white_space(char c){
  return c == ' ' || c == '\t' || c == '\n';
}
