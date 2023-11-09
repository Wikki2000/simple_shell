#include "shell.h"

/**
 * executeCOMMAND - Execute a command in a child process
 * @args: Array of strings representing the command and its arguments
 * @envp: Array of strings representing the environment variables
 *
 * Description: This function create a child process using fork()
 * and execute using execve.
 *
 * Return: Void
 */
void executeCOMMAND(char **args, char **envp)
{
	pid_t babyPROCCESS = fork();

	if (babyPROCCESS == -1)
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
		wait(NULL);
}
