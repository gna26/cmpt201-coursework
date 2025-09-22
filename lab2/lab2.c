#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  char *buff = NULL;
  size_t size = 0;

  printf("Enter programs to run.\n");
  while (true) {
    printf("> ");
    fflush(stdout);

    if (getline(&buff, &size, stdin) != -1L) {

      char *intput_str = buff;
      char *delm = " \t\n\r";
      char *token = NULL;
      char *saveptr = NULL;

      token = strtok_r(intput_str, delm, &saveptr);
      if (token == NULL) {
        continue;
      }

      char *program = token;

      pid_t pid = fork();
      if (pid == -1) {
        perror("fork");
        continue;
      }

      if (pid == 0) {
        execl(program, program, (char *)NULL);

        perror("Exec failure");
        exit(1);
      } else {
        int status;
        waitpid(pid, &status, 0);
      }
    }

    free(buff);
  }
  return 0;
}
