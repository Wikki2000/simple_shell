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
		int i;
		char *input = getINPUT();
		char *token;
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

		token  = strtok(input, " ");
		command[0] = token;
		for (i = 1; token != NULL; i++)
		{
			token = strtok(NULL, " ");
			command[i] = token;
		}
		command[i] = NULL;
		executeCOMMAND(command, envp);
		free(input);
	}
	return (0);
}
