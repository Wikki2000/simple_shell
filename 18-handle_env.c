#include "shell.h"
/**
 * builtin_command - builtin handler
 * @tokens: tokens array
 * @filename: executable filename
 * @env: environemnt variable
 * @n: return code
 * Return: 0 - success (-2) - not a builtin command
 */
int handle_builtin(char **tokens, char *filename, char **env, int *n)
{
        int m;
        if (_strncmp("setenv", tokens[0], 6) == 0)
        {
                m = handle_setenv(tokens, filename,env,n);
                return (m);
        }
        else if (_strncmp("unsetenv", tokens[0], 8) == 0)
        {
                m = handle_unsetenv(tokens, filename,env,n);
                return (m);
        }
        return (NOT_BUILTIN);
}
/**
 * handle_setenv - set an environment variable
 * @tk: tokens
 * @file: filename
 * @env: environment
 * @n: status code
 * Return: 0 - success
 */
int handle_setenv(char **tk, char *file, char **env, int *n)
{
        (void)env;

        if (tk[1] == NULL || (tk[1] != NULL && tk[2] == NULL))
        {
                print_env_error(file, "Invalid argument");
                free_memory(tk);
                return (*n);
        }
        if (_setenv(tk[1], tk[2], 1) == -1)
        {
                print_env_error(file, "Invalid argument");
                free_memory(tk);
                *n = -1;
                return (*n);
        }
        free_memory(tk);
        *n = 0;
        return (*n);
}

/**
 * handle_unsetenv - unset an environment variable
 * @tk: tokens
 * @file: filename
 * @env: environment
 * @n: status code
 * Return: 0 - success
 */
int handle_unsetenv(char **tk, char *file, char **env, int *n)
{
        (void)env;

        if (tk[1] == NULL)
        {
                print_env_error(file, "Invalid argument");
                free_memory(tk);
                *n = -1;
                return (*n);
        }
        if (_unsetenv(tk[1]) == -1)
        {
                handle_error(file, tk[0], *n);
                free_memory(tk);
                *n = -1;
                return (*n);
        }
        free_memory(tk);
        *n = 0;
        return (*n);
}
