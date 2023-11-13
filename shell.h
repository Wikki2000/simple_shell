#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 128
#define MAX_COMMAND_LENGTH 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int _strlen(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
ssize_t _getline(char **inputPTR, size_t *size, int input_STREAM);
int handle_failure(char *ptr);
int getINPUT(char **buff, size_t *size);
char *_strchr(const char *str, int c);
char *_strtok(char *str, const char *delim);
void executeCOMMAND(char **args, char **envp);
int stringCOMPARE(char *str1, char *str2, int index);
char **strTOKENIZE(char *input, char **args);
void printENV(void);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void changeDIRECTORY(char *input);
int print_decimal(int num);
int _putchar(char c);

#endif
