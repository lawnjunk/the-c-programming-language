#include <stdio.h>
#include <strings.h>
#include <limits.h>

#define MAX_LENGTH 500

void itob(int n, char s[], int b);
void reverse(char intput[]);

int main(){
  char number[MAX_LENGTH];
  itob(INT_MIN + 1376, number, 16);
  printf("%s\n", number);
  
  itob(INT_MIN , number, 2);
  printf("%s\n", number);

  itob(INT_MAX - 3749, number, 8);
  printf("%s\n", number);

  return 0;
}

void itob(int n, char s[], int b){
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
}

void reverse(char input[]){
  int c, i, j;
  for (i=0, j=strlen(input)-1; i< j; i++, j--){
    c = input[i];
    input[i] = input[j];
    input[j] = c;
  }
}

