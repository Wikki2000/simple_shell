#include "shell.h"

void executeCOMMAND(char **argv, char **envp)
{
	pid_t babyPROCCESS;

	if (babyPROCCESS < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (babyPROCCESS == 0)
	{
		execve(argv[0], argv, envp);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free(argv[0]);
	}
}
