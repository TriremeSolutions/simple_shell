#include "main.h"

void entry(char **argv, char *lineBufPtr)
{
	if (strcmp(lineBufPtr, "exit") == 0)
	{
		printf(":-} Madame $helby says Ciao!\n");
		argv[0] = "exit";
	}
	if (strcmp(argv[0], "hello") == 0)
	printf("This is Shelby\n");
}
