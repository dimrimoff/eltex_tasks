// Copyright 2024 <dimrimoff>

#include <stdio.h>

int main() {
  float x = 5.0;
  printf("x = %f, ", x);
  float y = 6.0;
  printf("y = %f\n", y);
  float *xp = &y;
  float *yp = &y;
  printf("Result is: %f\n", *xp + *yp);
  
  return 0;
}
