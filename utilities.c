#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: 0 if the string are equal
 * a negative value if s1<s2
 * Positive value if s1>s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, result;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if ((s1[i] - '0') == (s2[i] - '0'))
		{
			result = 0;
		}
		else if ((s1[i] - '0') > (s2[i] - '0'))
		{
			result = (s1[i] - '0') - (s2[i] - '0');
			break;
		}
		else
		{
			result = (s1[i] - '0') - (s2[i] - '0');
			break;
		}

	}

	return (result);
}

/**
 * _strcat - A function that concatenates two stringds
 * @dest: First string
 * @src: Second string
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int d_len = 0, i;

	while (dest[d_len])
		d_len++;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[d_len] = src[i];
		d_len++;
	}
	dest[d_len] = '\0';

	return (dest);
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: pointer to the string to be counted
 *
 * Return: the length of the string
 */

int _strlen_recursion(const char *s)
{

	if (*s == 0)
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));
}

/**
 * _strdup - duplicat a string
 * @str: pointer to the string to be duplicated
 *
 * Return: the duplicated string
 */

char *_strdup(char *str)
{
	int idx = 0, len;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen_recursion(str);
	dup = malloc((sizeof(char) * len) + 1);

	if (dup == NULL)
		return (NULL);

	while (idx < len)
	{
		dup[idx] = str[idx];
		idx++;
	}
	dup[idx] = '\0';

	return (dup);
}

/**
 * _atoi - A function that converts a string to an integer
 * @s: the given string to be return as integer
 *
 * Return: An integer
 */
int _atoi(char *s)
{
	int i, sign = 1;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 45)
		{
			sign *= -1;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = (num * 10) + (s[i] - '0');
		}
		if (s[i] == 66)
		{
			break;
		}
	}
	num *= sign;
	return (num);
}
