#include "shell.h"

/**
 * _getenv - Function that gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *name)
{
        int len, i;

        len = _strlen(name);

        /* Iterate through each environment variable */
        for (i = 0; environ[i]; i++)
        {
                /* Check if the variable matches the provided name */
                if (_strncmp(environ[i], name, len) == 0)
                {
                        /* Return the value of the environment variable */
                        return (environ[i] + len + 1);
                }
        }

        return (NULL);
}

/**
 * changeDIRECTORY - Change CWD to a specified directory enter by user
 * @input: The command enter to change directory
 *
 * Return: Void
 */
void changeDIRECTORY(char *input)
{
        char cwd[100];
        char *directory = NULL;

        if (stringCOMPARE(input, "cd", 0) == 0)
                directory = _getenv("HOME");
        else if (_strncmp(input, "cd ", 3) == 0)
                directory = _strtok(input + 3, " ");

        if (chdir(directory) == -1)
        {
                write(STDOUT_FILENO, "./hsh: 1: cd: can't cd to ", 26);
                write(STDOUT_FILENO, directory, _strlen(directory));
                write(STDOUT_FILENO, "\n", 1);
        }

        /* Update the PWD environment variable */
        else
        {
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                        _setenv("PWD", cwd, 1);
                else
                        perror("getcwd failed");
        }

}
