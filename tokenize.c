#include "shell.h"

/**
 * tokenize - tokenize a string
 * @str: the string to be tokenized
 * @delim: the delimeter
 * @len: the argument count of the string
 *
 * Return: a pointer to a null terminated strings
 */

char **tokenize(char *str, char *delim, int len)
{
	char **tokens = NULL, *token = NULL, *temp = NULL;
	int n = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (tokens == NULL)
		return (NULL);

	str = rem_new_line(str);
	temp = _strdup(str);

	token = strtok(temp, delim);
	while (token)
	{
		tokens[n] = _strdup(token);
		token = strtok(NULL, delim);
		n++;
	}
	tokens[n] = NULL;
	free(temp);
	return (tokens);
}
