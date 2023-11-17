#include "shell.h"
/**
 * handle_rbyte - check the type of data return from getine
 * @buffer: user input from stdin
 * @rbyte: return byte from getline
 * @ret_code: return code for the process
 * @env: environment variable
 * Return: integer
 */

int handle_rbyte(char *buffer, int rbyte, int *ret_code, char **env)
{
	/* when user press enter key */
	if (rbyte == 1)
	{
		free(buffer);
		return (1);
	}

	/* end of file */
	if (rbyte == -1)
	{
		free(buffer);
		free_memory(env);
		exit(*ret_code);
	}
	return (rbyte);
}
