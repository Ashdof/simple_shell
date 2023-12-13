#include "shell.h"

/**
 * handleExit - implement the built-in exit command
 * @argv: a reference pointer to commands provided by user
 *
 * Return: 0 on success
 */
int handleExit(__attribute__((unused)) char **argv)
{
	return (0);
}

/**
 * handleEnv - implement env built-in command
 *
 * Return: nothing
 */
int handleEnv(__attribute__((unused)) char **argv)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		scriptString(environ[i]);
		scriptString("\n");
	}

	return (1);
}
