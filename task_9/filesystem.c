// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
  int file =  open("output.txt", O_CREAT | O_WRONLY, 0644);
  if (file == -1) {
    printf("Opening file error!\n");
    return 1;
  }

  char str[] = "String from file";
  write(file, str, strlen(str));

  close(file);

  file = open("output.txt", O_RDONLY);
  if (file == -1) {
    printf("Opening file error!\n");
    return 1;
  }

  char buffer[strlen(str)];
  int i = strlen(str) - 1;
  while (i >= 0) {
    read(file, &buffer[i], 1);
    i--;
  }

  printf("String from file backwards: %s\n", buffer);

  close(file);

  return 0;

}
