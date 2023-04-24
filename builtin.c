#include "shell.h"

/**
 * _myexit - exits the shell
 *
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * Return: exits with a given exit status (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit argument */
	{
		/* Convert exit argument to integer */
		exitcheck = _erratoi(info->argv[1]);

		if (exitcheck == -1)
		{
			/* Set error status and print error message */
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		/* Set error number and return a negative exit status */
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}

	/* Set error number and return a negative exit status */
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 *
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];

	int chdir_ret;

	/* Get the current working directory */
	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
		/* If no arguments are given, change to home directory */
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		/* If '-' is given as an argument, change to previous directory */
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{
		/* Otherwise, change to the given directory */
		chdir_ret = chdir(info->argv[1]);
	}

	/* If chdir() returns -1, print an error message */
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		/* Set the PWD and OLDPWD environment variables */
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - prints a list of available commands or help for a specific command
 *
 * @info: pointer to the info_t struct containing arguments and environment variables
 *
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	/* Set arg_array to point to the argv member of info */
	arg_array = info->argv;

	/* Print a message indicating that the help function has been called, but it is not yet implemented */
	_puts("help call works. Function not yet implemented \n");

	/* The following if statement is a temporary workaround to prevent the
	 * "unused variable" warning from the compiler. It does not affect the behavior of the function.
	 */

	if (0)
		_puts(*arg_array);

	/* Return 0 to indicate successful execution */
	return (0);
}
