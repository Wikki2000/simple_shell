#include "shell.h"
/**
 * dynamic_env - allocate memory for env and make it resizable
 * @env: environment variable
 * Return: pointer to redesigned environment variable
 */
char **dynamic_env(char **env)
{
    int i, j;
    char *tmp;
    char **env_array;

    /* Get size of the Array of pointers */
    i = 0;
    while (env[i])
        i++;

    /* Allocate memory for env_array */
    env_array = malloc(sizeof(char *) * (i + 1));
    if (env_array == NULL)
        return (NULL);

    /* Copy strings from env to env_array */
    i = 0;
    while (env[i])
    {
        tmp = strdup(env[i]);
        if (tmp == NULL)
        {
            /* Free all previously allocated memory on failure */
            for (j = i - 1; j >= 0; j--)
                free(env_array[j]);
            free(env_array);
            return (NULL);
        }
        env_array[i] = tmp;
        i++;
    }
    env_array[i] = NULL;

    return (env_array);
}

