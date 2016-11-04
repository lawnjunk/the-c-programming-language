#include <stdio.h>
#define IN 1
#define OUT 0


/* write a program to print a histogram of the lengths 
 * of words in its input. It is easy to draw the 
 * histogram with the bars horizontal; a vertical 
 * orientation is more challenging. */

int is_white_space(char c);

int main(){
  int c, i, min, max;
  int word_length = 0;
  int histogram[256];
  int state = OUT;
  min = 255;
  max = 0;

  for(i=0; i<256; ++i){
    histogram[i] = 0;
  }

  while ((c = getchar()) != EOF){
    if (is_white_space(c)){
      state = IN;
      histogram[word_length]++;
      if (word_length < min)
        min = word_length;
      if (word_length > max)
        max = word_length;
      word_length = 0;
    }
    ++word_length;
  }

  for (i=min; i<=max; ++i){
    if ((word_length = histogram[i]) > 0){
      printf("size: %d count: %d", i + 1, word_length);
      for(c=0; c<word_length; ++c){
        printf("-");
      }
      printf("\n");
    }
  }
}

int is_white_space(char c){
  return c == ' ' || c == '\n' || c == '\t';
}
