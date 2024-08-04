// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int error_cnt;

void* load_func(void *handle, const char* func_name) {
  void* func = dlsym(handle, func_name);
  char* error = dlerror();
  if (error != NULL) {
    printf("%s\n", error);
    error_cnt++;
  }
  return func;
}

int main() {

  void *lmycalc_p = dlopen("libmycalc.so", RTLD_LAZY);
  if (lmycalc_p == NULL) {
    printf("%s\n", dlerror());
    exit(1);
  }
  
  int (*mycalc[4])(int,int);
  mycalc[0] = load_func(lmycalc_p,"Add");
  mycalc[1] = load_func(lmycalc_p,"Sub");
  mycalc[2] = load_func(lmycalc_p,"Mul");
  mycalc[3] = load_func(lmycalc_p,"Div");

  if (error_cnt > 0) {
    exit(1);
  }
  
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
          result = mycalc[0](a, b);
          break;
        case sub:
          result = mycalc[1](a, b);
          break;
        case mul:
          result = mycalc[2](a, b);
          break;
        case div:
          result = mycalc[3](a, b);
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

  dlclose(lmycalc_p);
  return 0;
}
