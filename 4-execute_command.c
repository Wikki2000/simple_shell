#include "shell.h"

/**
 * executeCOMMAND - Execute a command in a child process
 * @args: Array of strings representing the command and its arguments
 * @envp: Array of strings representing the environment variables
 *
 * Description: This function creates a child process using fork()
 * and executes the command using execve.
 *
 * Return: Void
 */
void executeCOMMAND(char *args[], char **envp, char *exec)
{
	pid_t babyPROCCESS = fork();

	if (babyPROCCESS == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (babyPROCCESS == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror(exec);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

