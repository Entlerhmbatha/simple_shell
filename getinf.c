#include "shell.h"

/**
 * clear_info - kuwona zvakanaka
 * @information: tarisa ku inf_t
 *
 * Dsc: iyi function ino ita zvaka wanda
 */
void clear_info(inf_t *information)
{
	information->arg = NULL;
	information->argv = NULL;
	information->path = NULL;
	information->argc = 0;
}

/**
 * set_infomtion- ino tanga inf_t struct
 * @information:tarisa ku inf_t
 * @av: inopa pikisano
 *
 * Dsc: ndopano tangira zvarehwa kumusoro
 */
void set_information(inf_t *information, char **av)
{
	int p = 0;

	information->fname = av[0];
	if (information->arg)
	{
		information->argv = strtow(information->arg, " \t");
		if (!information->argv)
		{
			information->argv = malloc(sizeof(char *) * 2);
			if (information->argv)
			{
				information->argv[0] = _strdup(information->arg);
				information->argv[1] = NULL;
			}
		}
		for (p = 0; information->argv && information->argv[p]; p++)
			;
		information->argc = p;

		replace_alias(information);
		replace_vars(information);
	}
}

/**
 * free_information -regedzai information fields
 * @information: tarisa ku to inf_t
 * @zvese: boolean to free all fields or not
 *
 * Description: taka tarisana nema boolens
 */
void free_information(inf_t *information, int zvese)
{
	free(information->argv);
	information->argv = NULL;
	information->path = NULL;
	if (zvese)
	{
		if (!information->cmd_buf)
			free(information->arg);
		if (information->env)
			free_list(&(information->env));
		if (information->history)
			free_list(&(information->history));
		if (information->alias)
			free_list(&(information->alias));
		free(information->environ);
			information->environ = NULL;
		bfree((void **)information->cmd_buf);
		if (information->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

