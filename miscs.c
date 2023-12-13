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

/**
 * scriptChar - print a character
 * @c: the character to print
 *
 * Return: the character
 */
int scriptChar(char c)
{
	return (write(1, &c, 1));
}

/**
 * scriptString - print an array of characters
 * @str: a pointer to a space in memory where the array of characters
 * is stored
 *
 * Return: number of characters printed
 */
int scriptString(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		scriptChar(str[i]);

	return (i);
}
