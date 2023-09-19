#include "main.h"

/**
* _ospaces - returns the number of \o occurence of a string
* @s: string character
* Return: return int
*/

unsigned int _ospaces(char *s)
{
	int i, cpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			cpt++;
	}
	return (cpt);
}
