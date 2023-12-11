#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define TOK_DELIM " \r\t\n\a"
#define TOK_BUFFSIZE 60

/* function prototypes */
ssize_t getLine(char **);
int initChild(char **);
char **parseString(char *);
int launchProcess(char **);

#endif /* SIMPLE_SHELL */
