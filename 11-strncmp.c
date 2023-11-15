#include "shell.h"

/**
 * _strncmp - Compare two strings up to a specified length.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return:
 *  - Negative value if s1 < s2.
 *  - Positive value if s1 > s2.
 *  - 0 if s1 is equal to s2 up to n characters.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);

		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
