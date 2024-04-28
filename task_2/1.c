// Copyright 2024 <dimrimoff>

#include <stdio.h>
#define N 8

int main() {
  int array[N][N];
  int count = 1;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      array[i][j] = count;
      count++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", array[i][j]);
      count++;
    }
    printf("\n");
  }
  return 0;
}
