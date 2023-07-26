#include "shell.h"

/**
 * _getenv - Get the environmrnt variable
 * @var: the variable to look for in the system environment
 *
 * Return: the content of the variable
 */

char *_getenv(const char *var)
{
	int i, len;
	char *env_var = NULL;

	len = _strlen_recursion(var);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
		{
			env_var = _strdup(environ[i]);

			while (*env_var != '=')
				env_var++;
			++env_var;
			return (env_var);
		}
	}

	return (NULL);
}
