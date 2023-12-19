#include "shell.h"

/**
 * initChild - create a child process
 * @argv: a reference pointer to the space in memory holding the
 * tokenized string
 *
 * description: this function creates a child process and executes
 * the commands supplied as tokens
 *
 * Return: 1 on success. It however exits on failure
 */
int initChild(char **argv)
{
	pid_t pid;
	int wstatus;
	char *arg, *cmd;

	arg = argv[0];
	cmd = handlePath(arg);

	if (cmd == NULL)
		perror(arg);
	else
	{
		pid = fork();
		if (pid < 0)
			perror(arg); /* error forking */

		else if (pid == 0)
		{
			/* child process */
			if (execve(cmd, argv, NULL) == -1)
				perror(arg);

			exit(EXIT_FAILURE);
		}
		else
		{
			/* parent process */
			do {
				waitpid(pid, &wstatus, WUNTRACED);
			} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
		}
	}

	return (1);
}

/**
 * parseString - parse the string
 * @str: a pointer to a space in memory where the string is
 * stored
 *
 * description: this function takes a string input and parse
 * it into tokens
 *
 * Return: a reference pointer to the tokens
 */
char **parseString(char *str)
{
	int buffsize, i = 0;
	char **tokens, *token;

	buffsize = TOK_BUFFSIZE;

	tokens = malloc(sizeof(char *) * buffsize + 1);
	if (tokens == NULL)
		return (NULL);

	token = strTok(str, TOK_DELIM);
	while (token)
	{
		tokens[i++] = token;
		token = strTok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * handlePath - compute path
 * @cmd: a pointer to command
 *
 * description: this function searches the system and attempts to
 * build the path of a command.
 *
 * Return: on success, it returns a pointer to the executable file,
 * a null pointer if it fails
 */
char *handlePath(char *cmd)
{
	struct stat buffer;
	int len;
	char *path, *path_dup, *dir, *full_path;

	path = getEnv("PATH");
	if (path == NULL)
		return (NULL);

	path_dup = strDup(path);
	len = strLen(cmd);
	dir = strtok(path_dup, PATH_DELIM);

	while (dir != NULL)
	{
		buildPath(&full_path, dir, cmd, len);

		if (stat(full_path, &buffer) == 0)
		{
			free(path_dup);
			return (full_path);
		}
		else
		{
			free(full_path);
			dir = strtok(NULL, PATH_DELIM);
		}
	}

	free(path_dup);
	if (stat(cmd, &buffer) == 0)
		return (cmd);

	/* executable not found */
	return (NULL);
}

/**
 * buildPath - build path of the executable
 * @dir: a pointer to the directory of the file
 * @cmd: the command
 * @n: length of the command
 * @loc: location to store full path
 *
 * description: this function builds a path of an executable file
 *
 * Return: nothing
 */
void buildPath(char **loc, char *dir, char *cmd, int n)
{
	char *mem;
	int len;

	len = strLen(dir);
	mem = malloc(sizeof(char) * len + n + 2);
	if (mem == NULL)
	{
		perror("build_path");
		exit(EXIT_FAILURE);
	}

	strCpy(mem, dir);
	strCat(mem, "/");
	strCat(mem, cmd);

	*loc = mem;
}

/**
 * getEnv - get environment variables
 * @cmd: a pointer to the environment variables
 *
 * Return: the value part of the variable
 */
char *getEnv(const char *cmd)
{
	int i;
	size_t len;

	len = strLen(cmd);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], cmd, len) == 0 &&
		    environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}

	/* variable not found */
	return (NULL);
}
