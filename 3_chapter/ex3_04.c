#include <stdio.h>
#include <strings.h>
#include <limits.h>

#define MAX_LENGTH 500

void itoa(int n, char s[]);
void reverse(char intput[]);

int main(){
  char number[MAX_LENGTH];
  itoa(INT_MIN, number);
  printf("%s\n", number);

  itoa(375, number);
  printf("%s\n", number);
  return 0;
}

void itoa(int n, char s[]){
  long num = (long) n;
  int i, sign;  

  if((sign = n) < 0){
    num = -num;
  }

  i = 0;

  do {
    s[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char input[]){
  int c, i, j;
  for (i=0, j=strlen(input)-1; i< j; i++, j--){
    c = input[i];
    input[i] = input[j];
    input[j] = c;
  }
}

