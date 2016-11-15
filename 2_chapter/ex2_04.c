#include <stdio.h>
#include <strings.h>

void squeeze(char *input, char *filter);

int main(){

  char data[100] = "huaeccxmzrnl234nnqlyui yuio";

  squeeze(data, "uacxmzrnl234niuqu");

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

  strcpy(input, tmp_buf);
}
