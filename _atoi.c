#include "shell.h"

/**
 * interactive - return_interactive_mode
 * @inf: struct_address
 *
 * Return: 1 mode, 0
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_deli - checks_delimeter
 * @x: char_check
 * @deli: delimeter_string
 * Return: 1 success, 0 false
 */
int is_deli(char x, char *deli)
{
	while (*deli)
		if (*deli++ == x)
			return (1);
	return (0);
}

/**
 *_isalpha - checks_alphabetic_character
 *@x: character_input
 *Return: 1 if x_alphabet, 0 kan pasina
 */

int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts_string_integer
 *@z: string_converted
 *Return: 0
 */
int _atoi(char *z)
{
	int y, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (y = 0;  s[y] != '\0' && flag != 2; y++)
	{
		if (s[y] == '-')
			sign *= -1;

		if (s[y] >= '0' && s[y] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

