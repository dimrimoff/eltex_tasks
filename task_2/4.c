// Copyright 2024 <dimrimoff>

#include <stdio.h>
#define N 5

int array[N][N] = {0};
int row_start = 0, row_end = N - 1;
int col_start = 0, col_end = N - 1;
int count = 1;
  
int main() {
  
  while (row_start <= row_end && col_start <= col_end) {

    for (int i = col_start; i <= col_end; ++i) {
      array[row_start][i] = count++;
    }
    ++row_start;

    for (int i = row_start; i <= row_end; ++i) {
      array[i][col_end] = count++;
    }
    --col_end;

    if (row_start <= row_end) {
      for (int i = col_end; i >= col_start; --i) {
        array[row_end][i] = count++;
      }
      --row_end;
    }

    if (col_start <= col_end) {
      for (int i = row_end; i >= row_start; --i) {
        array[i][col_start] = count++;
      }
      ++col_start;
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
