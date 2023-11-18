#include "shell.h"
/**
 * _strcpy - copy a string into another
 * @dest: a strring to have a copy
 * @src: a string to be copied
 * Return: a copy of string
 */
char *_strcpy(char *dest, char *src)
{
	int i, len = _strlen(src);

	for (i = 0; i < len; ++i)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}
