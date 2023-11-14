#include "shell.h"

/**
 * _envCAT - concatenates name and value of environmental variable
 * @dest: holds the new environ
 * @src: name, value or equal sign
 * Return: the new environ
 */

char *_envCAT(char *dest, char *src)
{
	int len = _strlen(dest), j, i = _strlen(src);

	for (j = 0; j < i; ++j)
	{
		*(dest + len) = *(src + j);
		len++;
	}
	return (dest);
}

/**
 * _envCOPY - copy name to the new environmental variable
 * @dest: a pointer to store the name of environ
 * @src: name of the environ
 * Return: a new environ contain the name
 */

char *_envCOPY(char *dest, char *src)
{
	int i, len = _strlen(src);

	for (i = 0; i < len; ++i)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
/**
 * setNewENVIRON - set new environmntal variable
 * @newENV: a new single environ to be set
 * @newENVIRON: a new environmental variable
 * @envNAME: name of environmental variable
 * @envVALUE: value of environmental variable
 * Return: 0 in Success and -1 on Failuere
 */
int setNewENVIRON(char *newENV, char **newENVIRON,
		char *envNAME, char *envVALUE)
{
	int count = 0, i;

	newENV = malloc(_strlen(envNAME) + _strlen(envVALUE) + 2);
	if (newENV == NULL)
	{
		perror("Memory allocation Failed.");
		return (-1);
	}
	_envCOPY(newENV, envNAME);
	_envCAT(newENV, "=");
	_envCAT(newENV, envVALUE);
	newENV[_strlen(envNAME) + _strlen(envVALUE) + 1] = '\0';
	while (environ[count] != NULL)
		count++;
	newENVIRON = malloc((count + 2) * sizeof(char *));
	if (newENVIRON == NULL)
	{
		free(newENV);
		perror("Memory allocation Failed.");
		return (-1);
	}
	for (i = 0; i < count; i++)
		newENVIRON[i] = environ[i];
	newENVIRON[count] = newENV;
	newENVIRON[count + 1] = NULL;
	environ = newENVIRON;
	return (0);
}

/**
 * _setenv - update existing or set new environmntal variable
 * @envNAME: name of environmental variable
 * @envVALUE: value of environmental variable
 * @overWrite: determine whether to overwrite the environ or nor
 * Return: 0 in Success and -1 on Failure
 */
int _setenv(char *envNAME, char *envVALUE, int overWrite)
{
	char *equalSIGN,  *newENV = NULL, **newENVIRON = NULL;
	size_t nameLEN = 0;
	int i;

	if (envNAME == NULL || envVALUE == NULL)
	{
		perror("Input is NULL");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		equalSIGN = _strchr(environ[i], '=');
		nameLEN = equalSIGN - environ[i];
		if (_strncmp(environ[i], envNAME, nameLEN) == 0)
		{
			if (!overWrite)
			{
				perror("Can not edit environ.");
				return (-1);
			}
			else
			{
				newENV = malloc(_strlen(envNAME) + _strlen(envVALUE) + 2);
				if (newENV == NULL)
				{
					perror("Memory allocation failed.");
					return (-1);
				}
				_envCOPY(newENV, envNAME);
				_envCAT(newENV, "=");
				_envCAT(newENV, envVALUE);
				newENV[_strlen(envNAME) + _strlen(envVALUE) + 1] = '\0';
				environ[i] = newENV;
			}
			return (0);
		}
	}
	return (setNewENVIRON(newENV, newENVIRON, envNAME, envVALUE));
}
