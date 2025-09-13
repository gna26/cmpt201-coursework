#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Please enter some text: ");
  char *buff = NULL;
  size_t size = 0;
  ssize_t num_char = getline(&buff, &size, stdin);
  if (num_char == -1) {
    perror("getline failed");
    exit(EXIT_FAILURE);
  }
  printf("Tokens:\n");
  char *saveptr;
  char *ret = strtok_r(buff, " ", &saveptr);
  printf("%s \n", ret);
  while (ret) {
    ret = strtok_r(NULL, " ", &saveptr);
    if (ret) {
      printf("%s \n", ret);
    }
  }

  free(buff);
}
