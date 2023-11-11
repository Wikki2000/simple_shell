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
	char *command;

	command = (char *) malloc(sizeof(char));
	if (command == NULL)
	{
		perror("Malloc fail");
		exit(EXIT_FAILURE);
	}

	if (_strncmp(args[0], "/bin/", 5) == 0)
		strcpy(command, args[0]);
	else
	{
		strcpy(command, "/bin/");
		strcat(command, args[0]);
	}

	if (access(command, X_OK) == 0)
	{
		if (babyPROCCESS == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (babyPROCCESS == 0)
		{
			execve(command, args, envp);
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	else
		perror("./hsh");
}
