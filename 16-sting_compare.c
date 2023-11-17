#include "shell.h"

/**
 * stringCOMPARE - Compare and check if two strings are equal
 * @str1: The first string to be compared
 * @str2: The second string to be compared
 * @index: Index of the string
 *
 * Return: Value (0) if success else (1)
 */
int stringCOMPARE(char *str1, char *str2, int index)
{
        int str_LEN1 = 0, str_LEN2 = 0;

        if (str1 == NULL || str2 == NULL)
                return (-1);
        str_LEN1 = _strlen(str1);
        str_LEN2 = _strlen(str2);
        if (str_LEN1 != str_LEN2)
                return (1);
        if (str1[index] == '\0' && str2[index] == '\0')
                return (0);

        if (str1[index] != str2[index])
                return (1);

        return (stringCOMPARE(str1, str2, index + 1));
}
