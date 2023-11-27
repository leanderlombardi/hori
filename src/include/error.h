#ifndef ERROR_H
#define ERROR_H

/* ERRORS */

void throw_error(char *fp, int code, int line, int ch, char *text);

void throw_null_use_error(char *fp, int line, int ch, char *text);

void throw_parsing_error(char *text);

void throw_error_error();

/* WARNINGS */

void throw_warning(char *fp, int code, int line, int ch, char *text);

void throw_null_use_warning(char *fp, int line, int ch, char *text);

#endif // ERROR_H

