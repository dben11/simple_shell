#include "shell.h"

/**
 * rem_new_line - remove a new line from the input
 * @str: pointer to the inputed string
 *
 * Return: the replacement str
 */

char *rem_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}
