#include "shell.h"

void execute_command(char **args, char **envp) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // In the child process
        execve(args[0], args, envp);

        // If execvp fails, print an error message
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // In the parent process, wait for the child to finish
        wait(NULL);
    }
}
