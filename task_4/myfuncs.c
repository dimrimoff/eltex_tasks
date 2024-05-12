// Copyright 2024 <dimrimoff>

#include <stdio.h>
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

void MenuFind(struct Abonent s[]) {
  char name_find[10];
  InputData(name_find, "name");
  printf("\n");
  for (int i = 0; i < 100; i++) {
    if (CompareString(s[i].name, name_find)) {
      printf("%3d. Name: %-10s ", i + 1, s[i].name);
      printf("Second name: %-10s ", s[i].second_name);
      printf("Phone number: %-10s\n", s[i].phone_number);
      }
    }
  printf("RECORDS FOUND!\n\n");
}

void MenuDelete(struct Abonent s[]) {
  char name_delete[10];
  InputData(name_delete, "name");
  printf("\n");
  for (int i = 0; i < 100; i++) {
    if (CompareString(s[i].name, name_delete)) {
      printf("%3d. Name: %-10s ", i + 1, s[i].name);
      printf("Second name: %-10s ", s[i].second_name);
      printf("Phone number: %-10s\n", s[i].phone_number);
      for (int j = 0; j < 10; j++) {
        s[i].name[j] = 0;
        s[i].second_name[j] = 0;
        s[i].phone_number[j] = 0;
    }
  }
  }
  printf("RECORDS DELETED!\n\n");
}

void MenuOutput(struct Abonent s[]) {
  for (int i = 0; i < 100; i++) {
    printf("%3d. Name: %-10s ", i + 1, s[i].name);
    printf("Second name: %-10s ", s[i].second_name);
    printf("Phone number: %-10s\n", s[i].phone_number);
  }
  printf("\n");
}

void MenuAdd(struct Abonent s[]) {
  int i = 0;
  while (i < 100) {
    if (s[i].name[1] == 0) break;
    i++;
  }
  if (i < 100) {
    char name[10], second_name[10], phone_number[10];
    InputData(name, "name");
    InputData(second_name, "second name");
    InputData(phone_number, "phone number");
    for (int j = 0; j < 10; j++) {
      s[i].name[j] = name[j];
      s[i].second_name[j] = second_name[j];
      s[i].phone_number[j] = phone_number[j];
    }
    printf("\n%3d. Name: %-10s ", i, s[i].name);
    printf("Second name: %-10s ", s[i].second_name);
    printf("Phone number: %-10s\n", s[i].phone_number);
    printf("RECORD ADDED!\n\n");
  } else {
    printf("Record is beyound limit of the phonebook!\n"
           "Delete any record to free more space!\n\n");
  }
}

int MenuShow(struct Abonent s[]) {
  int number;
  int i = 0, count = 0;
  while (i < 100) {
    if (s[i].name[1] != 0) count += 1;
    i++;
  }
    printf ("1. Add abonent\n"
            "2. Delete abonent by name\n"
            "3. Find abonent by name\n"
            "4. Display all records\n"
            "5. Exit\n\n");
  printf("%d records entered\n\n", count);
  printf("Enter menu item number: ");
  scanf ("%d", &number);
  return number;
}

