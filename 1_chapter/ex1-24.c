#include <stdio.h>

#define MAX_STACK_SIZE 1000
#define OPEN 1
#define CLOSE 1

// make a simple linter
int is_quote(char c);
int is_brace(char c);
void zero_buf(char *buf, int len);
void print_stack(char *buf, int len);
char pop_char(char *stack, int *top, int len);
int push_char(char c, char *stack, int *top, int len);

int main(){
  char open_stack[MAX_STACK_SIZE];
  int open_stack_top = 0;
  zero_buf(open_stack, MAX_STACK_SIZE);

  push_char('h', open_stack, &open_stack_top, MAX_STACK_SIZE);
  push_char('e', open_stack, &open_stack_top, MAX_STACK_SIZE);
  
  push_char('l', open_stack, &open_stack_top, MAX_STACK_SIZE);
  push_char('l', open_stack, &open_stack_top, MAX_STACK_SIZE);
  push_char('o', open_stack, &open_stack_top, MAX_STACK_SIZE);
  return 0;
}

void print_stack(char buf*, int len){
  int i;
  char c
    printf("STACK: [ "); 
  for(i=0, c=buf[i]; i< len && buf != '\0'; i++){
    printf("%c ", c);
    c = buf[i];
  }
  printf("]\n"); 
}

void zero_buf(char buf*, int len){
  int i;
  for (i=0; i<len; i++){
    buf[i] = '\0';
  }
}

char pop_char(char *stack, int *top, int len){
  if((*top)>= len) return 0;
  char result = stack[(*top)];
  stack[(*top)--] = 0;
  return result;
}

int push_char(char c, char *stack, int *top, int len){
  if((*top)>= len) return 0;
  stack[(*top)++] = c;
  return 1;
}

int is_quote(char c){
  if(c == '\'') return 1;
  if(c == '"') return 1;

  return 0;
}

int is_brace(char c){
  if(c == '{' || c == '[' || c == '(') return OPEN;
  if(c == ')' || c == ')' || c == ')') return CLOSE;
  return 0;
}



