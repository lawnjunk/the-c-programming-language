#include <stdio.h>
#define MAX_STACK 1000

static char *stack[MAX_STACK];
static int stack_top;
static int pushstr(char *);
static char *popstr();

// echo command
int main(int argc, char *argv[]){
  char **current;

  int (* push)(char *) = pushstr;

  stack[0] = "this is a test";
  stack[1] = "this is a diff test"; 
  stack[2] = "this is a wierd test"; 
  stack_top = 3;

  pushstr("hey there");
  push("hey sup ");
  pushstr("Dow");
  pushstr("lulwat");

  // loop using pointer arithmatic
  for (current = stack; current < (stack + stack_top); current++){
    printf("%s\n", *current);
  }

  // loop using static extern stack
  while( stack_top ){
    printf("%s\n", popstr());
  }

  return 0;
} 

static int pushstr(char *str){
  stack[stack_top++] = str;
  return stack_top;
}

static char *popstr(){
  return stack[--stack_top];
}
