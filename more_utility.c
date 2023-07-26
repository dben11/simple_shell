#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - This function prints a string to stdout.
 * @str: The string to print to stdout
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * _strncmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * @len: the maximum byte to be compared
 * Return: 0 if the string are equal
 * a negative value if s1<s2
 * Positive value if s1>s2
 */
int _strncmp(const char *s1, const char *s2, size_t len)
{
	int result = 0;
	unsigned int i = 0;

	while (i < len)
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
		{
			result = s1[i] - s2[i];
			break;
		}

		i++;
	}

	return (result);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the old memory
 * @old_size: the size of the old memory
 * @new_size: the new size of the created memory
 *
 * Return: pointer to the newly created memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_str = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_str = malloc(new_size);
		if (new_str == NULL)
			return (NULL);
		return (new_str);
	}
	else
	{
		if (new_size == 0)
		{
			free(new_str);
			return (NULL);
		}
	}
	new_str = malloc(new_size);
	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
	{
		new_str[i] = ((char *) ptr)[i];
	}
	free(ptr);
	return (new_str);
}
