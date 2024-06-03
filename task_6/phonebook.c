// Copyright 2024 <dimrimoff>
#include <stdio.h>
#include <stdlib.h>
#include "myfuncs.h"

int main() {
  
  Phonebook *phonebook = (Phonebook *)malloc(sizeof(Phonebook));
  phonebook->abonents = NULL;
  phonebook->size = 0;

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

  for (int i = 0; i < phonebook->size; i++) {
    free(phonebook->abonents[i].name);
    free(phonebook->abonents[i].second_name);
    free(phonebook->abonents[i].phone_number);
  }

  free(phonebook->abonents);
  free(phonebook);
  
  return 0;
}
