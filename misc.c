#include "shell.h"

/**
 * strLen - compute length of string
 * @str: a pointer to the string
 *
 * Return: computed length
 */
int strLen(const char *str)
{
	const char *p = str;

	while (*p)
		p++;

	return (p - str);
}

/**
 * strDup - duplicate a string
 * @str: a pointer to the string
 *
 * description: this function duplicates a string, without
 * modifying it
 *
 * Return: a pointer to a space in memory where th eduplicate
 * is stored
 */
char *strDup(char *str)
{
	int i, len = 0;
	char *mem;

	len = strLen(str);

	mem = malloc(sizeof(char) * len + 1);
	if (mem == NULL)
	{
		perror("duplicate_string");
		exit(EXIT_FAILURE);
	}

	for (i = 0; str[i] != '\0'; i++)
		mem[i] = str[i];
	mem[i] = '\0';

	return (mem);
}

/**
 * strCmp - compare two strings
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 *
 * Return: -1 if s1 is less than s2, 0 if both are equal and
 * 1 if s1 is greater than s2
 */
int strCmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * strnCmp - compare two strings
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 * @n: number of bytes to compare
 *
 * description: this function compares two strings, up to n bytes
 *
 * Return: -1 if s1 is less than s2, 0 if both are equal and
 * 1 if s1 is greater than s2
 */
int strnCmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}

	return (*s1 - *s2);
}

/**
 * strCpy - copy strings
 * @dest: a pointer to the destination space in memory
 * @src: a pointer to the source space in memory
 *
 * description: this function copies bytes from src to dest
 *
 * Return: nothing
 */
void *strCpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}
