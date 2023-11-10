#include "shell.h"

/**
 *  str_tokenize - tokenize a command accepted from user
 * @input: user input to be tokenized
 * @args: buffer to store the tokenized string
 *
 * Return: array of tokenized user input
 */

char **str_TOKENIZE(char *input, char **args)
{
	char *token = NULL;
	int ac = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[ac] = token;
		ac++;
		token = strtok(NULL, " ");
	}
	args[ac] = NULL;
	return (args);
}

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

	while (1)
	{
		val = getINPUT(&input, &size);
		if (val == -1)
			break;
		if (_strlen(input) == 0)
			continue;
		if (stringCOMPARE(input, "exit", 0) == 0)
			exit(EXIT_SUCCESS);
		args = (char **)malloc(sizeof(char *) * 100);
		if (args == NULL)
		{
			perror("Memory allocation fail");
			exit(EXIT_FAILURE);
		}
		str_TOKENIZE(input, args);
		executeCOMMAND(args, envp);
		free(args);
	}
	free(input);
	return (0);
}
