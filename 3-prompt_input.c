#include "shell.h"

/**
 * getINPUT - Prompt and accept user command
 *
 * Description: This function display prompt
 * and then read user command
 *
 * Return: The pointer to the input command
 */
char *getINPUT(void)
{
	char *buff = NULL;
	int n;
	size_t size = 0;

	write(STDOUT_FILENO, "#cisfun$ ", 9);

	/* Handle error in reading input */
	if (getline(&buff, &size, stdin) == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}

	n = _strlen(buff);

	/* Remove the trailing "\n" character */
	if (n > 0 && buff[n - 1] == '\n')
		buff[n - 1] = '\0';

	return (buff);
}
