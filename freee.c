#include "shell.h"

/**
 * frees_get_env - free environment variable used
 * @env_path: the environment variable to be free
 */

void frees_get_env(char *env_path)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_path--;
	free(env_path);
}

/**
 * frees_tokens - free tokens
 * @tokens: the tokens to be free
 */

void frees_tokens(char **tokens)
{
	char **temp = tokens;

	if (tokens)
	{
		while (*tokens)
			free(*tokens++);
		free(temp);
	}
}
