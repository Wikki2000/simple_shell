#include "shell.h"

/**
 * printENV - Print the current environment variables
 *
 * Return: Void
 */
void printENV(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

