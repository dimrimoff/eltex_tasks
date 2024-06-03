// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include "myfuncs.h"

void InputData(char *str, char *data) {
    printf("Input %s of abonent (max 9 symbols): ", data);
    scanf("%9s[^\n]", str);
    getchar();
    if (CountChars(str) == 9) {
      while (getchar() != '\n');
    }
}

int CountChars(char *str) {
  int count = 0;
  while (*str != 0) {
    count++;
    str++;
  }
  return count;
}
  
int CompareString(char *str1, char *str2) {
  while (*str1 && *str2) {
    if (*str1 != *str2) {
      return 0;
    }
    str1++;
    str2++;
  }
  return (*str1 == 0 && *str2 == 0);
}

void MenuFind(Phonebook *pbook) {
  char name_find[10];
  InputData(name_find, "name");
  printf("\n");
  for (int i = 0; i < pbook->size; i++) {
    if (CompareString(pbook->abonents[i].name, name_find)) {
      printf("%3d. Name: %-10s ", i + 1, pbook->abonents[i].name);
      printf("Second name: %-10s ", pbook->abonents[i].second_name);
      printf("Phone number: %-10s\n", pbook->abonents[i].phone_number);
      }
    }
  printf("RECORDS FOUND!\n\n");
}

void MenuDelete(Phonebook *pbook) {
  char name_delete[10];
  InputData(name_delete, "name");
  printf("\n");
  for (int i = 0; i < pbook->size; i++) {
    if (CompareString(pbook->abonents[i].name, name_delete)) {
      printf("%3d. Name: %-10s ", i + 1, pbook->abonents[i].name);
      printf("Second name: %-10s ", pbook->abonents[i].second_name);
      printf("Phone number: %-10s\n", pbook->abonents[i].phone_number);
    }
  }
  for (int i = 0; i < pbook->size; i++) {
    if (CompareString(pbook->abonents[i].name, name_delete)) {
      Abonent temp = pbook->abonents[i];
      for (int j = i; j < pbook->size - 1; j++) {
        pbook->abonents[j] = pbook->abonents[j+1];
      }
      pbook->abonents[pbook->size-1] = temp;
      i--;
      pbook->size--;
    }
  }
  pbook->abonents = (Abonent *)realloc(pbook->abonents,
                     (pbook->size) * sizeof(Abonent));
  if (pbook->abonents == NULL) {
    printf("Error of memory allocation!\n");
    exit(1);
  } else {
  printf("RECORDS DELETED!\n\n");
  }
}

void MenuOutput(Phonebook *pbook) {
  for (int i = 0; i < pbook->size; i++) {
    printf("%3d. Name: %-10s ", i + 1, pbook->abonents[i].name);
    printf("Second name: %-10s ", pbook->abonents[i].second_name);
    printf("Phone number: %-10s\n", pbook->abonents[i].phone_number);
  }
  printf("\n");
}

void MenuAdd(Phonebook *pbook) {
    pbook->abonents = (Abonent *)realloc(pbook->abonents,
                     (pbook->size + 1) * sizeof(Abonent));
    if (pbook->abonents == NULL) {
    printf("Error of memory allocation!\n");
    exit(1);
  }
  char name[10], second_name[10], phone_number[10];
  InputData(name, "name");
  InputData(second_name, "second name");
  InputData(phone_number, "phone number");
  pbook->abonents[pbook->size].name = (char*)malloc(10);
  pbook->abonents[pbook->size].second_name = (char*)malloc(10);
  pbook->abonents[pbook->size].phone_number = (char*)malloc(10);
  for (int i=0; i < 10; i++) {
    pbook->abonents[pbook->size].name[i] =  name[i];
    pbook->abonents[pbook->size].second_name[i] =  second_name[i];
    pbook->abonents[pbook->size].phone_number[i] =  phone_number[i];
  }
  pbook->size++;
  printf("\n%3d. Name: %-10s ", pbook->size, name);
  printf("Second name: %-10s ", second_name);
  printf("Phone number: %-10s\n", phone_number);
  printf("RECORD ADDED!\n\n");
}

int MenuShow(Phonebook *pbook) {
  int number;
  printf ("1. Add abonent\n"
          "2. Delete abonent by name\n"
          "3. Find abonent by name\n"
          "4. Display all records\n"
          "5. Exit\n\n");
  printf("%d records entered\n\n", pbook->size);
  printf("Enter menu item number: ");
  scanf ("%d", &number);
  return number;
}

