#include "shell.h"

/**
 * getLine - read input stream
 * @data: a pointer to a space in memory to store input read
 *
 * description: this function reads data input
 *
 * Return: nothing
 */
ssize_t getLine(char **data)
{
	ssize_t len;
	size_t buffsize = 0;

	len = getline(data, &buffsize, stdin);
	if (len == -1)
	{
		free(*data);

		if (feof(stdin)) /* reached end of file */
			exit(EXIT_SUCCESS);
		else
		{
			perror("($)");
			exit(EXIT_FAILURE);
		}
	}

	return (len);
}
