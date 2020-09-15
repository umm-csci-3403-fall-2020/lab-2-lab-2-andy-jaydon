#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;
  char *result; //Initialize new variable to store mem made from running palindrome

  size = 100;
  line = (char*) calloc (size + 1, sizeof(char)); //store mem

  // fgets reads a line from stdin (usually the keyboard)
  // and returns it in the buffer passed as the first argument
  // (line here). If there's no more input to read from, it
  // returns NULL.
  while (fgets(line, size, stdin) != NULL) {
    // This crazy line removes the '\n' at the end of the input line.
    // Without it, nothing will ever be a palindrome, unless it happens
    // to somehow start with a '\n'.
    line[strcspn(line, "\n")] = '\0';
    result = palindrome(line);
    printf("Is the stirng <%s> a palindrome? %s\n", line, result);
    free(result); //Free mem stored from running palindrome
  }
  free(line); //Free mem stored in main
}
