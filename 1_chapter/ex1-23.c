#include <stdio.h>

/* remove comments from a c program */

int main(){
  int c, last;


  while ((c = getchar()) != EOF){
    if(c == '/'){
      last = c; 
      if ((c = getchar()) == '/' ){
        // skip the rest of the line
        while((c = getchar()) != EOF && c != '\n')
          continue;
        printf("\n");
        continue;
      } else {
        printf("%c%c", last, c);
      }
    }

    printf("%c", c);
  }

  printf("\n");
  return 0;
}
