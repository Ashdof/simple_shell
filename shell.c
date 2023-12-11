#include "shell.h"

/**
 * main - application entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *buffer, **args;
	ssize_t len;
	int status;

	buffer = NULL;

	for (;;)
	{
		printf("($) ");
		len = getLine(&buffer);
		args = parseString(buffer);
		status = launchProcess(args);
		printf("\nCommands: %s", buffer);
		printf("Length: %ld\n", len);
		printf("Status: %d\n\n", status);

		free(buffer);
		free(args);
	}

	return (0);
}
