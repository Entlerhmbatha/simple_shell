#include "shell.h"

/**
 * get_environ - ndatenda zvanku
 * @information: hungwaru hwese
 *
 * Return: dzosa
 */
char **get_environ(inf_t *information)
{
	if (!information->environ || information->env_changed)
	{
		information->environ = list_to_strings(information->env);
		information->env_changed = 0;
	}

	return (information->environ);
}

/**
 * _unsetenv - kubvisa ma env
 * @information: pano buda zvese
 * @var: Zvema property
 *
 * Return: 0 kana kuti 1
 */
int _unsetenv(inf_t *information, char *var)
{
	list_t *nod = information->env;
	size_t r = 0;
	char *h;

	if (!nod || !var)
		return (0);

	while (nod)
	{
		p = starts_with(nod->str, var);
		if (h && *h == '=')
		{
			information->env_changed = delete_nod_at_index(&(information->env), r);
			r = 0;
			nod = information->env;
			continue;
		}
		nod = nod->next;
		r++;
	}
	return (information->env_changed);
}

/**
 * _setenv - pazvaka tangira
 * @information: Chinoongedzo cheku poyinda
 * @var: ma strin'i ema propatiz.
 * @val: string iku unza env var val.
 *
 * Return: Dzosa 0.
 */
int _setenv(inf_t *information, char *var, char *val)
{
	char *buf = NULL;
	list_t *nod;
	char *p;

	if (!var || !val)
		return (0);

	buf = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, val);
	nod = information->env;
	while (nod)
	{
		p = starts_with(nod->str, var);
		if (p && *p == '=')
		{
			free(nod->str);
			nod->str = buf;
			information->env_changed = 1;
			return (0);
		}
		nod = nod->next;
	}
	add_nod_end(&(information->env), buf, 0);
	free(buf);
	information->env_changed = 1;
	return (0);
}

