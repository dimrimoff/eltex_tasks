// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include "myfuncs.h"

int main() {
  int input_negative = EnterNegative();
      
  printf("Binary representation of negative number %d: \n",
         input_negative);
  PrintBinary(input_negative);

  return 0;
}
