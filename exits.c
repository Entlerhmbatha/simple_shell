#include "shell.h"

/**
 * _strncpy - Copies a string up to n bytes.
 *
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of bytes to be copied.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int dest_index, src_index;

	char *start = dest;

	dest_index = 0;

	/* Copy up to n bytes from src to dest. */
	while (src[dest_index] != '\0' && dest_index < n - 1)
	{
		dest[dest_index] = src[dest_index];
		dest_index++;
	}

	/* If less than n bytes were copied, pad dest with null bytes. */
	if (dest_index < n)
	{
		src_index = dest_index;
		while (src_index < n)
		{
			dest[src_index] = '\0';
			src_index++;
		}
	}
	return (start);
}

/**
 * _strncat - Concatenates two strings up to n bytes.
 *
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_index, src_index;

	char *start = dest;

	dest_index = 0;

	/* Find the end of the first string. */
	while (dest[dest_index] != '\0')
	{
		dest_index++;
	}

	src_index = 0;

	/* Concatenate up to n bytes from src onto the end of dest. */
	while (src[src_index] != '\0' && src_index < n)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}

	/* If less than n bytes were used, pad with a null byte. */
	if (src_index < n)
	{
		dest[dest_index] = '\0';
	}
	return (start);
}


/**
 * _strchr - Locates a character in a string.
 *
 * @s: The string to be searched.
 * @c: The character to look for.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	/* Search for the character in the string. */
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	/* Return NULL if the character is not found. */
	return (NULL);
}

