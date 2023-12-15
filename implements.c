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
