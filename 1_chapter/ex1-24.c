#include <stdio.h>

#define MAX_STACK_SIZE 1000
#define OPEN 2
#define CLOSE 1

// make a simple linter
int is_quote(char c);
int is_brace(char c);
void zero_buf(char *buf, int len);
void print_stack(char *buf, int len);
char pop_char(char *stack, int *top, int len);
int push_char(char c, char *stack, int *top, int len);
char get_matching_brace(char c);

int main(){
  char c, brace_type;
  int stack_top = 0;
  char top_char = '\0';
  char stack[MAX_STACK_SIZE];
  zero_buf(stack, MAX_STACK_SIZE);

  while((c = getchar()) != EOF){
    if ((brace_type = is_brace(c))){
      switch (brace_type){
        case OPEN:
          push_char(c, stack, &stack_top, MAX_STACK_SIZE);
          continue;;
        case CLOSE:
          top_char = pop_char(stack, &stack_top, MAX_STACK_SIZE);
          char match;
          if((match = get_matching_brace(top_char)) != c){
            printf("MATCHING BRACE ERROR\n");
            return 1;
          }
          continue;
      }
    }
  }

  if(stack_top > 0){
    printf("MATCH BRACE ERR\n");
    return 1;
  }

  printf("LOOKS GOOD\n");
  return 0;
}

void print_stack(char *buf, int len){
  int i;
  char c;
  printf("STACK: [ ");
  for(i=0; i< len; i++){
    c = buf[i];
    if(c == '\0') break;
    printf("%c ", c);
  }
  printf("]\n");
}

void zero_buf(char *buf, int len){
  int i;
  for (i=0; i<len; i++){
    buf[i] = '\0';
  }
}

char pop_char(char *stack, int *top, int len){
  if((*top)>= len) return 0;
  char result = stack[(*top) - 1];
  stack[--(*top)] = '\0';
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
  if(c == '}' || c == ']' || c == ')') return CLOSE;
  return 0;
}

char get_matching_brace(char c){
  switch (c){
    case '{':
      return '}';
    case '}':
      return '{';
    case '(':
      return ')';
    case ')':
      return '(';
    case '[':
      return ']';
    case ']':
      return '[';
    default: 
      return '\0';
  }
}
