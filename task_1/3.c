// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include "myfuncs.h"

int main() {
  int input_positive = EnterPositive();
    
  printf("Binary representation of %d: \n", input_positive);
  PrintBinary(input_positive);

  printf("Number of ones in the binary representation of %d: %d\n",
         input_positive, CountOnes(input_positive));

  return 0;
}
