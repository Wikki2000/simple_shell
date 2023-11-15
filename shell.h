#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 128
#define MAX_COMMAND_LENGTH 64

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void executeCOMMAND(char **args, char *exec);
int _strlen(const char *string);
char *getINPUT(void);

#endif
