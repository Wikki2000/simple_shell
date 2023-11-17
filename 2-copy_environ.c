#include "shell.h"
/**
 * dynamic_env - allocate memory for env and make it resizable
 * @env: environment variable
 * Return: pointer to redesign environment variable
 */

char **copyENVIRON(char **env)
{
	int i = 0, k;
	char *currentENV, **newENVIRON;

        while (env[i])
		i++;
	newENVIRON = malloc(sizeof(char *) * (i + 1));
	if (newENVIRON == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		currentENV = strdup(env[i]);
		if (currentENV == NULL)
		{
			for (k = i - 1; k >= 0; k--)
				free(newENVIRON[k]);
			freeMEMORY(newENVIRON);
			return (NULL);
		}
		newENVIRON[i] = currentENV;
                i++;
        }
        newENVIRON[i] = NULL;
        return (newENVIRON);
}
