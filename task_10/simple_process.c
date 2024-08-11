// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status;
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork failed");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    printf("I am child, my pid is %d, my parent pid is %d\n",
           getpid(), getppid());
    exit(100);
  } else {
  printf ("I am parent, my pid is %d, my parent pid is %d\n",
           getpid(), getppid());
  
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
