#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, k, l, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, k = 0; k < numwords; k++)
	{
		while (is_delim(str[i], d))
			i++;
		l = 0;
		while (!is_delim(str[i + l], d) && str[i + l])
			k++;
		s[k] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < k; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < l; n++)
			s[k][n] = str[i++];
		s[k][n] = 0;
	}
	s[k] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, k, l, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, k = 0; k < numwords; k++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		l = 0;
		while (str[i + l] != d && str[i + l] && str[i + l] != d)
			l++;
		s[k] = malloc((l + 1) * sizeof(char));
		if (!s[k])
		{
			for (l = 0; l < k; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < l; n++)
			s[k][n] = str[i++];
		s[k][n] = 0;
	}
	s[k] = NULL;
	return (s);
}
