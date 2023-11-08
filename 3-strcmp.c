#include "shell.h"

/**
 * stringCOMPARE - Compare and check if two strings are equal
 * @str1: The first string to be compared
 * @str2: The second string to be compared
 * @index: Index of the string
 *
 * Return: Value (0) if success else (1)
 */
int stringCOMPARE(const char *str1, const char *str2, int index)
{
	if (str1[index] == '\0' && str2[index] == '\0')
		return (0);

	if (str1[index] != str2[index])
		return (1);

	return (stringCOMPARE(str1, str2, index + 1));
}
