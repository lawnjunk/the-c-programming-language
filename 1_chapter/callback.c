#include <stdio.h>

void make_call(void (*callback)(int num));
void print_num(int num);

int main(){
  make_call(print_num);
}

void make_call(void (*callback)(int num)){
  callback(3);
}

void print_num(int num){
  printf("num %d\n", num);
}
