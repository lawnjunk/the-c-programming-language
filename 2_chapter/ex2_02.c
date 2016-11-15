#include <stdio.h>
#define LENGTH 500

int get_line(char *buf, int len);

int main(){
  char buf[LENGTH];
  get_line(buf, LENGTH);
  printf("%s\n", buf);

  return 0;
}

int get_line(char *buf, int len){
  int c;
  int i = 0;
  while((c = getchar()) != EOF){
    if (i >= len -1)  break; 
    if (c == '\n') break; 
    buf[i++] = c;
  }
  
  buf[i] = '\0';

  return i;
}
