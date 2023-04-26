#include "shell.h"

/**
 * print_env - pano tangi kadhir kacho
 * @information: zvese zvese pano
 * Return: Zvese 0
 */
int print_env(inf_t *information)
{
	print_list_str(information->env);
	return (0);
}

/**
 * _get_env_var - tora chaka mirira env
 * @information: pazvese zviri pano
 * @zita: zita re env
 * Return: Zvese 0
 */
char *_get_env_var(inf_t *information, const char *zita)
{
	list_t *nod = information->env;
	char *p;

	while (nod)
	{
		p = starts_with(nod->str, zita);
		if (p && *p)
			return (p);
		nod = nod->next;
	}
	return (NULL);
}

/**
 * set_env_var - inotanga env params ese
 * @information: zvese zviri pano
 * Return: zvese 0
 */
int set_env_var(inf_t *information)
{
	if (information->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (set_env_var(information, information->argv[1], information->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_env_var - ino bvisa env params
 * @information: njere dzese dziri pano
 * Return: Zvese dzosa 0
 */
int unset_env_var(inf_t *information)
{
	int p;

	if (information->argc == 1)
	{
		_eputs("Too few few arguments.\n");
		return (1);
	}
	for (p = 1; p <= information->argc; p++)
		unset_env_var(information, information->argv[p]);

	return (0);
}

/**
 * pop_env_list - zadza env list
 * @information: zurivo rwese ruri pano
 * Return: Always 0
 */
int pop_env_list(inf_t *information)
{
	list_t *nod = NULL;
	size_t p;

	for (p = 0; environ[p]; p++)
		add_nod_end(&nod, environ[p], 0);
	information->env = nod;
	return (0);
}

