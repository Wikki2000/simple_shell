#include "shell.h"
/**
 * _unsetenv - remove an environ variable
 * @name: name of the environment variable to remove
 * Return: (0) - successful, (-1) - failure
 */

int _unsetenv(char *name)
{
        int i, j;

        i = 0;
        while (environ[i])
                i++;
        if (_getenv(name) == NULL)
                return (-1);
        for (i = 0; environ[i]; i++)
        {
                if (_strnstr(environ[i], name, strlen(name)))
                {
                        free(environ[i]);
                        environ[i] = NULL;
                        for (j = i; environ[j + 1]; j++)
                                environ[j] = environ[j + 1];
                        environ[j] = NULL;
                }
        }
        return (0);
}
