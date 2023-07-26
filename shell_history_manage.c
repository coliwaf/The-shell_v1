/**
 * history_file_get - gets the file containing history
 * @data: struct param
 *
 * Return: allocated string containing history file
 */
char *history_file_get(data_s *data)
{
}

/**
 * create_update_history - creates a file, or appends to existing file
 * @data: the struct param
 *
 * Return: 1 on success, else -1
 */
int create_update_history(data_s *data)
{
}

/**
 * get_history - function reads history from specified file
 * @data: the struct param
 *
 * Return: hist_ln_count on success, 0 otherwise
 */
int get_history(data_s *data)
{
}

/**
 * history_list_update - appends entry to a linked list history
 * @data: Struct containing potential args
 * @buffr: buffer
 * @ln_count: the history ln_count, hist_ln_count
 *
 * Return: Always 0
 */
int history_list_update(data_s *data, char *buffr, int ln_count)
{
}

/**
 * history_renumber - changes the renumbers the history linked list
 * @data: Struct containing potential args
 *
 * Return: the new hist_ln_count
 */
int history_renumber(data_s *data)
{
}

