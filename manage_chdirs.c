#include "shell.h"

/**
 * getHomePath - get the path to the home directory
 *
 * Return: path to home directory
 */
char *getHomePath(void)	
{
	char *home;

	home = getEnv("HOME");
	if (home == NULL)
		perror("cd:home_path");

	return (home);
}

/**
 * getPrevPath - get the previous working directory path
 *
 * Return: path to the previous working directory
 */
char *getPrevPath(void)
{
	char *prev_path;

	prev_path = getEnv("OLDPWD");
	if (prev_path == NULL)
		perror("cd:prev_path");
	else
		scriptString(prev_path);

	return (prev_path);
}
