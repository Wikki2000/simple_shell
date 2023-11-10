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
	char *input = NULL, **args = NULL;
	size_t size = 0;
	int val;

	(void)argc;
	(void)argv;

	for (;;)
	{
		val = getINPUT(&input, &size);
		if (val == -1)
			break;
		if (_strlen(input) == 0)
			continue;
		if (stringCOMPARE(input, "exit", 0) == 0)
			exit(EXIT_SUCCESS);

		else if (stringCOMPARE(input, "env", 0) == 0)
		{
			printENV();
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
