#include <stdio.h>
#include <strings.h>

int any(char *input, char *find);

int main(int argc, char *argv[]){

  if(argc != 3){
    printf("ERROR:\n  TRY ./any <str one> <str two>\n");
    return 1;
  }

  int wat = any(argv[1] , argv[2]);
  printf("%d\n", wat);

  return 0;
}

int any(char *input, char *find){
  int i;
  int num_chars = 128;
  int char_map[num_chars]; 

  for (i=0; i<num_chars; ++i){
    char_map[i] = 0;
  }

  for(i=0; i<strlen(find); ++i){
    char_map[find[i]] = 1;
  }

  for(i=0; i<strlen(input); ++i){
    if (char_map[input[i]])
      return i+1;
  }

  return 0;
}
