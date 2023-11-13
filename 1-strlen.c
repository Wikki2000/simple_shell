#include "shell.h"

/**
 * _strlen - Calculate lenght of a string
 * @string: Pointer to the string whoose lenght is to be calculated
 *
 * Return: The lenght of the string
 */
int _strlen(char *string)
{
	int count = 0;

	while (*string)
	{
		count++;
		string++;
	}

	return (count);
}
