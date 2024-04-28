// Copyright 2024 <dimrimoff>
#include <stdio.h>
#define N 10

int main() {
  int array[N];
      
  for (int i = 0; i < N; i++) {
    array[i] = i + 1;
  }

  for (int i = 0; i < N/2; i++) {
    int t;
    t = array[i];
    array[i] = array[N - 1 - i];
    array[N - 1 - i] = t;
 }

  
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
  return 0;
}
