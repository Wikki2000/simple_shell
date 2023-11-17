#include "shell.h"

/**
 * main - entry point.
 * @argc: argument count from commandline
 * @envp: environment
 * @argv: pointer to an array of argument from commandline.
 * Return: succes code on success or error code on error
 */

int main(int argc, char **argv, char **envp)
{
	char *input, *delim, char **tokens, *buf;
	ssize_t read;
	size_t size;
	int retCODE = 0;

	sep = " \n\t";
	/* make the environment variable dynamic (resizeable) */
	environ = dynamic_env(envp);
	while (1)
	{
		input = NULL;
		tokens = NULL;
		buf = NULL;
		if (isatty(STDIN_FILENO))
			prompt_user();
		read = getline(&buffer, &buff_size, STDIN_FILENO);
		if (handleREAD(input, rbyte, &ret_code, environ) == 1)
			continue;
		buf = preprocess_strtok(buffer);
		tokens = tokenize_buffer(buf, sep);
		free(buf);
		if (tokens == NULL)
			continue;
		ret_code = process_cmd(tokens, argv[0], environ, &ret_code);
	}
	free_memory(environ);
	return (ret_code);
}
