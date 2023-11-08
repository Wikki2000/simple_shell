#include "shell.h"
/**
 * _memcpy - copy memory area from one pointer to another
 * @dest: a destination pointer
 * @src: a source pointer to be copied
 * @n: size to be copied
 *
 * Return: a destination pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char **ptr = &src, **pt = &dest;
	unsigned int i;

	for (i = 0; i < n; ++i)
	{
		*(*pt + i) = *(*ptr + i);
	}
	return (dest);
}

/**
 * _getline - Accepts input from standard input.
 * @inputPTR: A buffer to store the input
 * @size: Initial size of the buffer
 * @input_STREAM: A stream to accept an input whether a file or standard input
 *
 * Return: The Number of characters accepted from standard input
 */

ssize_t _getline(char **inputPTR, size_t *size, int input_STREAM)
{
	size_t count = 0, newSIZE = 0, byte = 1;
	ssize_t inputREAD;
	char buf, *newBUF = NULL;

	if (*inputPTR == NULL || *size == 0)
	{
		*inputPTR = malloc(BUFFER_SIZE);
		*size = BUFFER_SIZE;
	}
	while (1)
	{
		inputREAD = read(input_STREAM, &buf, byte);
		if (inputREAD == -1)
		{
			free(size);
			return (handle_failure(*inputPTR));
		}
		else if (inputREAD == 0)
			break;
		if (count >= *size - 1)
		{
			newSIZE = *size * 2;
			newBUF = malloc(newSIZE);
			if (newBUF == NULL)
				return (handle_failure(newBUF));
			_memcpy(newBUF, *inputPTR, *size);
			free(*inputPTR);
			*inputPTR = newBUF;
			*size = newSIZE;
		}
		(*inputPTR)[count++] = buf;
		if (buf == '\n')
			break;
	}
	(*inputPTR)[count] = '\0';
	if (count == 0 && inputREAD == 0)
		return (-1);
	return (count);
}

/**
 * handle_failure - Free an memory allocated
 * @ptr: A string with allocated memory
 * Return: Always Failure (-1)
 */

int handle_failure(char *ptr)
{
	free(ptr);
	return (-1);
}
