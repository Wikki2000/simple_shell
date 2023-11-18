#include "shell.h"

/**
 * _setenv - set an environment variable
 * @name: name of environment variable
 * @value: value of environment variable
 * @overwrite: (0) - don't overwrite, (1) - overwrite.
 * Return: (0) - success : (-1) - on error
 */

int _setenv(char *name, char *value, int overwrite)
{
        char *new_env;
        int size;

        /* len = len(name) +len(value) + len('=') + len('\0') */
        size = strlen(name) + strlen(value) + 2;
        new_env = malloc(sizeof(char) * size);
        if (new_env == NULL)
                return (-1);
        /* construct the new environment */
        strcpy(new_env, name);
        strcat(new_env, "=");
        strcat(new_env, value);
        strcat(new_env, "\0");
        if (_getenv(name) == NULL)
        {
                if (_putenv(new_env) == -1)
                        return (-1);
        }
        else
        {
                if (overwrite == 0)
                        free(new_env);
                else
                {
                        if (_unsetenv(name) == -1)
                                return (-1);
                        if (_putenv(new_env) == -1)
                                return (-1);
                }
        }
        return (0);
}

/**
 * _getenv - check if an environment variable exist
 * @name: name of the environment variable
 * Return: 1 (exist) 0 (does not exist)
 */

char *_getenv(char *name)
{
        int i;
        char *env;

        i = 0;
        while (environ[i])
        {
                env = _strnstr(environ[i], name, _strlen(name));
                if (env)
                        return (env);
                i++;
        }
        return (NULL);
}

/**
 * _putenv - put an environment variable into a list of env variables
 * @new_env: name of the env variable
 * Return: (0) - success, (-1) - error
 */

int _putenv(char *new_env)
{
        int i, j;
        char **env_array, *tmp, **tmp1;

        i = 0;
        while (environ[i])
                i++;
        env_array = malloc(sizeof(char *) * (i + 2));
        if (env_array == NULL)
        {
                free(new_env);
                return (-1);
        }
        for (i = 0; environ[i]; i++)
        {
                tmp = strdup(environ[i]);
                if (tmp == NULL)
                {
                        for (j = i - 1; j >= 0; j--)
                                free(env_array[j]);
                        free_memory(env_array);
                        free(new_env);
                        return (-1);
                }
                env_array[i] = tmp;
        }
        env_array[i] = new_env;
        i++;
        env_array[i] = NULL;
        tmp1 = environ;
        environ = env_array;
        free_memory(tmp1);
        return (0);
}
