#include <stdio.h>

/* write a program to write blanks tabs and new lines */


int main(){
  int c, num_space, num_tab, num_line;
  num_space = num_tab = num_line = 0;

  while((c = getchar()) != EOF){
    if(c == ' ')
      ++num_space;
    if(c == '\n')
      ++num_line;
    if(c == '\t')
      ++num_tab;
  }

  printf("number of spaces %d\n", num_space);
  printf("number of tabs %d\n", num_tab);
  printf("number of lines %d\n", num_line);

  return 0;
}
