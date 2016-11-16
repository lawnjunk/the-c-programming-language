#include <stdio.h>
#include <strings.h>

void squeeze(char *input, char *filter);

int main(int argc, char *argv[]){

  if (argc != 3){
    printf("USAGE ERROR:\n  Try ./squeeze <string one> <string two>\n");
    return 1;
  }

  char data[strlen(argv[1])]; 
  strcpy(data, argv[1]);

  squeeze(data, argv[2]);
  printf("%s\n", data);

  return 0;
}

void squeeze(char *input, char *filter){
  int i, f;
  char alpha_map[128];
  char tmp_buf[strlen(input)];

  for (i=0; i<128; ++i){
    alpha_map[i] = 0;
  }

  for (i=0; i<strlen(filter); ++i){
    alpha_map[filter[i]] = 1;
  }

  for (i=0, f=0; i<strlen(input); ++i){
    if(alpha_map[input[i]]) continue;
    tmp_buf[f++] = input[i];
  }

  tmp_buf[f] =  '\0';

  strcpy(input, tmp_buf);
}
