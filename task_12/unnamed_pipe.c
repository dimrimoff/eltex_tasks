// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#ifndef MESSAGE
#define MESSAGE "Hi!"
#endif

int main() {
  int status;
  char *message = MESSAGE;
  int unnamed_pipe[2];
  if (pipe(unnamed_pipe) != 0) {
    perror ("pipe failed");
    exit(EXIT_FAILURE);
  }
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork failed");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    close(unnamed_pipe[1]);
    int i = strlen(message);
    char buffer[i];
    ssize_t num_bytes = read(unnamed_pipe[0], &buffer, i + 1);
    if (num_bytes == -1) {
      perror("read failed");
      exit(EXIT_FAILURE);
    }
    printf("String from unnamed pipe: %s\n", buffer);
    exit(EXIT_SUCCESS);
  } else {
    close(unnamed_pipe[0]);
    if (write(unnamed_pipe[1], message, strlen(message) + 1) < 0) {
      perror("write failed");
      exit(EXIT_FAILURE);
    }
    if (wait(&status) == -1) {
      perror("wait failed");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(status)) {
      printf("Child process exited with status = %d\n",
             WEXITSTATUS(status));
    } else {
      printf ("Child process did not exit successfully\n");
    }
  
    return 0;
  }
}
