// Copyright 2024 <dimrimoff>

#include <stdio.h>
#define N 10

int main() {
  int array[N];
  int *p_arr = array;
  
  for (int i = 0; i < N; i++) {
    array[i] = i + 1;
    }

  for (int i = 0; i < N; i++) {
    printf("%d ", *p_arr + i);
    }
    printf("\n");

  return 0;
}
