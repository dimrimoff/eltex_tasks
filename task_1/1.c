// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include "myfuncs.h"

int main() {
  int input_positive = EnterPositive();
    
  printf("Binary representation of positive number %d: \n",
         input_positive);
  PrintBinary(input_positive);
  
  return 0;
}
