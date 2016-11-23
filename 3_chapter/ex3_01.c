#include <stdio.h>

int bin_search(int x, int *data, int length);

int main(){
  int nums[] = {0, 3, 6, 11, 14, 17, 20, 23};

  printf("found %d\n", bin_search(6, nums, 8));
  printf("found %d\n", bin_search(23, nums, 8));
  printf("found %d\n", bin_search(0, nums, 8));
  printf("8 not found %d\n", bin_search(33, nums, 8));
  return 0;
}

int bin_search(int x, int *data, int length){
  int low, high, mid, c;
  low = 0;
  high = length -1;
  c = 1;
  while(low <= high){
    ++c;
    mid = (low+high) / 2;
    if(x < data[mid])
      high = mid -1;
    else
      low = mid + 1;
  }

  if (x == data[mid])
    return x;
  return -1;
}


