#include "main.h"
/**
 * argPackets - copies the tokenized input values into slots in an array
 * @argv: char pointer
 * @duplicate: copied string
 * @delimiter: delimiter
 * Return: 0;
 */
void argPackets(char **argv, char *duplicate, const char *delimiter)
{
char *chipped;
int c;
chipped = strtok(duplicate, delimiter);
for (c = 0; chipped != NULL; c++)
	{
		argv[c] = malloc(sizeof(char) * strlen(chipped));
		strcpy(argv[c], chipped);
		chipped = strtok(NULL, delimiter);
	}
	argv[c] = NULL; /**account for last index;*/
}
