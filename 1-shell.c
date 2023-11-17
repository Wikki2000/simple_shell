#include "shell.h"

/**
 * main - entry point.
 * @argc: argument count from commandline
 * @envp: environment
 * @argv: pointer to an array of argument from commandline.
 * Return: succes code on success or error code on error
 */

int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
	char *input, *delim, **tokens;
	ssize_t read;
	size_t size = 0;
	int ret = 0;

	delim = " \n\t";
	environ = dynamic_env(envp);
	while (1)
	{
		input = NULL;
		tokens = NULL;
		if (isatty(STDIN_FILENO))
			getINPUT();
		read = getline(&input, &size, stdin);
		if (handle_rbyte(input, read, &ret, environ) == 1)
			continue;
		tokens = tokenize_buffer(input, delim);
		if (tokens == NULL)
			continue;
		ret = process_cmd(tokens, argv[0], environ, &ret);
		free(input);
	}
	free_memory(environ);
	return (ret);
}
