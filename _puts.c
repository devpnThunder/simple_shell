#include "main.h"

/**
* _puts - function that prints a string
* @str: string characters
*
* Return: the string characters
*/
void _puts(char *str)
{
	int i = 0;

	while (i >= 0)
	{
		if (str[i] == '\0')
		{
			_putchar('\n');
			break;
		}
		_putchar(str[i]);
		i++;
	}
}
