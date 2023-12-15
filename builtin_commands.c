#include "shell.h"

/**
 * handleExit - implement the built-in exit command
 * @argv: a reference pointer to commands provided by user
 *
 * Return: 0 on success
 */
int handleExit(char **argv)
{
	int status;

	if (argv[1] != NULL)
	{
		status = _atoi(argv[1]);
		free(argv);
		_exit(status);
	}

	return (0);
}

/**
 * handleEnv - implement env built-in command
 * @argv: a reference pointer to the arguments
 *
 * Return: nothing
 */
int handleEnv(__attribute__((unused)) char **argv)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		scriptString(environ[i]);
		scriptString("\n");
	}

	return (1);
}

/**
 * setEnv - set environment variable
 * @name: a pointer to a space in memory where the variable is stored
 * @value: a pointer to a space in memory where the variable's value
 * is stored
 * @overwrite: the overwrite value
 *
 * Return: 0 on success, -1 if it fails
 */
int setEnv(const char *name, const char *value, int overwrite)
{
	size_t n_len, v_len;
	char *mem, *new_env;

	if (name == NULL || name[0] == '\0' || value == NULL)
		return (0);
	new_env = getEnv(name);
	if (new_env == NULL && overwrite == 0)
		return (0);

	n_len = strLen(name);
	v_len = strLen(value);
	mem = malloc(n_len + v_len + 2);
	if (mem == NULL)
		return (-1);
	strnCpy(mem, name, n_len);
	mem[n_len] = '=';
	strnCpy(mem + n_len + 1, value, v_len);
	mem[n_len + v_len + 1] = '\0';

	if (putenv(mem) != 0)
		return (-i);

	return (0);
}

/**
 * unsetEnv - unset an environment variable
 * @name: a pointer to a space in memory where the variable's name
 * is stored
 *
 * Return: 0 on success, -1 on failure
 */
int unsetEnv(const char *name)
{
	char **env, **p;
	size_t len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);

	len = strLen(name);
	for (env = environ; *env != NULL; )
	{
		if (strnCmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			for (p = env; *p != NULL; p++)
				*p = *(p + 1);
		}
		else
		{
			env++;
		}
	}

	return (0);
}
