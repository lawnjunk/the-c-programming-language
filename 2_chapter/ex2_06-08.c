#include <stdio.h>
#include <stdint.h>

void priint8_t_truth(int8_t b);
int8_t right_rot(int8_t num, int8_t p);
int8_t get_bit(int8_t num, int8_t offset);
int8_t set_bit(int8_t num, int8_t offset);
void print_byte(int8_t b, char *msg);
int8_t flip_bit(int8_t num, int8_t offset);
int8_t clear_bit(int8_t num, int8_t offset);
int8_t get_bits(int8_t num, int8_t p, int8_t c);
int8_t invert_bits(int8_t num, int8_t p, int8_t n);
int8_t set_bits(int8_t num, int8_t p, int8_t c, int8_t value);

int main(){
  int8_t n;
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

  puts("\nget_bits(12, 4, 2)");
  n = get_bits(0x3b, 3, 3);
  print_byte(0x3b, "BEFORE"); 
  print_byte(n, "AFTER ");

  puts("\nset_bits(0, 1, 3, 5)");
  n = set_bits(0, 1, 3, 5);
  print_byte(n, "AFTER");

  puts("\nset_bits(-1, 2, 3, 0)");
  n = set_bits(-1, 2, 3, 0);
  print_byte(n, "AFTER");

  puts("\ninvert_bits(10, 0, 4)");
  n = invert_bits(10, 0, 4);
  print_byte(10, "BEFORE");
  print_byte(n, "AFTER ");

  puts("\ninvert_bits(0xaa, 2, 4)");
  n = invert_bits(0xaa, 2, 4);
  print_byte(0xaa, "BEFORE");
  print_byte(n, "AFTER ");

  puts("\nright_rot(0xaa, 1)");
  n = right_rot(0xaa, 1);
  print_byte(0xaa, "BEFORE");
  print_byte(n, "AFTER ");

  puts("\nright_rot(0xa0, 2)");
  n = right_rot(0xa0, 2);
  print_byte(0xa0, "BEFORE");
  print_byte(n, "AFTER ");
  return 0;

}

void print_byte(int8_t b, char *msg){
  int8_t i;
  printf("%s ", msg);
  for(i=7; i>-1; --i){
    printf(" %d", get_bit(b, i));
  }
  printf("\n");
}

void print8_t_truth(int8_t b){
  if (b) {
    printf("true\n");
    return; 
  }
  printf("false\n");
}

int8_t get_bit(int8_t num, int8_t offset){
  num  = num >> offset;
  return num & 1;
}

int8_t set_bit(int8_t num, int8_t offset){
  int8_t mask = 1 << offset;
  return num | mask;
}

int8_t clear_bit(int8_t num, int8_t offset){
  int8_t mask = 1 << offset;
  return num & ~mask;
}

int8_t flip_bit(int8_t num, int8_t offset){
  int8_t mask = 1 << offset;
  return num ^ mask;
}

/* fron in get c bits at position p */
int8_t get_bits(int8_t num, int8_t p, int8_t c){
  int8_t shift = num >> (p - c + 1);
  print_byte(shift, "SHIFT");
  int8_t mask = -1 << c;
  return shift & ~mask;
}

int8_t set_bits(int8_t num, int8_t p, int8_t n, int8_t value){
  int8_t mask = ~(-1 << n);
  value = (mask & value) << p;
  mask = mask << p;
  return (num & ~mask) | value;
}

int8_t invert_bits(int8_t num, int8_t p, int8_t n){
  int8_t mask = ~(-1 << n) << p;
  print_byte(mask, "mask  ");
  return num ^ mask;
}

int8_t right_rot(int8_t num, int8_t p){
  int8_t shift = num << p;
  int8_t mask = ~(-1 << p);
  int8_t left_over = num >> (8 - p);
  return shift | (left_over & mask);
}

/*0000 0010*/
/*0000 0000*/
/*1111 1111*/
/*1111 1101*/

// 0000 0101
//
// 
/*0000 0000*/
/*0000 0101*/

/*7654 3210*/
/*0000 1100*/


