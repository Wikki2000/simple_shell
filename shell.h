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
void free2DMEMORY(char **tokens);

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
int builtin_command(char **tk, char *file, char **env, int *n);
int handle_exit(char **tk, char *file, char **env, int *);
int handle_setenv(char **tk, char *file, char **env, int *);
int handle_unsetenv(char **tk, char *file, char **env, int *);
int handle_env(char **tk, char *file, char **env, int *);
int _atoi(char *str);
void handle_exit_error(char *filename, char **tokens, int n, char *msg);
void handle_cd_error(char *filename, char **tokens, int n, char *msg);
char *_strtok(char *str, char *sep);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _unsetenv(char *name);
char **dynamic_env(char **env);
int _putenv(char *new_env);
char *_getenv(char *name);
int _setenv(char *name, char *value, int overwrite);
void print_env_error(char *file, char *msg);
int buf_overflow(int *, int *, char *, int *, char *, int *, size_t *);
int handle_cd(char **tk, char *file, char **env, int *n);
int cd_home(char *file);
char *getenv_value(char *env_name);
char *special_char(char **tokens);
int cd_path(char *file, char *path);
int cd_previous_path(char *file);
int flush(char **tokens, int *status);

#endif
