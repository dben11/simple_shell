#include "shell.h"

/**
 * _handle_exit - handle th exit
 * @arg_tokens: the arguments token
 * @line: red argument
 */

void _handle_exit(char **arg_tokens, char *line)
{
	int status = 0;

	if (arg_tokens[1] == NULL || (!_strcmp(arg_tokens[1], "0")))
	{
		frees_tokens(arg_tokens);
		free(line);
		exit(0);
	}
	status = _atoi(arg_tokens[1]);
	if (status != 0)
	{
		frees_tokens(arg_tokens);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Illigal number: ");
		_puts(arg_tokens[1]);
		_puts("\n");
		exit(2);
	}
	frees_tokens(arg_tokens);
	free(line);
	exit(EXIT_SUCCESS);
}
