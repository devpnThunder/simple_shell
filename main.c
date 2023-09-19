#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
unsigned int _ospaces(char *s);
char **stringSplit(char *s);

#endif /* SHELL_HEADER */
