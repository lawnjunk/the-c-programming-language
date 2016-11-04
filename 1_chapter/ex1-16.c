#include <stdio.h>
#define MAXLINE 80


/* revies the main routiene of the lognest-line program so it will
 * correctly print the length of arbitraryly long input lines, 
 * and as much as possible of the text. */

int get_line(char line[], int maxline);
int copy_buf(char to[], char from[]);

int main(){
  int len, max, line_num, line_count;
  char line[MAXLINE];
  char longest[MAXLINE];
  max = 0;
  line_count = line_num = 1;

  while((len = get_line(line, MAXLINE)) > 0 ){
    if (len > max){
      max = len;
      line_num = line_count;
      copy_buf(longest, line);
    }
    line_count++;
  }

  if( max > 0){
    printf("line %d had %d characters\n", line_num, max);
    printf("%s\n", longest);
  }

  return 0;
}

/* read line into buf and return length */
int get_line(char buf[], int limit){
  int c, i;
  i=0;
  while((c = getchar()) != EOF && c != '\n' ){
    if (i < limit) {
      buf[i] = c;
    }
    ++i;
  }
  buf[i] = '\0';
  return i;
}

int copy_buf(char to[], char from[]){
  int i, c;
  i = 0;
  while((to[i] = from[i]) != '\0'){
    ++i;
  }

  to[i] = '\0';
  return i;
}
