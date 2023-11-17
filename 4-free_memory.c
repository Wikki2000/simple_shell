#include "shell.h"

/**
 * free_memory - free memory
 * @tokens: array of tokens
 * Return: void
 */

void free_memory(char **tokens)
{
        char **temp;

        if (tokens == NULL)
                return;
        temp = tokens;
        while (*temp)
        {
                free(*temp);
                temp++;
        }
        free(tokens);
}
