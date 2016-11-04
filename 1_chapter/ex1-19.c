#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000

int get_line(char line[], int max_length);
char* reverse_string(char intput[]);

int main(){
  char line[MAXLENGTH];
  int line_num = 1;

  while(get_line(line, MAXLENGTH)) 
    printf("%d: %s\n", line_num++, reverse_string(line));

  return 0;
}

int get_line(char buf[], int limit){
  int c, i;
  for(i = 0; (c = getchar()) != EOF && i < limit - 1; ++i){
    if (c == '\n') {
      ++i; 
      break;
    }
    buf[i] = c;
  }
  buf[i] = '\0';
  return i;
}

char* reverse_string(char input[]){
  int length = strlen(input);
  int start, end, c;

  for(start=0, end = length - 1; start < end; start++, end--){
    c = input[start];
    input[start] = input[end];
    input[end] = c;
  }

  return input;
}
