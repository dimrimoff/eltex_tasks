// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MESSAGE
#define MESSAGE "Hi!"
#endif

int main() {
  int named_pipe;
  char *message = MESSAGE;

  if (mkfifo("named_pipe", 0777) < 0) {
    perror ("mkfifo failed");
    exit(EXIT_FAILURE);
  }

  named_pipe = open("named_pipe", O_WRONLY);
  
  if (named_pipe < 0) {
    perror("open failed");
    exit (EXIT_FAILURE);
  }
  
  if (write(named_pipe, message, strlen(message) + 1) < 0) {
    perror("write failed");
    close(named_pipe);
    exit(EXIT_FAILURE);
  }

  close(named_pipe);

  if (unlink("named_pipe") < 0) {
    perror("unlink failed");
    exit(EXIT_FAILURE);
  }
  
  printf("Message - \"%s\" - is transeived to client through"
         " the named pipe!\n", message);
  return 0;
         
}
