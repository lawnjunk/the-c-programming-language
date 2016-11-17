#include <stdio.h>

void print_byte(int b, char *msg);
void print_truth(int b);
int get_bit(int num, int offset);
int set_bit(int num, int offset);
int flip_bit(int num, int offset);
int clear_bit(int num, int offset);

int main(){
  int n;
  n = get_bit(4, 2);
  printf("get_bit(4, 2)\n"); 
  print_byte(4, "FOUR");
  printf("RESULT %d\n", n);

  n = set_bit(4 , 0);
  puts("\nset_bit(4, 0)");
  print_byte(4, "BEFORE");
  print_byte(n, "AFTER ");

  puts("\nclear_bit(-1, 1)");
  n = clear_bit(-1, 1);
  print_byte(-1, "BEFORE");
  print_byte(n, "AFTER ");

  puts("\nflip_bit(0, 3)");
  n = flip_bit(0, 3);
  print_byte(0, "BEFORE"); 
  print_byte(n, "AFTER ");

  puts("\nflip_bit(-1, 5)");
  n = flip_bit(-1, 5);
  print_byte(-1, "BEFORE"); 
  print_byte(n, "AFTER ");

  return 0;
}

void print_byte(int b, char *msg){
  int i;

  printf("%s ", msg);
  for(i=7; i>-1; --i){
    printf(" %d", get_bit(b, i));
  }
  printf("\n");

}

void print_truth(int b){
  if (b) {
    printf("true\n");
    return; 
  }
  printf("false\n");
}

int get_bit(int num, int offset){
  num  = num >> offset;
  return num & 1;
}

int set_bit(int num, int offset){
  int mask = 1 << offset;
  return num | mask;
}

int clear_bit(int num, int offset){
  int mask = 1 << offset;
  return num & ~mask;
}

int flip_bit(int num, int offset){
  int mask = 1 << offset;
  return num ^ mask;
}

