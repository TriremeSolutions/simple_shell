#include "main.h"

void chops(char *duplicate, char *lineBufPtr, const char *delimiter)
{
	int chopNumber;
	char *chopped;
	chopNumber = 0;
	strcpy(duplicate, lineBufPtr);
	chopped = strtok(lineBufPtr, delimiter); /*initial user input chopped*/
	while (chopped != NULL)
	{
		chopNumber++;
		chopped = strtok(NULL, delimiter);
	}
}
