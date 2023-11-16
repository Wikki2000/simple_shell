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
#include <stdbool.h>

void execute_command(char **args, char **envp);
int _strlen(const char *string);
char **strTOKENIZE(char *input, char **args);
#endif
