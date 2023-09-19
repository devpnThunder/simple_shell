#include "main.h"

/**
* **stringSplit - splits a sentence into multiple words
* @s: string character
* Return: returns the split strings
*/

char **stringSplit(char *s)
{
	int i = 0;
	char separate[] = " ";
	int zeros = _ospaces(s);
	char **splits = malloc(sizeof(char *) * (zeros + 1));
	char *split;

	if (!splits)
	{
		fprint(stderr, "sh: allocation error\n");
		exit(1);
	}

	split = strtok(s, separate);

	while (split != NULL)
	{
		splits[i] = split;
		split = strtok(NULL, separate);
		i++;
	}
	splits[i] = NULL;

	return (splits);
}
