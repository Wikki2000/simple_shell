#include "shell.h"

/**
 * prompt_user - prompt user to input data from commandline
 * Return: void
 */

void getINPUT(void)
{
	size_t size;
	char pwd[500];

	size = 500;
	getcwd(pwd, size);
	strcat(pwd, "$ ");
	write(STDOUT_FILENO, pwd, strlen(pwd));
}
