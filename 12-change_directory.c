#include "shell.h"

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
		directory = getenv("HOME");
	else if (_strncmp(input, "cd ", 3) == 0)
		directory = strtok(input + 3, " ");

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
			setenv("PWD", cwd, 1);
		else
			perror("getcwd failed");
	}

}
