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
	char command[100];
	pid_t babyPROCCESS;
	int count =  1;

	/* Check if full command path is given or not */
	if (args[0][0] == '/')
		_strcpy(command, args[0]);
	else if (args[0][0] == '.')
		_strcpy(command, args[0]);
	else
	{
		_strcpy(command, "/bin/");
		_strcat(command, args[0]);
	}

	/* Check if command exist */
	if (access(command, X_OK) == 0)
	{
		babyPROCCESS = fork();
		if (babyPROCCESS == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (babyPROCCESS == 0)
		{
			execve(command, args, envp);
			exit(EXIT_SUCCESS);
		}
		else
			wait(NULL);
	}
	else
	{
		write(STDOUT_FILENO, "./hsh: 1: ", 10);
		write(STDOUT_FILENO, command, _strlen(command));
		write(STDOUT_FILENO, ": not found", 11);
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}
}
