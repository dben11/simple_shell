#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **tokenize(char *str, char *delim, int len);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen_recursion(const char *s);
char *_strdup(char *str);
int _atoi(char *s);
void _puts(char *str);
char *rem_new_line(char *str);
int arg_count(char *str);
void signal_handler(int sig_id);
int execbuiltin_cmd(char **arg_tokens, char *line);
void frees_get_env(char *env_path);
void frees_tokens(char **tokens);
void _open_help(void);
int count_delim(char *str, char *delim);
char *_getenv(const char *var);
void _print_env(void);
char *concat_path(char *pathname, char *progname);
char *search_cmd(char *cmd_name);
int exec(char *cmd_name, char **opts);
void _handle_exit(char **arg_tokens, char *line);

#endif /* SHELL_H isdef */
