#include "shell.h"

/**
 * strTok - tokinize a string
 * @str: a pointer to the string
 * @delim: a pointer to the delimeter
 *
 * Return: a pointer to the tokinised string
 */
char *strTok(char *str, const char *delim)
{
	int i = 0;
	char *last_token;
	static char *token;

	if (str != NULL)
		token = str;

	if (token == NULL || *token == '\0')
		return (NULL);

	while (*token)
	{
		for (i = 0; delim[i]; i++)
			if (*token == delim[i])
				break;
		if (delim[i] == '\0')
			break;
		token++;
	}

	last_token = token;
	while (*token)
	{
		for (i = 0; delim[i]; i++)
			if (*token == delim[i])
				break;
		if (delim[i])
		{
			*token++ = '\0';
			break;
		}
		token++;
	}

	return (last_token);
}

/**
 * _atoi - convert to integer
 * @s: a pointer to the string
 *
 * description: this function converts a string to an integer
 *
 * Return: the integer
 */

int _atoi(char *s)
{
	unsigned int n = 0;
	int op = 1;
	char *p = s;

	while (*p != '\0' && (*p < '0' || *p > '9'))
	{
		if (*p == '-')
			op *= -1;
		p++;
	}

	for (; *p != '\0' && *p >= '0' && *p <= '9'; p++)
	{
		if (*p < '0' || *p > '9')
			return (0);
		n = n * 10 + *p - '0';
	}

	return (n * op);
}
