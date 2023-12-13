#include "shell.h"

/**
 * strCat - concatenate strings
 * @dest: a pointer to the destination space in memory
 * @src: a pointer to the source space in memory
 *
 * description: this function copies bytes from src to des
 *
 * Return: a pointer to dest
 */
char *strCat(char *dest, char *src)
{
	char *q, *p = dest;

	while (*p)
		p++;
	for (q = src; *q != '\0'; q++)
		*p++ = *q;
	*p = '\0';

	return (dest);
}
