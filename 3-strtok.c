#include "shell.h"

/**
 * tokenize_buffer - tokenize a string of character
 * @buffer: a string of characters rep. user commands
 * @sep: seperation
 * Return: pointer to a pointer to a char
 */

char **tokenize_buffer(char *buffer, char *sep)
{
	char **token_array;
	char *token, *tmp_buffer;
	int token_count;

	token = NULL;
	token_count = get_N_token(buffer, sep);
	/*printf("token_count before: %d\n", token_count);*/
	/* check if no token or failure occur */
	if (token_count <= 0)
		return (NULL);
	/*printf("token_count after: %d\n", token_count);*/

	/* allocate memory for the token array */
	token_array = malloc(sizeof(char *) * (token_count + 1));

	/* validate memory allocation */
	if (token_array == NULL)
		return (NULL);
	tmp_buffer = strdup(buffer);
	token = _strtok(tmp_buffer, sep);
	token_count = 0;
	while (token != NULL)
	{
		/* make a copy of the token since it will be modified */
		token_array[token_count] = strdup(token);
		token_count++;
		/*printf("token inside: %s\n", token);*/
		token = _strtok(NULL, sep);
	}
	free(tmp_buffer);
	token_array[token_count] = NULL;
	return (token_array);
}

/**
 * get_N_token - get total number of tokens
 * @buffer: string buffer
 * @sep: seperator
 * Return: integer representing total number of tokens
 */

int get_N_token(char *buffer, char *sep)
{
	char *buff_cpy, *buff_tmp, *token;
	int token_count = 0;

	/* duplicate the buffer memory */
	buff_cpy = strdup(buffer);
	buff_tmp = buff_cpy;
	if (buff_cpy == NULL)
		return (-1);
	token = _strtok(buff_cpy, sep);
	while (token != NULL)
	{
		token_count++;
		token = _strtok(NULL, sep);
	}
	free(buff_tmp);
	return (token_count);
}
