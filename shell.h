#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TOK_DELIM " \r\t\n\a"
#define TOK_BUFFSIZE 60
#define PATH_DELIM ":"
#define READ_BUFFSIZE 120

extern char **environ;

/* function prototypes */
ssize_t getLine(char **, size_t *, int);
int initChild(char **);
char **parseString(char *);
int launchProcess(char **);
void buildPath(char **, char *, char *, int);
char *handlePath(char *);
int handleEnv(char **);
int handleExit(char **);
char *getEnv(const char *);
void readLine(char **);
void interMode(void);
void nonInterMode(int);
char *strTok(char *, const char *);
int setEnv(char *, char *, int);
char **handleRelPath(char *, char *, char **);
int unsetEnv(char *);

int strnCmp(char *, char *, int);
int strCmp(char *, char *);
char *strDup(char *);
int strLen(const char *);
void *strCpy(char *, char *);
char *strCat(char *, char *);
int scriptChar(char);
int scriptString(char *);
void *memChr(char *, int, size_t);
char *strnCpy(char *, char *, size_t);
int _atoi(char *);

#endif /* SIMPLE_SHELL */
