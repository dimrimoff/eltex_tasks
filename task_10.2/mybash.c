// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

void ParseInput(char *input, char **args) {
  char *token;
  int index = 0;

  token = strtok(input, " \n");
  while (token != NULL) {
    args[index++] = token;
    token = strtok(NULL, " \n");
  }
  args[index] = NULL;
}

int main() {
  char input[MAX_INPUT_SIZE];
  char *args[MAX_ARGS];
  pid_t pid;
  int status;

  while (1) {
    printf("Enter comand and list of arguments throught spaces "
           "('exit' for termination):\n");

    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
      perror("fgets error");
      continue;
    }

    if (strncmp(input, "exit", 4) == 0) {
      break;
    }

    ParseInput(input, args);

    pid = fork();
    if (pid < 0) {
      perror("fork failed");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      if (execvp(args[0], args) < 0) {
        perror("exec failed");
        exit(EXIT_FAILURE);
    }
    } else {
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}
