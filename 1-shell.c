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
	char *input = NULL;
	size_t size = 0;
	pid_t babyPROCCESS = fork();
	char **args;

	for (;;)
	{
		write(STDOUT_FILENO, "# ", 2);
		if (getline(&input, &size, stdin) == -1)
		{
			perror("getline failed");
			free(input);
			exit(EXIT_FAILURE);
		}

		args = (char **) malloc(sizeof(char *) * _strlen(input));
		if (args == -1)
		{
			perror("Memory allocation failed");
			free(input);
			free(args);
			exit(EXIT_FAILURE);
		}
		args[0] = input;
		args[1] = NULL;
		if (babyPROCCESS == -1)
		{
			perror("fork failed");
			free(input);
			free(args);
			exit(EXIT_FAILURE);
		}
		else if (babyPROCCESS == 0)
		{
			if (excecve(args[0], args, envp) == -1)
			{
				perror("./hsh");
				free(input);
				free(args);
			}
		}
		else
			wait(NULL);
	}
		free(input);
		free(args);
		return (0);
}
