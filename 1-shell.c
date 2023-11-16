#include "shell.h"

int main(int argc, char **argv, char **envp)
{
	char *input = NULL;
	char **args;
	size_t size = 0;
	ssize_t bytes;
	bool is_pipe = true;

	(void)argc;
	(void)argv;

	while (is_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			is_pipe = false;

		write(STDOUT_FILENO, "# ", 2);
		bytes = getline(&input, &size, stdin);

		if (bytes == -1)
			exit(EXIT_FAILURE);

		if (input[bytes - 1] == '\n')
			input[bytes - 1] = '\0';

		args = (char **) malloc(sizeof(char **) * 100);
		if (args == NULL)
		{
			perror("Malloc failed");
			free(args);
			free(input);
			exit(EXIT_FAILURE);
		}
		strTOKENIZE(input, args);
		execute_command(args, envp);
		free(args);
	}

	return 0;
}

