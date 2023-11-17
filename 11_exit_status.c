#include "shell.h"

/**
 * handle_exit - Handle the exit command
 * @argv: Array of command-line arguments
 * @n: Pointer to the exit status code
 * Return: 0 on success, -1 on failure
 */
int handle_exit(char **argv, int *n)
{
    int status_code;
    static int error_num = 1;

    if (argv[1] == NULL)
    {
        free_memory(environ);
        exit(*n);
    }

    status_code = _atoi(argv[1]);
    if (status_code < 0)
    {
        handle_exit_error(argv[0], argv, error_num, "Illegal number");
        error_num++;
        *n = ILLEGAL_NUMBER;
    }
    else
    {
        *n = status_code;
    }

    free_memory(environ);

    exit(*n);
}

/**
 * handle_exit_error - Print error message for exit command
 * @filename: Name of the executable
 * @argv: Command-line arguments
 * @n: Number of times a child process failed to execute a command
 * @msg: Message to display
 * Return: void
 */
void handle_exit_error(char *filename, char **argv, int n, char *msg)
{
    char error[100];
    char *count_str;

    strcpy(error, filename);
    strcat(error, ": ");
    count_str = int_to_str(n);
    if (count_str == NULL)
    {
        count_str = "1";
    }
    strcat(error, count_str);
    strcat(error, ": ");
    strcat(error, argv[1]);
    strcat(error, ": ");
    strcat(error, msg);
    strcat(error, ": ");
    strcat(error, argv[1]);
    strcat(error, "\n");

    write(STDERR_FILENO, error, strlen(error));
    free(count_str);
}

