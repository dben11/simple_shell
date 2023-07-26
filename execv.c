#include "shell.h"

/**
 * concat_path - concatenate a pathname and a programname
 * @pathname: the pathname
 * @progname: the programname to place in the path
 *
 * Return: The pathname concatenated with the programnane
 */

char *concat_path(char *pathname, char *progname)
{
	int prog_len, path_len, size;

	prog_len = _strlen_recursion(progname);
	path_len = _strlen_recursion(pathname);
	size = sizeof(char) * (path_len + prog_len + 2);
	pathname = _realloc(pathname, (path_len + 1), size);
	if (pathname == NULL)
		return (NULL);
	_strcat(pathname, "/");
	_strcat(pathname, progname);
	return (pathname);
}

/**
 * search_cmd - search for command in the system
 * @cmd_name: the command name to be search for in the system
 *
 * Return: the path name of the command found or NULL if it does not exist
 */

char *search_cmd(char *cmd_name)
{
	char *env_path = NULL, **path_tokens = NULL;
	int i = 0, num_delim = 0;
	struct stat sb;

	if (cmd_name)
	{
		if (stat(cmd_name, &sb) != 0 && cmd_name[0] != '/')
		{
			env_path = _getenv("PATH");
			num_delim = count_delim(env_path, ":") + 1;
			path_tokens = tokenize(env_path, ":", num_delim);

			while (path_tokens[i])
			{
				path_tokens[i] = concat_path(path_tokens[i], cmd_name);

				if (stat(path_tokens[i], &sb) == 0)
				{
					free(cmd_name);
					cmd_name = _strdup(path_tokens[i]);
					frees_get_env(env_path);
					frees_tokens(path_tokens);
					return (cmd_name);
				}
				i++;
			}
			frees_get_env(env_path);
			frees_tokens(path_tokens);
		}
		if (stat(cmd_name, &sb) == 0)
			return (cmd_name);
	}
	free(cmd_name);
	return (NULL);
}

/**
 * exec - execute a command
 * @cmd_name: the command to be executed
 * @opts: The options or flags to be executed
 *
 * Return: an integer status value
 */

int exec(char *cmd_name, char **opts)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cmd_name, opts, environ);
			break;
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (0);
}
