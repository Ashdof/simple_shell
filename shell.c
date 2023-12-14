#include "shell.h"

/**
 * main - application entry point
 *
 * Return: Always 0 (success)
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int fd;

	if (isatty(STDIN_FILENO))
		interMode();
	else if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open_file");
			return (1);
		}

		nonInterMode(fd);
	}
	else
		nonInterMode(STDIN_FILENO);

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
	char *built_ins[] = {"exit", "env"};
	int (*builtins_cmd[]) (char **) = {
		&handleExit,
		&handleEnv
	};

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
