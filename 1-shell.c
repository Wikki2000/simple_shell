#include "shell.h"

int main(void) {
    char *input = NULL;
    size_t size = 0;
    ssize_t bytes;
    bool is_pipe = !isatty(STDIN_FILENO);

    if (is_pipe) {
        // If input is from a pipe, read directly from stdin
        bytes = getline(&input, &size, stdin);
        
        if (bytes == -1) {
            perror("getline failed");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (input[bytes - 1] == '\n') {
            input[bytes - 1] = '\0';
        }

        // Tokenize the input to form the argument list
        int i = 0;
        char *args[20];
        for (char *token = strtok(input, " "); token != NULL && i < 19; token = strtok(NULL, " ")) {
            args[i++] = token;
        }
        args[i] = NULL;  // Null-terminate the argument list

        execute_command(args);
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

            if (input[bytes - 1] == '\n') {
                input[bytes - 1] = '\0';
            }

            if (strcmp(input, "exit") == 0) {
                free(input);
                exit(EXIT_SUCCESS);
            }

            // Tokenize the input to form the argument list
            int i = 0;
            char *args[20];
            for (char *token = strtok(input, " "); token != NULL && i < 19; token = strtok(NULL, " ")) {
                args[i++] = token;
            }
            args[i] = NULL;  // Null-terminate the argument list

            execute_command(args);
        }
        free(input);
    }

    return 0;
}

