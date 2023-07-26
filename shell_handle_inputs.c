/**
 * input_buffer - chains commands in the buffer
 * @data: struct param
 * @buffr: buffer mem address
 * @len: length var mem address
 *
 * Return: returned bytes
 */
ssize_t input_buffer(data_s *data, char **buffr, size_t *len)
{
}

/**
 * get_input - gets full line except the newline
 * @data: struct param
 *
 * Return: bytes read
 */
ssize_t get_input(data_s *data)
{
}

/**
 * read_buf - reads a buffer
 * @data: struct param
 * @buffr: buffer
 * @i: size
 *
 * Return: res
 */
ssize_t read_buf(data_s *data, char *buffr, size_t *i)
{
}
/**
 * _getline - gets the next line of input from STDIN
 * @data: struct param
 * @ptr: address of pointer to buffer as NULL or preallocated
 * @length: len of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(data_s *data, char **ptr, size_t *length)
{
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
}

