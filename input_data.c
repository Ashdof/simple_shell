#include "shell.h"

/**
 * getLine - read input stream
 * @data: a pointer to a space in memory to store input read
 * @: a pointer to a space in memory holding the number of bytes
 * to read
 * @fd: a file descriptor
 *
 * description: this function reads data input
 *
 * Return: nothing
 */
ssize_t getLine(char **data, size_t *n, int fd)
{
	ssize_t len = 0;
	size_t min = READ_BUFFSIZE;
	char *mem;

	if (*n == 0)
		*n = min;

	mem = malloc(sizeof(char) * (*n) + 1);
	if (mem == NULL)
		return (-1);

	while ((len = read(fd, mem, *n)) != -1)
	{
		if (len >= ((ssize_t) *n))
		{
			*n += min;
			mem = realloc(mem, *n);
			if (data == NULL)
			{
				perror("getline realloc");
				return (-1);
			}
		}
		/*strnCpy(*data, mem, len);*/

		/* search for a newline character */
		if (memChr(mem, '\n', len))
			break;

	}
	if (len == -1)
		return (-1);
	mem[len] = '\0';
	*data = mem;
	/*free(mem);*/
	/**data = msg;*/

	return (len);
}

/**
 * readLine - read data input
 * @buffer: a reference pointer to a space in memory to store data
 * read
 *
 * Return: nothing
 */
void readLine(char **buffer)
{
	size_t buffsize = 0;

	buffsize = getLine(buffer, &buffsize, STDIN_FILENO);
	if (buffsize == ((size_t) -1))
	{
		if (feof(stdin))
		{
			scriptString("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
}
