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

/**
 * strnCpy - copy bytes
 * @dest: a pointer to a space in memory to store copied bytes
 * @src: a pointer to a space in memory to copy bytes from
 * @n: number of bytes to copy
 *
 * description: this function copies n bytes from the space pointed
 * at by src to the space pointed at by dest
 *
 * Return: a pointer to the copied bytes
 */
char *strnCpy(char *dest, char *src, size_t n)
{
	size_t i;
	char *p = dest;

	for (i = 0; i <= n; i++)
		*p++ = src[i];

	return (dest);
}

/**
 * memChr - get the first occurence of a character
 * @s: a pointer to the string
 * @c: the character to search for
 * @n: the length of the string
 *
 * Return: the array of characters up to, but not including the
 * character represented by c
 */
void *memChr(char *s, int c, size_t n)
{
	while (n != 0)
	{
		if ((unsigned char) c == *s)
			return ((void *) (s - 1));

		n--;
		s++;
	}

	return (NULL);
}
