#include <stdio.h>

void print_buf(int *buf, int length);

int main(){
  int buf_len = 10;
  int buf[buf_len];

  print_buf(buf, buf_len);
  return 0;
}

void print_buf(int *buf, int length){
  int i;
  for(i=0; i<length; ++i)
    printf("%d ", buf[i]);
  printf("\n");
}
