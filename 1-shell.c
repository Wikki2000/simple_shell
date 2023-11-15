#include "shell.h"

/**
 * main - Entry point of program
 * @argc: Command-line arguement count
 * @args: An array of command-line arguement
 * @envp: Environment variable
 *
 * Description: This program implement a simple shell
 *
 * Return: Always (0)
 */
int main(int argc, char **args, char **envp)
{
	(void)args;
	(void)argc;

	for (;;)
	{
		char *input = getINPUT();
		char **command;

		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}

		command = (char **) malloc(sizeof(char *) * 100);
		if (command == NULL)
		{
			perror("Memory allocation fail");
			exit(EXIT_FAILURE);
		}

		command[0] = input;
		command[1] = NULL;
		for (i = 0; command[i]; i++)
			free(command[i]);
		executeCOMMAND(command, envp);
		free(input);
		free(command);
	}
	return (0);
}
