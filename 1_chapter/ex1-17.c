#include <stdio.h>

#define MAXLINE 80

int next_line_length(void);

int main(){
  int line_length, line_count;
  line_length = 0;
  line_count = 1;

  printf("lines with > %d chars:\n", MAXLINE);
  while((line_length = next_line_length()) > -1){
    if (line_length > MAXLINE){
      printf("%d\n", line_count);
    }
    line_count ++; 
  }
  return 0;
}

int next_line_length(void){
  int c;
  int line_length = -1;
  while((c = getchar()) != EOF ){
    line_length++;
    if (c == '\n')
      break;
  }

  return line_length;
}
