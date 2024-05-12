// Copyright <dimrimoff>

#ifndef MYFUNCS_H
#define MYFUNCS_H

struct Abonent {
    char name[10];
    char second_name[10];
    char phone_number[10];
  };

void InputData(char *, char *);

int CountChars(char *);

int CompareString(char *, char *);

void MenuFind(struct Abonent[]);

void MenuDelete(struct Abonent *);

void MenuOutput(struct Abonent[]);

void MenuAdd(struct Abonent[]);

int MenuShow(struct Abonent[]);

void PrintBinary(int);

int CountOnes(int);

int EnterPositive(void);

int EnterNegative(void);

#endif
