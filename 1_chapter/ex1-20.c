#include <stdio.h>
#define TABSET 2

/* turn tabs into spaces */

int main(){
  int c, i;
  while((c = getchar()) != EOF){
    if (c == '\t')
      for (i=0; i<TABSET; ++i)
        printf(" ");
    else
      printf("%c", c);
  }
}
