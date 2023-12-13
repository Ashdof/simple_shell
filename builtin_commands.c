#include "shell.h"

/**
 * handleExit - implement the built-in exit function
 * @argv: a reference pointer to commands provided by user
 *
 * Return: 0 on success
 */
int handleExit(__attribute__((unused)) char **argv)
{
	return (0);
}

/**
 * builtins_cmd - function pointer
 *
 * description: these are pointer functions to built in commands
 */
int (*builtins_cmd) (char **) = {
        &handleExit
};
