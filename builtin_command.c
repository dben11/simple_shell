#include "shell.h"

/**
 * execbuiltin_cmd - execute a built in command
 * @arg_tokens: the given token
 * @line: the argument to be executed
 *
 * Return: 1 if is a builtin cmd or 0 if not
 */

int execbuiltin_cmd(char **arg_tokens, char *line)
{
	int i = 0;
	char *list_of_builtin_cmd[] = {"exit", "cd", "help", "env", NULL};

	while (list_of_builtin_cmd[i])
	{
		if (_strcmp(arg_tokens[0], list_of_builtin_cmd[i]) == 0)
		{
			switch (i)
			{
				case 0:
					_handle_exit(arg_tokens, line);
					return (1);
				case 1:
					chdir(arg_tokens[1]);
					return (1);
				case 2:
					_open_help();
					return (1);
				case 3:
					_print_env();
					return (1);
				default:
					break;
			}
		}
		i++;
	}
	return (0);
}
