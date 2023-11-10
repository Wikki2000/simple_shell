#include "shell.h"

/**
 * getINPUT - Prompt and accept user command
 * @buff: The buffer to store user input
 * @size: The size of memory to be allocated
 *
 * Description: This function display prompt
 * and then read user command
 *
 * Return: The pointer to the input command
 */
int getINPUT(char **buff, size_t *size)
{
	int val, n;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	fflush(stdout);
	val = _getline(buff, size, STDIN_FILENO);

	if (val == -1)
		return (-1);
	n = _strlen(*buff);
	if (n > 0 && (*buff)[n - 1] == '\n')
		(*buff)[n - 1] = '\0';
	return (val);
}
