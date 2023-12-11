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

	pid = fork();

	if (pid < 0)
		perror("($)"); /* error forking */
	else if (pid == 0)
	{
		/* child process */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			free(*argv);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		/* parent process */
		do {
			waitpid(pid, &wstatus, WUNTRACED);
		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
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
	{
		perror("allocation");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, TOK_DELIM);
	while (token)
	{
		tokens[i] = token;
		i++;

		if (i >= buffsize)
		{
			buffsize += TOK_BUFFSIZE;
			tokens = realloc(tokens, buffsize);
			if (tokens == NULL)
			{
				perror("allocation");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * launchProcess - launch a child process
 * @args: a reference pointer to a space in memory where tokenized
 * commands are stored
 *
 * description: this function launches a child process
 *
 * Return: 1 as status of execution
 */
int launchProcess(char **args)
{
	if (args[0] == NULL)
		return (1);

	return (initChild(args));
}
