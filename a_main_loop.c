#include "main.h"

/**
 * n_hsh - the entry point of hsh
 * @member: member struct.
 * @av: the argument vector from the main function.
 * Return: returns 0 on success, and 1/error code on error.
 */
int n_hsh(memb_t *member, char **av)
{
	ssize_t k = 0;
	int builtin_ret = 0;

	while (k != -1 && builtin_ret != -2)
	{
		n_clear_member(member);
		if (n_interactive_mode(member))
			n_puts("$ ");
		n_inputchar(BUF_FLUSH);
		k = n_get_input(member);
		if (k != -1)
		{
			n_set_member(member, av);
			builtin_ret = n_find_builtin(member);
			if (builtin_ret == -1)
				n_find_command(member);
		}
		else if (n_interactive_mode(member))
			n_putchar('\n');
		n_free_member(member, 0);
	}
	n_write_history(member);
	n_free_member(member, 1);
	if (!n_interactive_mode(member) && member->status)
		exit(member->status);
	if (builtin_ret == -2)
	{
		if (member->err_num == -1)
			exit(member->status);
		exit(member->err_num);
	}
	return (builtin_ret);
}

/**
 * n_find_builtin - function to find a builtin command.
 * @member: member struct.
 * Return:  returns 0 if builtin executed successfully,
 *	returns 1 if builtin found but not successful,
 *	returns -1 if builtin not found,
 *	returns -2 if builtin signals exit().
 */
int n_find_builtin(member_t *member)
{
	int i, built_in_ret = -1;

	builtin_table builtintbl[] = {
		{"exit", n_my_exit},
		{"env", n_my_env},
		{"history", n_my_history},
		{"setenv", n_my_setenv},
		{"unsetenv", n_my_unsetenv},
		{"cd", n_my_cd},
		{"alias", n_my_alias},
		{"help", n_my_help},
		{NULL, NULL}};
	for (i = 0; builtintbl[i].type; i++)
		if (n_my_strcmp(member->argv[0], builtintbl[i].type) == 0)
		{
			member->line_count++;
			built_in_ret = builtintbl[i].func(member);
			break;
		}
	return (built_in_ret);
}

/**
 * n_find_command - finds a command in PATH.
 * @member: member struct.
 * Return: nothing. void.
 */
void n_find_command(memb_t *member)
{
	char *path = NULL;
	int i, numbs_args;

	member->path = member->argv[0];
	if (member->linecount_flag == 1)
	{
		member->line_count++;
		member->linecount_flag = 0;
	}
	for (i = 0, numbs_args = 0;member->arg[i]; i++)
	{
		if (!n_is_delimiter(member->arg[i], " \t\n"))
			numbs_args++;
	}
	if (!numbs_args)
		return;
	path = n_find_path(member, n_getenv(member, "PATH="), member->argv[0]);
	if (path)
	{
		member->path = path;
		n_fork_command(member);
	}
	else
	{
		if ((n_interactive_mode(member) || n_getenv(member, "PATH=") ||
					member->argv[0][0] == '/') && n_is_cmd(member, member->argv[0]))
		{
			n_fork_command(member);
		}
		else if (*(member->arg) != '\n')
		{
			member->status = 127;
			n_print_error(member, "not found\n");
		}
	}
}
/**
 * n_fork_command - forks an exec thread to run command.
 * @member: member struct.
 * Return: returns nothing.
 */
void n_fork_command(memb_t *member)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(memb->path, memb->argv, n_get_environ(member)) == -1)
		{
			n_free_member(member, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(member->status));
		if (WIFEXITED(member->status))
		{
			member->status = WEXITSTATUS(member->status);
			if (member->status == 126)
				n_print_error(info, "Permission denied\n");
		}
	}
}
