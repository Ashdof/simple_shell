#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

#define TOK_DELIM " \r\t\n\a"
#define TOK_BUFFSIZE 60
#define PATH_DELIM ":"

extern char **environ;

/* function prototypes */
ssize_t getLine(char **);
int initChild(char **);
char **parseString(char *);
int launchProcess(char **);
char *buildPath(char *, char *, int);
char *handlePath(char *);

int strnCmp(char *, char *, int);
int strCmp(char *, char *);
char *strDup(char *);
int strLen(const char *);
char *getEnv(const char *);
void *strCpy(char *, char *);
char *strCat(char *, char *);

#endif /* SIMPLE_SHELL */
