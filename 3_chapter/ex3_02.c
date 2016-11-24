#include <stdio.h>
#include <strings.h>

#define MAX_LENGTH 1000

/*write a function escape that converts characters liek*/
/*newline and tab into visible escape sequences like \n */
/*and \t is it copies the string t to s. use a switch */
/*write a function for the other direction as well*/

int escape(char *s, char *t);
int unescape(char *s, char *t);

int main(){
  char escape_result[MAX_LENGTH];
  char unescape_result[MAX_LENGTH];

  escape(escape_result, "hello\twor\\ld\n");
  printf("escape_result\n%s\n", escape_result);
  unescape(unescape_result, escape_result); 
  printf("unescape_result\n%s\n", unescape_result);

  return 0;
}

int escape(char *s, char *t){
  int i,j,c;
  for (i=0, j=0, c=t[0]; c!='\0'; c=t[++i], ++j){
    switch (c){
      case '\t':
        s[j] = '\\';
        s[++j] = 't';
        break;
      case '\n':
        s[j] = '\\';
        s[++j] = 'n';
        break;
      default:
        s[j] = c;
    }
  }
  s[j] = '\0';
  return j;
}

int unescape(char *s, char *t){
  int i,j,c;
  for(i=0, j=0, c=t[0]; c!='\0'; c=t[++i], ++j){
    switch(c){
      case '\\':
        c=t[++i];
        switch (c){
          case 't':
            s[j] = '\t';
            break;
          case 'n':
            s[j] = '\n';
            break;
          default:
            s[j] = '\\';
            s[++j] = c;
        }
        break;
      default:
        s[j] = c;
    }
  }
  s[j] = '\0';
  return j;
}

