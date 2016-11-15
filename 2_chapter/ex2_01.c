#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
  printf("limits.h\n");
  printf("  CHAR_BIT %d\n", CHAR_BIT);
  printf("  CHAR_MAX %d\n", CHAR_MAX);
  printf("  UCHAR_MAX %d\n", UCHAR_MAX);
  printf("  SCHAR_MAX %d\n", SCHAR_MAX);
  printf("  CHAR_MIN %d\n", CHAR_MIN);
  printf("  SCHAR_MIN %d\n", SCHAR_MIN);
  printf("  INT_MAX %d\n", INT_MAX);
  printf("  LONG_MAX %ld\n", LONG_MAX);
  printf("  SHRT_MAX %d\n", SHRT_MAX);
  printf("  UINT_MAX %d\n", UINT_MAX);
  printf("  ULONG_MAX %lu\n", ULONG_MAX);
  printf("  USHRT_MAX %d\n", USHRT_MAX);
  printf("  INT_MIN %d\n", INT_MIN);
  printf("  LONG_MIN %ld\n", LONG_MIN);
  printf("  SHRT_MIN %d\n", SHRT_MIN);

  printf("\nfloat.h\n");
  printf("  FLT_RADIX %d\n", FLT_RADIX);
  printf("  FLT_ROUNDS %d\n", FLT_ROUNDS);
  printf("  FLT_DIG %d\n", FLT_DIG);
  printf("  FLT_EPSILON %E\n", FLT_EPSILON);
  printf("  FLT_MANT_DIG %d\n", FLT_MANT_DIG);
  printf("  FLT_MAX_EXP %d\n", FLT_MAX_EXP);
  printf("  FLT_MIN_EXP %d\n", FLT_MIN_EXP);
  printf("  FLT_MAX %E\n", FLT_MAX);
  printf("  FLT_MIN %E\n", FLT_MIN);

  printf("  DBL_DIG %d\n", DBL_DIG);
  printf("  DBL_EPSILON %E\n", DBL_EPSILON);
  printf("  DBL_MANT_DIG %d\n", DBL_MANT_DIG);
  printf("  DBL_MAX_EXP %d\n", DBL_MAX_EXP);
  printf("  DBL_MIN_EXP %d\n", DBL_MIN_EXP);
  printf("  DBL_MAX %E\n", DBL_MAX);
  printf("  DBL_MIN %E\n", DBL_MIN);
  
}
