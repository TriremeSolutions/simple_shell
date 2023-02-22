#include "main.h"
/**
 * fetchPath - tokenizes input and gets PATH
 * @instructShell: user command
 * Return: a string argument
 */
char *fetchPath(char *instructShell)
{
char *path, *duplPath, *splitPath, *fullPath;
const char *delim, *prefix, *suffix;
int instructLength, splitSize;
struct stat buffer;
delim = ":";
prefix = "/";
suffix = "\0";
path = getenv("PATH");
	if (path)
	{
		duplPath = strdup(path);
		instructLength = strlen(instructShell);
		splitPath = strtok(duplPath, delim);
		while (splitPath != NULL)
		{
			splitSize = strlen(splitPath);
			fullPath = malloc(instructLength + splitSize + 2);
			strcpy(fullPath, splitPath);
			strcat(fullPath, prefix);
			strcat(fullPath, instructShell);
			strcat(fullPath, suffix);
			if (stat(fullPath, &buffer) == 0)
			{
				free(duplPath);
				return (fullPath);
			}
			else
			{
				free(fullPath);
				splitPath = strtok(NULL, delim);
			}
		}
		free(duplPath);
		if (stat(instructShell, &buffer) == 0)
			return (instructShell);
		return (NULL);
	}
return (NULL);
}
