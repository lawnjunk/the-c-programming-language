#include <stdio.h>

void print_truth(int b);
int get_bit(int num, int offset);
int set_bit(int num, int offset);
void print_byte(int b, char *msg);
int flip_bit(int num, int offset);
int clear_bit(int num, int offset);
int get_bits(int num, int p, int c);
int set_bits(int num, int p, int c, int value);

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

  puts("\n get_bits(12, 4, 2)");
  n = get_bits(0x3b, 3, 3);
  print_byte(0x3b, "BEFORE"); 
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

/* fron in get c bits at position p */
int get_bits(int num, int p, int c){
  int shift = num >> (p - c + 1);
  print_byte(shift, "SHIFT");
  int mask = -1 << c;
  return shift & ~mask;
}

int set_bits(int num, int p, int c, int value){
  return -1;
}

/*0000 0000*/
/*0000 0101*/

/*7654 3210*/
/*0000 1100*/

