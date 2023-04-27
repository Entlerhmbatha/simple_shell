#include "shell.h"

/**
 * input_buff - function that buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buff(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	/* If nothing left in the buffer, fill it */
	if (!*len)
	{
		/* Free any previously allocated buffer */
		free(*buf);
		*buf = NULL;

		/* Set signal handler for SIGINT */
		signal(SIGINT, sigintHandler);

		/* Read input from STDIN using either getline or _getline */
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif

		if (r > 0)
		{
			/* Remove trailing newline character */
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}

			/* Update history */
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);

			/* Check if it's a command chain and update command buffer */
			if (_strchr(*buf, ';'))
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - function that gets a line of input from STDIN
 * @information: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(inf_t *information)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t x, j, len;
	ssize_t r = 0;
	char **buff_p = &(information->arg), *p;

	/* Flush stdout buffer */
	_putchar(BUFF_FLUSH);

	/* Read input from buffer or STDIN */
	r = input_buff(information, &buff, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = x; /* init new iterator to current buf position */
		p = buf + x; /* get pointer for return */

		/* Check if it's a command chain */
		check_chain(information, buff, &j, x, len);

		/* Iterate to semicolon or end */
		while (j < len)
		{
			if (is_chain(information, buff, &j))
				break;
			j++;
		}

		/* Increment past nulled ';' */
		x = j + 1;
		if (x >= len) /* reached end of buffer? */
		{
			x = len = 0;
			information->cmd_buff_type = CMD_NORM;
		}

		/* Pass back pointer to current command position */
		*buff_p = p;
		return (_strlen(p));
	}

	/* Not a chain, return buffer from _getline() */
	*buff_p = buff;
	return (r);
}

/**
 * read_buff - func_that_reads_a_buffer
 * @information: params_struct
 * @buff: buff the buffer
 * @f: size
 *
 * Return: bytes_read
 */
ssize_t read_buff(inf_t *information, char *buff, size_t *f)
{
	ssize_t r = 0;

	if (*f)
		return (0);

/**
 * _getline - gets the next line of input from STDIN
 * @information: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(inf_t *information, char **ptr, size_t *length)
{
	static char buff[READ_BUFF_SIZE];
	static size_t r, len;
	size_t k;
	ssize_t r = 0, g = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		g = *length;
	if (r == len)
		r = len = 0;

	r = read_buff(information, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buff + r, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : len;
	new_p = _realloc(p, g, g ? g + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);
	if (g)
		_strncat(new_p, buff + r, k - r);
	else
		_strncpy(new_p, buff + r, k - r + 1);

	g += k - r;
	r = k;
	p = new_p;

	if (length)
		*length = g;
	*ptr = p;
	return (g);
}

/**
 * sigintHandler - ma blokisi ctrl-C
 * @sig_numba: siginari namba
 *
 * Return: hapana
 */
void sigintHandler(__attribute__((unused))int sig_numba)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

