#include "shell.h"

/**
 * main - Entry shell program
 *
 * Return: 0 on success
 */

int main(void)
{
	char *line = NULL, **arg_tokens = NULL;
	int num_arg = 0, exec_flag = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		signal(SIGINT, signal_handler);

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line_len = getline(&line, &line_size, stdin);

		if (line_len == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		num_arg = arg_count(line);
		if (line[0] != '\n' && num_arg > 0)
		{
			arg_tokens = tokenize(line, " \t", num_arg);
			if (arg_tokens[0] == NULL)
				continue;
			exec_flag = execbuiltin_cmd(arg_tokens, line);

			if (!exec_flag)
			{
				arg_tokens[0] = search_cmd(arg_tokens[0]);
				if (arg_tokens[0] && access(arg_tokens[0], X_OK) == 0)
					exec(arg_tokens[0], arg_tokens);
				else
					perror("./hsh");
			}
			frees_tokens(arg_tokens);
		}
	}
	free(line);
	return (0);
}
