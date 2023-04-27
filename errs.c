#include "shell.h"

/**
 * _eputs - icha budisa zviku diwa
 * @str: str icha buda
 *
 * Return: usa budisa chinhu
 */
void _eputs(char *str)
{
	int p = 0;

	if (!str)
		return;
	while (str[p] != '\0')
	{
		_eputchar(str[p]); /* prints single char to stderr */
		p++;
	}
}

/**
 * _eputchar - ino ita zviku diwa
 * @g: ino budisa character
 *
 * Return: zvikaita 1.
 * zvika ramba, -1
 */
int _eputchar(char g)
{
	static int p; /* counter for buffer */
	static char buf[WRITE_BUF_SIZE]; /* buffer for printing to stderr */

	if (g == BUF_FLUSH || p >= WRITE_BUF_SIZE) /* if buffer is full or flush requested */
	{
		write(2, buf, p); /* write to stderr */
		p = 0;
	}
	if (g != BUF_FLUSH) /* if not flushing */
		buf[p++] = g; /* add char to buffer */
	return (1);
}

/**
 * _putfdsc - ino nyora ma files abud pa filedescriptor
 * @g: ino dzosa ma character
 * @fdsc: kuti filedescriptor inonyora zviku diwa
 *
 * Return: Zvika ita 1.
 * On error, dzosa -1
 */
int _putfdsc(char g, int fdsc)
{
	static int p; /* counter for buffer */
	static char buf[WRITE_BUF_SIZE]; /* buffer for printing */

	if (g == BUF_FLUSH || p >= WRITE_BUF_SIZE) /* if buffer is full or flush requested */
	{
		write(fdsc, buf, p); /* write to given fd */
		p = 0;
	}
	if (g != BUF_FLUSH) /* if not flushing */
		buf[p++] = g; /* add char to buffer */
	return (1);
}

/**
 * _putsfdsc - inonyora an input string to given fdsc
 * @str: string ndiyo inonyorwa
 * @fdsc: kuti filedescriptor inyore ku zviku diwa
 *
 * Return: ma Number ema character ayiswa na put
 */
int _putsfdsc(char *str, int fdsc)
{
	int p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfds(*str++, fdsc); /* prints single char to given fd */
	}
	return (p);
}

