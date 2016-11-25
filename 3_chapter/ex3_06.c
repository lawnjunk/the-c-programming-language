#include <stdio.h>
#include <strings.h>
#include <limits.h>
#define MAX_LENGTH 500

void reverse(char intput[]);
void min_width(char input[], int min_width);
void itob(int n, char s[], int b, int min_width);

int main(){
  char number[MAX_LENGTH];
  itob(130, number, 8, 10);
  printf("%s\n", number);
  itob(130, number, 8, 2);
  printf("%s\n", number);
  return 0;
}

void itob(int n, char s[], int b, int p){
  if (b > 16 || b < 2){
    s[0] = '\0';
    return;
  }

  long num = (long) n;
  int i, sign, digit, letter;

  if((sign = n) < 0){
    num = -num;
  }

  i = 0;
  do {
    digit = (int) num % b;
    if (digit > 9)
      letter = (digit - 10) + 'a';
    else
      letter = digit + '0';
    s[i++] = letter;
  } while ((num /= b) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
  min_width(s, p);
}

void reverse(char input[]){
  int c, i, j;
  for (i=0, j=strlen(input)-1; i< j; i++, j--){
    c = input[i];
    input[i] = input[j];
    input[j] = c;
  }
}

void min_width(char input[], int pad){
  int length, i, j;
  length = strlen(input);

  if (length > pad)
    return;

  char buf[MAX_LENGTH];

  strcpy(buf, input);

  for (i=0; i<pad-length; i++){
    input[i] = ' ';
  }

  for(j=0; j<length; ++j){
    input[i++] = buf[j];
  }
  
  input[i] = '\0';
}
