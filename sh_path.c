#include "sshell.h"

/**
 * concat_args - A function that concatenate command arguments
 * @args: a string of arguments
 * @new_arg: new argument to be added
 * Return: a new string of arguments
 */
char *concat_args(char *args, char *new_arg)
{
	size_t new_len;
	/**/
	new_len = strlen(new_arg);
	args = realloc(args, strlen(args) + new_len + 2);

	if (args == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	strcat(args, " ");
	strcat(args, new_arg);
	return (args);
}

/**
 * check_current_dir - A function that checks the path enterred
 * @new_cmd: user's initial path
 * @sh_name: name of the shell executable file
 * @cmd: a string of command enterred with args
 */
int check_current_dir(char *new_cmd, char *sh_name, char **cmd)
{
	if (access(new_cmd, X_OK) == 0)
	{
		sh_execmd(*cmd, sh_name);
		return (1);
		/*exit(EXIT_SUCCESS);*/
	}
	return (0);
}

/**
 * check_dir_in_path - a function that handle the path
 * @new_cmd: the command name e.g. ls
 * @args: a string of command args
 * @sh_name: name of the shell executable file
 */
int check_dir_in_path(char *new_cmd, char *args, char *sh_name)
{
	char *path = getenv("PATH"), *dir = NULL, *cmd_path = NULL;

	if (path != NULL)
	{
		path = strdup(path);
		if (path == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		dir = strtok(path, ":");
		while (dir != NULL)
		{
			cmd_path = malloc(strlen(dir) + strlen(new_cmd) + 2); /*Both "/" and "\0"*/
			if (cmd_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			sprintf(cmd_path, "%s/%s", dir, new_cmd);
			if (access(cmd_path, X_OK) == 0)
			{
				cmd_path = realloc(cmd_path, strlen(cmd_path) + strlen(args) + 1);
				if (cmd_path == NULL)
				{
					perror("realloc");
					exit(EXIT_FAILURE);
				}
				strcat(cmd_path, args);
				sh_execmd(cmd_path, sh_name);
				free(path);
				free(cmd_path);
				/*exit(EXIT_SUCCESS);*/
				return (1);
			}
			free(cmd_path);
			dir = strtok(NULL, ":");
		}
		free(path);
	}
	return (0);
}

/**
 * sh_cmdpath - main fuction of path handling
 * @cmd: user's command string
 * @sh_name: name of the shell
 */
void sh_cmdpath(char **cmd, char *sh_name)
{
	char *new_cmd, *args, *new_arg, *cmd_dup = NULL;
	int is_executed;
	/**/
	cmd_dup = strdup(*cmd);
	new_cmd = strtok(cmd_dup, " \t\n");
	args = malloc(2);

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(args, " ");
	while ((new_arg = strtok(NULL, " \t\n")) != NULL)
		args = concat_args(args, new_arg);

	is_executed = check_current_dir(new_cmd, sh_name, cmd);
	if (!is_executed)
		is_executed = check_dir_in_path(new_cmd, args, sh_name);
	if (!is_executed)
		perror(sh_name);

	return;
}
