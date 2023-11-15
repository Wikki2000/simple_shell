#include "shell.h"

/**
 * main - Entry point of program
 * @argc: Command-line arguement count
 * @argv: An array of command-line arguement
 * @envp: Environment variable
 *
 * Description: This program implement a simple shell
 *
 * Return: Always (0)
 */
int main(int argc, char **argv, char **envp)
{
	char **args = NULL, *input = NULL;
	size_t size = 0;

	(void)argc;
	(void)argv;

	for (;;)
	{
		getINPUT(&input, &size);
		if (_strlen(input) == 0)
			continue;
		if (stringCOMPARE(input, "exit", 0) == 0)
			exit(EXIT_SUCCESS);
		else if (stringCOMPARE(input, "env", 0) == 0)
		{
			printENV();
			continue;
		}
		else if (_strncmp(input, "setenv", 6) == 0)
		{
			strTOKENIZE(input, args);
			_setenv(args[1], args[2], 1);
			free(args);
			continue;
		}
		else if (stringCOMPARE(input, "cd", 0) == 0 || strncmp(input, "cd ", 3) == 0)
		{
			changeDIRECTORY(input);
			continue;
		}
		else if (_strncmp(input, "#", 1) == 0)
		{
			free(input);
			continue;
		}
		args = (char **)malloc(sizeof(char *) * 100);
		if (args == NULL)
		{
			perror("Memory allocation fail");
			exit(EXIT_FAILURE);
		}
		strTOKENIZE(input, args);
		executeCOMMAND(args, envp);
		free(args);
	}
	free(input);
	return (0);
}
