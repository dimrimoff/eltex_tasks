// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include "myfuncs.h"

void PrintBinary(int number) {
  int i;
  for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
    printf("%d",(number >> i) & 1);
    if (!(i % 8) && i != 0) printf ("_");
  }
  printf("\n");
}

int CountOnes(int number) {
  int count = 0;
  while (number != 0) {
    count += number & 1;
    number >>= 1;
  }
  return count;
}

int EnterPositive() {
  int input_positive;

  do {
    printf("Enter a positive integer: ");
    scanf("%d", &input_positive);
    if (input_positive < 0) printf("Integer is negative\n");
  } while (input_positive < 0);

  return input_positive;
}

int EnterNegative() {
  int input_negative;

  do {
    printf("Enter a negative integer: ");
    scanf("%d", &input_negative);
    if (input_negative >= 0) printf("Integer is positive\n");
  } while (input_negative >= 0);

  return input_negative;
}
