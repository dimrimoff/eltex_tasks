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
  char *args1[MAX_ARGS], *args2[MAX_ARGS];
  pid_t pid1, pid2;
  int unnamed_pipe[2];
  int status;
  int found = 0;

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

    ParseInput(input, args1);
    
    for (int i = 0; args1[i] != NULL; i++) {
      if (strcmp(args1[i], "|") == 0) {
        args1[i] = NULL;  
        found = 1;
        int k = 0;
        for (int j = i + 1; args1[j] != NULL; j++, k++) {
          args2[k] = args1[j];
        }
        args2[k] = NULL;
        break;
      }
    }

    if (found) {
      if (pipe(unnamed_pipe) != 0) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
      }

      pid1 = fork();
      if (pid1 < 0) {
        perror("fork1 failed");
        exit(EXIT_FAILURE);
      } else if (pid1 == 0) { 
        close(unnamed_pipe[0]);
        dup2(unnamed_pipe[1], 1); 
        if (execvp(args1[0], args1) < 0) {
          perror("exec1 failed");
          exit(EXIT_FAILURE);
        }
      }

      pid2 = fork();
      if (pid2 < 0) {
        perror("fork2 failed");
        exit(EXIT_FAILURE);
      } else if (pid2 == 0) { 
        close(unnamed_pipe[1]);
        dup2(unnamed_pipe[0], 0);
        if (execvp(args2[0], args2) < 0) {
          perror("exec2 failed");
          exit(EXIT_FAILURE);
        }
      }

      close(unnamed_pipe[0]);
      close(unnamed_pipe[1]);

      waitpid(pid1, &status, 0);
      waitpid(pid2, &status, 0);

    } else {
      pid1 = fork();
      if (pid1 < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
      } else if (pid1 == 0) {
        if (execvp(args1[0], args1) < 0) {
          perror("exec failed");
          exit(EXIT_FAILURE);
        }
      } else {
        waitpid(pid1, &status, 0);
      }
    }
  }

  return 0;
}
