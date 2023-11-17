#include "shell.h"
/**
 * _strchr - Search for character in a string
 * @str: The string to search for character
 * @c: The character to search for in a string
 *
 * Return: The address of the search character
 * else NULL if character not found
 */
char *_strchr(const char *str, int c)
{
        /* check if str is NULL */
	if (str == NULL)
		return (NULL);
        /* Check if c is a valid character */
	else if (c < 0 || c > 255)
		return (NULL);
        /* Iterate over str to find c */
	while (*str)
	{
		if (c == *str)
			return ((char *)str);
		str++;
        }
	return (NULL);
}
