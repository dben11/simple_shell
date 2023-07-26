#include "shell.h"

/**
 * _print_env - print the env builtin
 */

void _print_env(void)
{
	int n = 0, m;

	while (environ[n])
	{
		m = 0;
		while (environ[n][m])
		{
			_putchar(environ[n][m]);
			m++;
		}
		if (m != 0)
			_putchar('\n');
		n++;
	}
}
