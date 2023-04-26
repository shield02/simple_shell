#include "main.h"

/**
 * execmd - execute a command
 * @argv: char pointer to pointer - holds an array of commands
 *
 * Description: This function execute commands that are gotten
 * from the user
 * Return: void
*/
void execmd(char **argv)
{
	char *cmd = NULL;
	int excmd;

	if (argv)
	{
		cmd = argv[0];

		excmd = execve(cmd, argv, NULL);

		if (excmd == -1)
		{
			perror("./shell");
		}
	}
}

