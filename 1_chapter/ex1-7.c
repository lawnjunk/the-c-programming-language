#include <stdio.h>
#define IN 1
#define OUT 0

/* how do you test a word count program? what kinds of inputs will uncover bugs */

/* 
 * 1) one use spcific files with known word couts.
 * 1) check against pre existing word count programs
 * 2) binary files
 * 2) code or text that include non sentences
 * 2) utf8 files
 *
 */

int is_white_space(char c);

int main(){
  int c, num_chars, num_lines, num_words, state;

  c = num_chars = num_lines = num_words = state = OUT;

  while((c = getchar()) != EOF) {
    ++num_chars;
    if(c == '\n')
      ++num_lines;
    if(is_white_space(c)){
      state =  OUT;
      continue;
    }
    state = IN;
    ++num_words;
  }

  printf("number of lines %d\n", num_lines);
  printf("number of words %d\n", num_words);
  printf("number of charicters %d\n", num_chars);

  return 0;
}

int is_white_space(char c){
  return c == ' ' || c == '\n' || c == '\t';
}
