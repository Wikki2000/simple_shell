#include "shell.h"
/**
 * main - Entry point of program
 * @argc: Command-line arguement count
 * @args: An array of command-line arguement
 * @envp: Environment variable
 *
 * Description: This program implement a simple shell
 *
 * Return: Always (0)
 */
int main(int argc, char *args[])
{
	char *input = NULL, *command[2];

	(void)argc;
	for (;;)
	{
		input = getINPUT();
		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}
		command[0] = input;
		command[1] = NULL;
		executeCOMMAND(command, args[0]);
	}
	free(input);
	return (0);
}
