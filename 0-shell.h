#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 64

int _strlen(char *str);
void add_current_dir_to_path();
char *getINPUT();
int stringCOMPARE(const char *str1, const char *str2, int index);
void executeCOMMAND(char **argv, char **envp);

#endif
