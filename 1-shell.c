#include "shell.h"

int main(int argc, char *argv[], char *envp[]) {
    char *input = NULL;
    size_t size = 0;
    pid_t wpid;
    bool is_pipe = !isatty(STDIN_FILENO);  // Check if input is coming from a pipe
    ssize_t bytes;

    if (is_pipe) {
        // If input is from a pipe, read directly from stdin
        bytes = getline(&input, &size, stdin);

        if (bytes == -1) {
            perror("getline failed");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (input[bytes - 1] == '\n')
            input[bytes - 1] = '\0';

        char *args[20];
        // Tokenize the input to form the argument list
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < 19) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  // Null-terminate the argument list

        // Fork and execute the command
        wpid = fork();
        if (wpid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (wpid == 0) {
            // In the child process
            execvp(args[0], args);
            
            // If execvp fails, print an error message
            perror("execvp failed");
            exit(EXIT_FAILURE);
        } else {
            // In the parent process
            wait(NULL);
        }

        free(input);
    } else {
        // Interactive mode
        while (1) {
            write(STDOUT_FILENO, "# ", 2);
            bytes = getline(&input, &size, stdin);
            
            if (bytes == -1) {
                perror("getline failed");
                free(input);
                exit(EXIT_FAILURE);
            }

            if (input[bytes - 1] == '\n')
                input[bytes - 1] = '\0';

            char *args[20];
            // Tokenize the input to form the argument list
            char *token = strtok(input, " ");
            int i = 0;
            while (token != NULL && i < 19) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;  // Null-terminate the argument list

            // Fork and execute the command
            wpid = fork();
            if (wpid == -1) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            } else if (wpid == 0) {
                // In the child process
                execvp(args[0], args);
                
                // If execvp fails, print an error message
                perror("execvp failed");
                exit(EXIT_FAILURE);
            } else {
                // In the parent process
                wait(NULL);
            }
        }

        free(input);
    }

    return 0;
}
