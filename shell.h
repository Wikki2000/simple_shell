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

int _strlen(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
ssize_t _getline(char **inputPTR, size_t *size, int input_STREAM);
int handle_failure(char *ptr);
void add_current_dir_to_path();
char *getINPUT();
int stringCOMPARE(const char *str1, const char *str2, int index);
char *_strchr(const char *str, int c);
char *_strtok(char *str, const char *delim);
void executeCOMMAND(char **args, char **envp);

#endif
