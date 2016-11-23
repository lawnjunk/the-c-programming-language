#include <stdio.h>

int count_bits(int num);

int main(){
  printf("bits in 0xb %d\n", count_bits(0xb));
  return 0;
}

int count_bits(int num){
  int c; 
  for (c=0; num!=0; num &= (num -1))
    ++c;
  return c;
}
