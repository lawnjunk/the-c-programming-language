#include <stdio.h>
#include <strings.h>

#define MAX_LENGTH 1000

int expand(char *s1, char *s2);
int expand_helper(char *s1, char low, char high);

int main(){
  char expand_result[MAX_LENGTH];

  expand(expand_result, "hello a-c-g 0-9");
  printf("%s\n", expand_result);
  return 0;
}

int expand(char *s1, char *s2){
  char expand_result[MAX_LENGTH];
  int cur, last, i, j;
  i = 0;
  j = 0;
  cur = s2[i]; 
  last = '\0';

  while((cur = s2[i++]) != '\0'){
    if (cur == '-' && i != 0){
      int c;
      char expanded[MAX_LENGTH];
      int length = expand_helper(expanded, last, s2[i++]);
      for (c=1; c<length; ++c){
        s1[j++] = expanded[c];
      }
      last = s1[j-1];
      continue;
    }
    s1[j++] = cur;
    last = cur;
  }
  s1[j] = '\0';
  return j;
}

int expand_helper(char *s1, char low, char high){
  int i;
  for(i=0; low<=high; i++){
    s1[i] = low++;
  }
  s1[i] = '\0';
  return i;
}
