#include <stdio.h>

/* verify that getchar() != EOF is 0 or 1 */

int main(){
  int result = getchar() != EOF;
  if(result == 1 || result == 0){
    printf("success\n");
    return 0;
  }
  printf("failure");
    
  return 1;
}
