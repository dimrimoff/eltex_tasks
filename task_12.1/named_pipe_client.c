// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
  int named_pipe = open("named_pipe", O_RDONLY);

  if (named_pipe < 0) {
    perror("open failed");
    exit (EXIT_FAILURE);
  }

  char buffer[128];

  ssize_t num_bytes = read(named_pipe, buffer, sizeof(buffer) - 1);
  if (num_bytes == -1) {
    perror("read failed");
    close(named_pipe);
    exit(EXIT_FAILURE);
  }

  buffer[num_bytes] = '\0';
  printf("Received message: \"%s\"\n", buffer);

  close(named_pipe);

  return 0;
         
}
