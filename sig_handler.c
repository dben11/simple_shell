#include "shell.h"

/**
 * signal_handler - handle signals
 * @sig_id: the id of the signal
 */

void signal_handler(int sig_id)
{
	if (sig_id == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
