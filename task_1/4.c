// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include "myfuncs.h"

int main() {
  int input_positive = EnterPositive();
  int new_byte;
  
  printf("Binary representation of %d: \n", input_positive);
  PrintBinary(input_positive);
    
  do {
    printf("Enter a new value for the third byte (integer in 0...255): ");
    scanf("%d", &new_byte);
    if (new_byte < 0 || new_byte > 255) printf("Integer is not in 0...255 \n");
  } while (new_byte < 0 || new_byte > 255);

  PrintBinary(new_byte);
  int result = (input_positive & 0xFF00FFFF) | (new_byte << 16);
  printf("Result after replacing the third byte: %d\n", result);
  PrintBinary(result);

  return 0;
}
