#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int command(char **argv);
int env(char **argv, char *envp[]);
void entry(char **argv, char *lineBufPtr);
char *fetchPath(char *instructShell);
int validator(char *shellprompt, char *lineBufPtr);
void chops(char *duplicate, char *lineBufPtr, const char *delimiter);
void argPackets(char **argv, char *duplicate, const char *delimiter);
#endif
