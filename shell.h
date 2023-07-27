#ifndef SHELL_H
#define SHELL_H

#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

#define NEGATIVE_ONE -1
#define GET_BUFFER_SIZE 1024
#define WRITE_FULL_BUFFER_SIZE 1024
#define CHANGE_LOWERCASE 1
#define CHANGE_UNSIGNED 2
#define FLAG_RED 0
#define OR_FLAG 1
#define AND_FLAG 2
#define CHAIN_FLAG 3
#define USE_STRTOK 0
#define USE_GETLINE 0
#define HIST_FILE_NM ".simple_shell_hist"
#define HIST_MAX_SIZE 4096

#define DATA_INIT				\
	{					\
		NULL, NULL, NULL, 0, 0, 0, 0,	\
		NULL, NULL, NULL, NULL, NULL,	\
		0, 0, NULL, 0, 0, 0		\
	}
extern char **environ;

/**
 * struct ListStrct - singly linked list
 * @num: numb param
 * @str: string param
 * @next: next node in struct
 */
typedef struct ListStrct
{
	int num;
	char *str;
	struct ListStrct *next;
} list_s;

/**
 * struct builtin - defines builtin string and its related function
 * @type: the builtin condition
 * @func: the accompanying func
 */
typedef struct builtin
{
	char *type;
	int (*func)(data_s *);
} builtin_cmds;

/**
 * struct infoData - struct with pseudo-arguments to pass to specific function
 * @arg: string generated by getline that contains args
 * @argv:array of strings generated from @arg
 * @path: path string for the current command
 * @argc: arguments length
 * @ln_count: length of encountered errors
 * @err_code: exit()'s error code
 * @ln_count_flag: check if curr line should be counted
 * @prog_fnm: program file's name
 * @env: linked list of the local copy of environment vars
 * @environ: customized modified copy of environ from linked list envs
 * @history: the command history
 * @alias: for the command alias node
 * @env_changed: flag to check if environ has changed
 * @status: response from the status of last executed command
 * @command_buffr: address of pointer to command_buffr(used in chaining)
 * @command_buffer_kind: specifies type of command buffer (CMD_type ||, &&, ;)
 * @retrv_file_descriptor: the file_descr that reads line input
 * @hist_ln_count: length of number of history lines
 */
typedef struct infoData
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int ln_count;
	int err_code;
	int ln_count_flag;
	char *prog_fnm;
	list_s *env;
	list_s *history;
	list_s *alias;
	char **environ;
	int env_changed;
	int status;
	char **command_buffr;
	int command_buffer_kind;
	int retrv_file_descriptor;
	int hist_ln_count;
} data_s;

int main_shell(data_s *, char **);
int select_builtin(data_s *);
void fetch_command(data_s *);
void process_fork(data_s *);
char *_char_dupli(char *, int, int);
int _is_exec(data_s *, char *);
char *fetch_cmd_in_path(data_s *, char *, char *);
int err_putchar(char);
void err_puts(char *);
int put_file_descr(char c, int file_descr);
int puts_file_descr(char *str, int file_descr);
int loopmain_shell(char **);
int _strlen(char *);
int _strcmp(char *, char *);
int _putchar(char);
void _puts(char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
char *str_starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void vector_free(char **);
int free_bytes(void **);
int active_terminal(data_s *);
int is_delimiter(char, char *);
int _isalpha(int);
int _atoi(char *);
int numb_atoi_err(char *);
void print_error(data_s *, char *);
int print_d(int, int);
char * convert_numb_base(long int, int, int);
void convert_comments(char *);
int handle_exiting(data_s *);
int handle_curr_dir(data_s *);
int handle_help(data_s *);
int handle_history(data_s *);
int handle_alias(data_s *);
void sigintHandler(int);
void set_data(data_s *, char **);
void free_data(data_s *, int);
void clear_data(data_s *);
ssize_t get_input(data_s *);
int _getline(data_s *, char **, size_t *);
int my_env(data_s *);
char *env_get(data_s *, const char *);
int unset_my_env(data_s *);
int create_env(data_s *);
int set_my_env(data_s *);
int _unsetenv(data_s *, char *);
int _setenv(data_s *, char *, char *);
char **get_environ(data_s *);
int get_history(data_s *data);
char *history_file_get(data_s *data);
int history_list_update(data_s *data, char *buffr, int ln_count);
int history_renumber(data_s *data);
int create_update_history(data_s *data);
list_s *add_to_node_start(list_s **, const char *, int);
list_s *add_to_node_end(list_s **, const char *, int);
size_t prnt_list_str_elem(const list_s *);
void free_list(list_s **);
int del_node_at_idx(list_s **, unsigned int);
char **_list_t_str(list_s *);
size_t _list_prnt(const list_s *);
size_t _list_lngth(const list_s *);
ssize_t fetch_node_idx(list_s *, list_s *);
list_s *node_start_elem(list_s *, char *, char);
int alias_change(data_s *);
int string_change(char **, char *);
int vars_change(data_s *);
int is_chain(data_s *, char *, size_t *);
void check_chain(data_s *, char *, size_t *, size_t, size_t);

#endif /* SHELL_H */