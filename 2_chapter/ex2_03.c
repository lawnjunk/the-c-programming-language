#include <stdio.h>
#include <math.h>
#include <strings.h>

int htoi(char *hex);
int hchar_to_int(char c);

int main(){
  printf("%d\n", htoi("0xAeF01B"));
}

int htoi(char *hex){
  int i = 0;
  int result = 0;
  int length = strlen(hex);
  int exp = length -1 ;

  if ((length > 1) && (hex[1] == 'x' || hex[1] == 'X')){
    if (hex[0] != '0'){
      return -1;
    }

    i = 2;
    exp -= 2;
  }

  for(; i<length; ++i, --exp){
    result += hchar_to_int(hex[i]) * pow(16, exp);
  }

  return result;
}

int hchar_to_int(char c){
  switch (c) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'A': return 10;
    case 'a': return 10;
    case 'B': return 11;
    case 'b': return 11;
    case 'C': return 12;
    case 'c': return 12;
    case 'D': return 13;
    case 'd': return 13;
    case 'E': return 14;
    case 'e': return 14;
    case 'F': return 15;
    case 'f': return 15;
    default: return -1;
  }
}

