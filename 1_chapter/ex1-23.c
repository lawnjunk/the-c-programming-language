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
        last = '\0';
        continue;
      } 
      
      if(c == '*'){
        while((c = getchar()) != EOF){
          if(c == '*') {
            if((c = getchar()) == '/'){
              break;
            }
          }
        }
        printf("\n");
        last = '\0';
        continue;
      } 

      printf("%c%c", last, c);
    }

    printf("%c", c);
  }

  printf("\n");
  return 0;
}
