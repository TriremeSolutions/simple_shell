#include "main.h"
/**
 * main - shell function
 * @argv: char pointer
 * @argc: integer
 * @envp: environ properties array
 * Return: 0;
 */
int main(int argc, char **argv, char *envp[])
{
	size_t ln = 2;
	ssize_t chrCount;
	char *duplicate, *lineBufPtr;
	const char *delimiter = " \n";
	char *shellprompt = "\n(0-0) Madame $helby: ";
	(void)argc;
	lineBufPtr = NULL;
	while (1)
	{
		printf("%s", shellprompt);
		chrCount = getline(&lineBufPtr, &ln, stdin);
		if (chrCount == -1)
		{
			printf(":-} Madame $helby will see you later... Goodbye.\n");
			return (-1);
		}
		duplicate = malloc(sizeof(char) * chrCount);
		if (duplicate == NULL)
		{
			perror("shelby: memory allocation error");
			return (-1);
		} /*user inputs valid, proceed to duplicate*/
		chops(duplicate, lineBufPtr, delimiter);
		argv = malloc(sizeof(char *) * ln);
		argPackets(argv, duplicate, delimiter);
		env(argv, envp);
		entry(argv, lineBufPtr);
		if (strcmp(argv[0], "exit") == 0)
		return (0);
		command(argv);
	}
	free(lineBufPtr);
	free(duplicate);
	return (0);
}
