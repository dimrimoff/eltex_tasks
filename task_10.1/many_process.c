// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status1 ,status2, status3, status4, status5;
  pid_t pid1, pid2, pid3, pid4, pid5;
  
  pid1 = fork();
  
  if (pid1 < 0) {
    perror("fork process1 failed");
    exit(EXIT_FAILURE);
    
  } else if (pid1 == 0) {
    printf("I am process1, my pid is %d, my parent (main) pid is %d\n",
           getpid(), getppid());

    pid3 = fork();
    
    if (pid3 < 0) {
      perror("fork failed process3");
      exit(EXIT_FAILURE);
    } else if (pid3 == 0) {
      printf("I am process3, my pid is %d, my parent (process1) pid is %d\n",
             getpid(), getppid());
      exit(103);
    } else {

      pid4 = fork();
      
      if (pid4 < 0) {
        perror("fork process4 failed");
        exit(EXIT_FAILURE);
      } else if (pid4 == 0) {
        printf("I am process4, my pid is %d, my parent (process1) pid is %d\n",
               getpid(), getppid());
        exit(104);
      } else {
        
        if (waitpid(pid3, &status3, 0) == -1) {
          perror("wait process3 failed");
          exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status3)) {
          printf("Process3 exited with status = %d\n",
                 WEXITSTATUS(status3));
        } else {
          printf ("Process3 did not exit successfully\n");
        }

        if (waitpid(pid4, &status4, 0) == -1) {
          perror("wait process4 failed");
          exit(EXIT_FAILURE);
        }
    
        if (WIFEXITED(status4)) {
          printf("Process4 exited with status = %d\n",
                 WEXITSTATUS(status4));
        } else {
          printf ("Process4 did not exit successfully\n");
        }
      }
      exit(101);
    }
    
  } else {
    pid2 = fork();
    
    if (pid2 < 0) {
      perror("fork process2 failed");
      exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
      printf("I am process2, my pid is %d, my parent (main) pid is %d\n",
             getpid(), getppid());
      pid5 = fork();
      if (pid5 < 0) {
        perror("fork process5 failed");
        exit(EXIT_FAILURE);
      } else if (pid5 == 0) {
        printf("I am process5, my pid is %d, my parent (process2) pid is %d\n",
               getpid(), getppid());
        exit(105);
      } else {
        if (waitpid(pid5, &status5, 0) == -1) {
          perror("wait process5 failed");
          exit(EXIT_FAILURE);
        }
    
        if (WIFEXITED(status5)) {
          printf("Process5 exited with status = %d\n",
                 WEXITSTATUS(status5));
        } else {
          printf ("Process5 did not exit successfully\n");
        } 
      }
      
      exit(102);
    } else {
      printf ("I am parent (main), my pid is %d, my parent pid is %d\n",
              getpid(), getppid());
  
      if (waitpid(pid1, &status1, 0) == -1) {
        perror("wait process1 failed");
        exit(EXIT_FAILURE);
      }
    
      if (WIFEXITED(status1)) {
        printf("Process1 exited with status = %d\n",
               WEXITSTATUS(status1));
      } else {
        printf ("Process1 did not exit successfully\n");
      }

      if (waitpid(pid2, &status2, 0) == -1) {
        perror("wait process2 failed");
        exit(EXIT_FAILURE);
      }
    
      if (WIFEXITED(status2)) {
        printf("Process2 exited with status = %d\n",
               WEXITSTATUS(status2));
      } else {
        printf ("Process2 did not exit successfully\n");
      }
    }
    return 0;
  }
}
