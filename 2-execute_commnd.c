#include "shell.h"

void execute_command(char **args, char **envp)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(args[0], args, envp);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    else 
        wait(NULL);
}
