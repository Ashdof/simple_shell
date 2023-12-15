#include "shell.h"

/**
 * interMode - interactive mode
 *
 * description: this function invokes the shell in an
 * interactive mode
 *
 * Return: nothing
 */
void interMode(void)
{
	char **args, *buffer = NULL;
	int status;

	do {
		scriptString("($) ");
		fflush(stdout);
		readLine(&buffer);

		args = parseString(buffer);
		if (args == NULL)
		{
			free(args);
			free(buffer);
			continue;
		}
		status = launchProcess(args);

		free(buffer);
		free(args);
	} while (status);
}

/**
 * nonInterMode - non-interactive mode
 * @fd: a file descriptor
 *
 * description: this function executes the shell in a non-interactive
 * mode
 *
 * Return: nothing
 */
void nonInterMode(int fd)
{
	ssize_t len;
	size_t n = 0;
	int status;
	char **args, *buffer = NULL;

	while ((len = getLine(&buffer, &n, fd)) > 0)
	{
		if (buffer[0] == '\0')
			continue;
		args = parseString(buffer);
		if (args == NULL)
		{
			free(buffer);
			continue;
		}
		status = launchProcess(args);
		if (status != 0)
			break;

		free(buffer);
	}

	close(fd);
}

/**
 * handleRelPath - handle relative path
 */
char **handleRelPath(char *full_path, char *buffer, char **rs)
{
	rs[0] = full_path;
	rs[1] = buffer;

	return (rs);
}
