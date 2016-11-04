#include <stdio.h>

/* write a program to print a histogram of the 
 * frequencies of different characters in its input. */

void print_char(char c);

int main(){
  int histogram[128];
  int i, c, char_count;

  for(i=0; i<128; ++i){
    histogram[i] = 0;
  }

  while((c = getchar()) != EOF){
    histogram[c]++; 
  }

  for(i=0; i<128; ++i){
    char_count = histogram[i];
    if( char_count > 0){
      print_char(i);
      printf(": %d \n", char_count);
    }
  }

  return 0;
}


void print_char(char c){
  if (c == '\n') {
    printf("\\n");
    return;
  }

  if (c == '\t'){
    printf("\\t");
    return;
  }
  printf("%c", c);
}
