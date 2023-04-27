#include "shell.h"

/**
 * is_shell_inter - tarisa kana iri interactive mode
 * @information: taridza ku struct yezviri mukati me shell
 *
 * Return: isa 1 kana irimu interactive mode, kana kuti dzosa hako zero 0
 */
int is_shell_inter(inf_t *information)
{
	/* check if stdin is a terminal and readfd is less than or equal to 2 */
	return (isatty(STDIN_FILENO) && information->read_fd <= STDERR_FILENO);
}

/**
 * is_delimeter - tarisa character kana iri delimiter
 * @p: ino cheka ma characters
 * @delimeter: inonzi delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delimeter(char p, char *delimeter)
{
	/* loop through delimiter string */
	while (*delimeter)
	{
		/* if character is a delimiter */
		if (*delimeter++ == p)
			return (1);
	}
	/* character is not a delimiter */
	return (0);
}

/**
 * _isalphabet - inotarisa ma characterz
 * @p: inotarisa character racho
 *
 * Return: 1 kana c ari ma letters, kana pasina is 0
 */
int _isalphabet(int p)
{
	/* check if c is a letter (uppercase or lowercase) */
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	/* c is not a letter */
	else
		return (0);
}

/**
 * _atoi - Ino chinja string kuisa ku integer
 * @g: ndiyo ino chinja string
 *
 * Return: 0
 */
int _atoi(char *g)
{
	int k, sign = 1, flag = 0, output;
	unsigned int result = 0;

	/* loop through input string */
	for (k = 0; g[k] != '\0' && flag != 2; k++)
	{
		/* if number is negative */
		if (g[k] == '-')
			sign *= -1;

		/* if character is a digit */
		if (g[k] >= '0' && g[k] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (g[k] - '0');
		}
		/* if character is not a digit and a number has already been found */
		else if (flag == 1)
			flag = 2;
	}

	/* apply sign to result */
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

