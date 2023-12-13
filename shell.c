#include "shell.h"

/**
 * main - application entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *buffer, **args;
	int status;

	buffer = NULL;

	do {
		printf("($) ");
		getLine(&buffer);
		args = parseString(buffer);
		status = launchProcess(args);

		free(buffer);
		free(args);
	} while (status);

	return (0);
}

/**
 * launchProcess - launch a child process
 * @args: a reference pointer to a space in memory where tokenized
 * commands are stored
 *
 * description: this function launches a child process
 *
 * Return: 1 as status of execution
 */
int launchProcess(char **args)
{
	int i, num;
	int (*builtins_cmd[]) (char **) = {&handleExit};
	char *built_ins[] = {"exit"};

	if (args[0] == NULL)
		return (1);

	num = sizeof(builtins_cmd) / sizeof(char *);

	for (i = 0; i < num; i++)
	{
		if (strcmp(args[0], built_ins[i]) == 0)
			return ((*builtins_cmd[i])(args));
	}

	return (initChild(args));
}
