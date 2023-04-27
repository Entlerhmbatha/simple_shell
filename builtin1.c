#include "shell.h"

/**
 * _myhistory - kuwonesa hisitori yemu komandi layini
 * @information: mastrakitya
 * Return: nguva dzese 0
 */
int _myhistory(inf_t *information)
{
	print_list(information->history);
	return (0);
}

/**
 * unset_alias - seta ma alias
 * @information: maparamita
 * @str: ma alias panapa
 *
 * Return: dzosa 0 kana kuti 1
 */
int unset_alias(inf_t *information, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_nod_at_index(&(information->alias),
		get_nod_index(information->alias, nod_starts_with(information->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - tatoyi seta alias
 * @information: maparamita
 * @str: ehe bo
 *
 * Return: dzosa 0 kana kuti 1 kana zvaramba
 */
int set_alias(inf_t *information, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(information, str));

	unset_alias(information, str);
	return (add_nod_end(&(information->alias), str, 0) == NULL);
}

/**
 * print_alias - nyora alias
 * @nod: iyi ndiyo alias nod
 *
 * Return: dzosa 0 zvika ita kana kuti 1 zvika ramba
 */
int print_alias(list_t *nod)
{
	char *p = NULL, *a = NULL;

	if (nod)
	{
		p = _strchr(nod->str, '=');
		for (a = nod->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - ino tevedzera alias builtin
 * @information: mastrakitya
 * Return: Dzosa 0 nguva dzese
 */
int _myalias(inf_t *information)
{
	int p = 0;  /* set variable to p */
	char *str_ptr = NULL;
	list_t *nod = NULL;

	if (information->argc == 1)
	{
		nod = information->alias;
		while (nod)
		{
			print_alias(nod);
			nod = nod->next;
		}
		return (0);
	}

	/* set variable to p */
	for (p = 1; information->argv[p]; p++)
	{
		str_ptr = _strchr(information->argv[p], '=');
		if (str_ptr)
			set_alias(information, information->argv[p]);
		else
			print_alias(nod_starts_with(information->alias, information->argv[p], '='));
	}

	return (0);
}

