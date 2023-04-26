#include "shell.h"

/**
 * _erratoi - chinja string kuisa ku Integer
 * @g: the string to be converted
 *
 * Return: 0 kana kuti -1
 */
int erratoi(char *g)
{
	int p = 0;
	unsigned long int result = 0;

	if (*g == '+')
		g++;
	for (p = 0; s[p] != '\0'; p++)
	{
		if (g[p] >= '0' && g[p] <= '9')
		{
			result *= 10;
			result += (g[p] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - buritsa err messeji
 * @information: tarisa ku ma params wodzosa ma values
 * @pstr: rudzi rwe err
 *
 * Return: hapana
 */
void print_error(inf_t *information, char *pstr)
{
	eputs(information->fname);
	eputs(": ");
	print_d(information->line_count, STDERR_FILENO);
	eputs(": ");
	eputs(information->argv[0]);
	eputs(": ");
	eputs(pstr);
}

/**
 * print_d - ma fanki sheni
 * @input: maini puti
 * @fdsc: ma dsc
 *
 * Return: ma number achubuda ema karekita
 */
int print_d(int input, int fdsc)
{
	int (*__putchar)(char) = _putchar;
	int p, count = 0;
	unsigned int abs_val, current;

	if (fdsc == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		abs_val = -input;
		__putchar('-');
		count++;
	}
	else
		abs_val = input;
	current = abs_val;
	for (p = 1000000000; p > 1; p /= 10)
	{
		if (abs_val / p)
		{
			__putchar('0' + current / p);
			count++;
		}
		current %= p;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - kuchinja chinja
 * @numba: nhamba
 * @bhesi: bhesi
 * @flagz: arg flagz
 *
 * Return: sitirin'i
 */
char *convert_number(long int numba, int bhesi, int flagz)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = numba;

	if (!(flagz & CONVERT_UNSIGNED) && numba < 0)
	{
		n = -numba;
		sign = '-';
	}
	array = flagz & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % bhesi];
		n /= bhesi;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - kuchinja kwema instance "#", "0/"
 * @buff: adhiresi
 *
 * Return: hapana
 */
void remove_comments(char *buff)
{
	int p;

	for (p = 0; buf[p] != '\0'; p++)
		if (buf[p] == '#' && (!p || buf[p - 1] == ' '))
		{
			buf[p] = '\0';
			break;
		}
}

