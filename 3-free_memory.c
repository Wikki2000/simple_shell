#include "shell.h"
/**
 * free_memory - free memory
 * @tokens: array of tokens
 * Return: void
 */

void freeMEMORY(char **arr)
{
	char **arrCOPY;

	if (arr == NULL)
		return;
	arrCOPY = arr;
	while (*arrCOPY)
	{
		free(*arrCOPY);
		arrCOPY++;
	}
	free(arr);
}
