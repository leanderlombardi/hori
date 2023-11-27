#include "include/error.h"
#include <stdio.h>
#include <stdlib.h>

/* ERRORS */

void throw_error(char *fp, int code, int line, int ch, char *text) {
  printf("<Error> [%i] in file '%s', %i:%i: %s\n", code, fp, line, ch, text);
  exit(code);
}

void throw_null_use_error(char *fp, int line, int ch, char *text) {
  printf("<NullUseError> [2] in file '%s', %i:%i: %s\n", fp, line, ch, text);
  exit(2);
}

void throw_parsing_error(char *text) {
  printf("<ParsingError> [1] in file 'src/parser.c': %s\n", text);
  exit(1);
}

void throw_error_error() {
  printf("<ErrorError> [755] in file 'src/error.c': Undefined error behavior\n");
  exit(755);
}

/* WARNINGS */

void throw_warning(char *fp, int code, int line, int ch, char *text) {
  printf("<Warning> %i in file '%s', %i:%i: %s\n", code, fp, line, ch, text);
}

void throw_null_use_warning(char *fp, int line, int ch, char *text) {
  printf("<NullUseWarning> [1] in file '%s', %i:%i: %s\n", fp, line, ch, text);
}

