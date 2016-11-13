#include <stdio.h>

#define FOLD_BREAK 79
#define WORD_BUF_LENGTH 1000;
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
int fill_line_buff(char *line, int len);

int main(){
  int length;
  char line[FOLD_BREAK];
  char next_word[WORD_BUF_LENGTH]; 
  int is_done = 0;

  while(!is_done){
    get_word(next_word, WORD_BUF_LENGTH, 
  }

  return 0;
}

int get_word(char *word, int buf_length, void (*callback)(int done, int length){
  int i;
  int done = 0;
  for(i=0; (c = getchar()) != EOF && i < buf_length -1; ++i){
    if(c == ' ' || c == '\t' || c == '\n') 
      break;
    word[i] = c;
  }

  if (c == EOF)
    done = 1;
  callback(done, i) ;
}

int fill_line_buff(char *buf, int len){
  int i, c;
  for(i=0; (c = getchar()) != EOF && i < len -1; ++i){
    if (c == '\n'){
      buf[i] = ' ';
      continue;
    }
    buf[i] = c; 
  }
  return i;
}

int is_alphabet_char(char c){
  return c > 64 && c < 124;
}

int is_white_space(char c){
  return c == ' ' || c == '\t' || c == '\n';
}
