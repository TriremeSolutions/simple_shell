#include "main.h"
/**
 * chops - tokenizes user input
 * @duplicate: copy of input string
 * @lineBufPtr: user input string
 * @delimiter: delimiter
 * Return: void
 */
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
