#include <stdio.h>
#include <strings.h>

/*Rewrite the function lower, which converts upper case letters */
/*to lowercase letters, with a conditional expression*/

char lower(char c);

int main(){
  int i;
  char *lul = "this IS a TEST 0123456789 ;[]\'{} ";

  for(i=0; i<strlen(lul); ++i){
    printf("%c" , lower(lul[i]));
  }

  puts("");
  return 0;
}

char lower(char c){
  return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}
