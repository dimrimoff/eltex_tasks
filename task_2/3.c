// Copyright 2024 <dimrimoff>

#include <stdio.h>
#define N 9

int main() {
  int array[N][N];
    
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j < N - i - 1) {
        array[i][j] = 0;
      } else {
        array[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
