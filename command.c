#include "main.h"
/**
 * command - main loop of the shell
 * @argv: input argument
 *
 * Return: an integer value ranging form 0 to 1
 */
int command(char **argv)
{
	pid_t forkCheck;
	if (argv)
	{
		char *instructShell, *trueInstruct;
		if (strcmp(argv[0], "help") == 0 || strcmp(argv[0], "yes") == 0)
		{
		
			printf("Help manual is in development\n");
			return (0);
		}
		if (strcmp(argv[0], "shelby") == 0)
		{
			printf("Listening!\n");
			return (0);
		}
		instructShell = argv[0];
		trueInstruct = fetchPath(instructShell);
		forkCheck = fork();
		if (forkCheck == -1)
		{
			perror("Unsuccessul");
			return (1);
		}
		if (forkCheck == 0)
		{
			if (execve(trueInstruct, argv, NULL) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
			return (0);
		}
	}
	return (1);
}
