// Copyright <dimrimoff>

#ifndef MYFUNCS_H
#define MYFUNCS_H

typedef struct {
  char *name;
  char *second_name;
  char *phone_number;
} Abonent;

typedef struct {
  Abonent *abonents;
  int size;
} Phonebook;

void InputData(char *, char *);

int CountChars(char *);

int CompareString(char *, char *);

void MenuFind(Phonebook *);

void MenuDelete(Phonebook *);

void MenuOutput(Phonebook *);

void MenuAdd(Phonebook *);

int MenuShow(Phonebook *);

void PrintBinary(int);

int CountOnes(int);

int EnterPositive(void);

int EnterNegative(void);

#endif
