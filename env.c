#include "main.h"

int env(char **argv, char *envp[]){
int ep;
	if (strcmp(argv[0], "env") == 0)
	{
		for (ep = 0; envp[ep] != NULL; ep++)
		{
			printf("\n%s\n", envp[ep]);
		}
	}
return (0);
}
