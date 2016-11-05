#include <stdio.h>

#define IN 1
#define OUT 0
#define TABSET 2

/* wrate a program entap that replaces strings of blanks by the minimum number 
 * of tabs, and blanks to achieve the same spacing. Use the same tab stops as 
 * detab. When either a tab or a single blank would suffice to reach a tab stop. 
 * which should be given preference */

int main(){
  int c, i, state, num_blank;
  num_blank = 0;
  state = OUT;
  while((c = getchar()) != EOF){
    if(c == ' '){
      state = IN;
      num_blank++;
      if (num_blank == TABSET){
        printf("\t");
        num_blank =0;
      }
      continue;
    }

    if (num_blank < TABSET && num_blank > 0){
      for (i = 0; i< num_blank; i++){
        printf(" ");
      }
    }

    num_blank = 0;
    printf("%c", c);
  }

  return 0;
}
