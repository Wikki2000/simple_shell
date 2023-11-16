#include "shell.h"

int main(int argc, char **argv, char **envp) {
    char *input = NULL;
    char *args[20];
    size_t size = 0;
    ssize_t bytes;
    bool is_pipe = true;
    int i;

    while (1 && is_pipe) {
        if (isatty(STDIN_FILENO) == 0) {
            is_pipe = false;
        }

        write(STDOUT_FILENO, "# ", 2);
        bytes = getline(&input, &size, stdin);

        if (bytes == -1) {
            perror("getline failed");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (input[bytes - 1] == '\n') {
            input[bytes - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            exit(EXIT_SUCCESS);
        }

        // Tokenize the input to form the argument list
        i = 0;  // Reset i to 0
        for (char *token = strtok(input, " "); token != NULL && i < 19; token = strtok(NULL, " ")) {
            args[i++] = token;
        }
        args[i] = NULL;  // Null-terminate the argument list

        // Pass envp to execute_command
        execute_command(args, envp);
    }
    free(input);

    return 0;
}

