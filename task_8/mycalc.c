// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main() {
  
  int input, a, b, result;
  typedef enum
      {add = 1,
       sub,
       mul,
       div,
       exit
      } Menu;
  Menu menu_item;

  do {
    printf ("1. Add\n"
            "2. Subtract\n"
            "3. Multiply\n"
            "4. Divide\n"
            "5. Exit\n\n");
  
    printf("Enter menu item number (1 to 5): ");
    if (scanf ("%d", &input) != 1) {
      printf("Invalid input! Program terminated!\n");
      return 1;
    }

    if (input >= add && input <= div) {
      printf("Enter two integers: ");
      scanf ("%d %d", &a , &b);

      menu_item = (Menu)input;

      switch (menu_item) {
        case add:
          result = Add(a, b);
          break;
        case sub:
          result = Sub(a, b);
          break;
        case mul:
          result = Mul(a, b);
          break;
        case div:
          result = Div(a, b);
          break;
        case exit:
          break;
      }
      printf("Result is: %d!\n\n", result);
    } else if (input == exit) {
      printf("Program is complete!\n");
    } else {
      printf("Invalid menu item number! Please, try again!\n\n");
    }

  } while (input != exit);

  return 0;
}
