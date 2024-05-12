// Copyright 2024 <dimrimoff>
#include <stdio.h>
#include "myfuncs.h"

int main() {
  
  struct Abonent phonebook[100];

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 10; j++) {
      phonebook[i].name[j] = 0;
      phonebook[i].second_name[j]= 0;
      phonebook[i].phone_number[j]= 0;
    }
  }
  
  enum menu {add = 1, delete, find, output, exit};
  enum menu menu_item;
  do {
    printf("\nMenu number %d selected\n\n", menu_item = MenuShow(phonebook));
    switch (menu_item) {
      case add:
        MenuAdd(phonebook);
        break;
      case delete:
        MenuDelete(phonebook);
        break;
      case find:
        MenuFind(phonebook);
        break;
      case output:
        MenuOutput(phonebook);
        break;
      case exit:
        break;
      default:
        break;
    }
  } while (menu_item != exit);
  
  return 0;
}
