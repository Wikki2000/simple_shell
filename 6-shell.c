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
	add_current_dir_to_path();

	while (1)
	{
		int i;
		char *input = getINPUT();
		char *token;
		pid_t babyPROCCESS = fork();

		/* Ignore empty input */
		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}

		/* Implement exit functuion */
		if (stringCOMPARE(input, "exit", 0) == 0)
			exit(EXIT_SUCCESS);

		/* Allocate memory to store arguement */
		args = (char **) malloc(sizeof(char *) * 100);
		if (args == NULL)
		{
			perror("Memory allocation fail");
			exit(EXIT_FAILURE);
		}

		/* Split the input into command and arguments */
                token  = strtok(input, " ");
		args[0] = token;

		for (i = 1; i < argc; i++)
			args[i] = strtok(NULL, " ");
		args[argc] = NULL;

		if (babyPROCCESS < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (babyPROCCESS == 0)
		{
			execve(args[0], args, envp);
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			free(input);
		}	
	}

	return (0);
}
