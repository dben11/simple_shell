#include "shell.h"

/**
 * arg_count - count the number of argument pass to the command line
 * @str: pointer to address of the read argument
 *
 * Return: the number of argument inputted or -1 on failure
 */

int arg_count(char *str)
{
	int count = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			count++;
		str++;
	}
	return (count);
}

/**
 * count_delim - count the delimeters in cmd_name
 * @str: the string to find out the number of delimeter
 * @delim: the delimeter
 *
 * Return: the number of delimeters in str
 */
int count_delim(char *str, char *delim)
{
	int i = 0, j, num_delim = 0;

	while (delim[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == delim[i])
				num_delim++;
			j++;
		}
		i++;
	}
	return (num_delim);
}
