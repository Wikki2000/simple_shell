#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return:the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest), j, i = _strlen(src);

	for (j = 0; j < i; ++j)
	{
		*(dest + len) = *(src + j);
		len++;
	}
	*(dest + len) = '\0';
	return (dest);
}
