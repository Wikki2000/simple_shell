#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define FILE_NOT_EXIST 2
#define ILLEGAL_NUMBER 2
#define COMMAND_NOT_EXIST 127
#define BUFFSIZE 1024
#define NOT_BUILTIN -50


extern char **environ;


void free_memory(char **tokens);
void getINPUT(void);
int get_N_token(char *buffer, char *sep);
char **tokenize_buffer(char *buffer, char *sep);
int handle_rbyte(char *buffer, int rbyte, int *ret_code, char **env);
int handle_execution(char **tokens, char *filename, char **env, int *n);
void handle_error(char *filename, char *cmd, int n);
char *int_to_str(int count);
char *build_full_path(char *cmd, char **env);
int handle_path(char **tokens, char *filename, char **env, int *ret_code);
int process_cmd(char **tokens, char *filename, char **env, int *ret_code);
char *_strnstr(char *haystack, char *needle, int n);
void handle_cd_error(char *filename, char **tokens, int n, char *msg);
char *_strtok(char *str, char *sep);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char **dynamic_env(char **env);
void print_env_error(char *file, char *msg);
char *special_char(char **tokens);
int flush(char **tokens, int *status);

#endif
