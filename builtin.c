#include "shell.h"

/**
 * _myexit - exits the shell
 *
 * @information: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * Return: exits with a given exit status (0) if info.argv[0] != "exit"
 */
int _myexit(inf_t *information)
{
	int exitcheck;

	if (information->argv[1]) /* If there is an exit argument */
	{
		/* Convert exit argument to integer */
		exitcheck = _erratoi(information->argv[1]);

		if (exitcheck == -1)
		{
			/* Set error status and print error message */
			information->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		/* Set error number and return a negative exit status */
		information->err_num = _erratoi(information->argv[1]);
		return (-2);
	}

	/* Set error number and return a negative exit status */
	information->err_num = -1;
	return (-2);
}

/**
 * _mycd - inochinja ma folder awuri kushandira
 *
 * @information: ita zvimwe
 *
 * Return: Always 0
 */
int _mycd(inf_t *information)
{
	char *r, *direct, buffer[1024];

	int cddir_ret;

	/* Get the current working directory */
	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!information->argv[1])
	{
		/* If no arguments are given, change to home directory */
		direct = _getenv(information, "HOME=");
		if (!dirrect)
			cddir_ret = /* TODO: what should this be? */
				cddir((direct = _getenv(information, "PWD=")) ? direct : "/");
		else
			cddir_ret = cddir(direct);
	}
	else if (_strcmp(information->argv[1], "-") == 0)
	{
		/* If '-' is given as an argument, change to previous directory */
		if (!_getenv(information, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(information, "OLDPWD=")), _putchar('\n');
		cddir_ret = /* TODO: what should this be? */
			cddir((direct = _getenv(information, "OLDPWD=")) ? direct : "/");
	}
	else
	{
		/* Otherwise, change to the given directory */
		cddir_ret = cddir(information->argv[1]);
	}

	/* If cddir() returns -1, print an error message */
	if (cddir_ret == -1)
	{
		print_error(information, "can't cd to ");
		_eputs(information->argv[1]), _eputchar('\n');
	}
	else
	{
		/* Set the PWD and OLDPWD environment variables */
		_setenv(information, "OLDPWD", _getenv(information, "PWD="));
		_setenv(information, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - prints a list of available commands or help for a specific command
 *
 * @information: pointer to the info_t struct containing arguments and environment variables
 *
 * Return: Always 0
 */
int _myhelp(inf_t *information)
{
	char **arg_arrays;

	/* Set arg_array to point to the argv member of info */
	arg_arrays = information->argv;

	/* Print a message indicating that the help function has been called, but it is not yet implemented */
	_puts("help call works. Function not yet implemented \n");

	/* The following if statement is a temporary workaround to prevent the
	 * "unused variable" warning from the compiler. It does not affect the behavior of the function.
	 */

	if (0)
		_puts(*arg_arrays);

	/* Return 0 to indicate successful execution */
	return (0);
}
