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
/**
 * _strtok - A function to tokenize a string based on delimiters.
 * @str: The input string to be tokenized.
 * @delim: A string containing delimiter characters.
 *
 * Return: A pointer to the next token in the string.
 * NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastTOKEN;
	char *tokenSTART, *tokenEND;

	/* If a new string is given, update lastToken */
	if (str != NULL)
		lastTOKEN = str;
	else if (lastTOKEN == NULL)
		return (NULL);

	/* Find the beginning of the next token */
	tokenSTART = lastTOKEN;
	while (*lastTOKEN != '\0' && _strchr(delim, *lastTOKEN) != NULL)
		lastTOKEN++;

	/* If no more tokens are found, return NULL */
	if (*lastTOKEN == '\0')
	{
		lastTOKEN = NULL;
		return (NULL);
	}

	/* Find the end of the token */
	tokenEND = lastTOKEN + 1;
	while (*tokenEND != '\0' && _strchr(delim, *tokenEND) == NULL)
		tokenEND++;

	/* Null-terminate the token and update lastToken */
	*tokenEND = '\0';
	lastTOKEN = tokenEND + 1;

	return (tokenSTART);
}


/**
 *  strTOKENIZE - tokenize a command accepted from user
 * @input: user input to be tokenized
 * @args: buffer to store the tokenized string
 *
 * Return: array of tokenized user input
 */

char **strTOKENIZE(char *input, char **args)
{
	char *token = NULL;
	int ac = 0;

	token = _strtok(input, " ");
	while (token != NULL)
	{
		args[ac] = token;
		ac++;
		token = _strtok(NULL, " ");
	}
	args[ac] = NULL;
	return (args);
}

