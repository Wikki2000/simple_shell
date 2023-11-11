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
	char *paths = getenv("PATH"), *path = NULL, command[100];
	pid_t babyPROCCESS;
	int isError = 1;

	path = _strtok(paths, ":");
	while (path != NULL)
	{
		_strcpy(command, path);
		if (args[0][0] == '/')
			_strcpy(command, args[0]);
		else
			_strcat(command, args[0]);
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
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
			else
			{
				isError = 0;
				wait(NULL);
				break;
			}
		}
		path = _strtok(NULL, ":");
	}
	if (isError)
		perror("./hsh");
}
/**
 * _getenv - get path form the environmetal variable
 * @env_NAME: name of environmental variable
 *
 * Return: the value of the environmntal variable
 *
 * Description: This function extract the value of the external variable
 */
char *_getenv(char *env_NAME)
{
	int i, len;
	char *val;

	for (i = 0; environ[i] != NULL; i++)
	{
		val = _strchr(environ[i], '=');
		if (val != NULL)
		{
			len = val - environ[i];
			if (stringCOMPARE(environ[i], env_NAME, len) == 0 && env_NAME[len] == '\0')
			{
				return ((char *)(val + 1));
			}
		}
	}
	return (NULL);
}
