#include "sshell.h"

/**
 * sh_execmd - A function that execute commands
 * @cmd: Command
 * @sh_name: The name of the shell xcutable file
 */
void sh_execmd(char **cmd, char *sh_name)
{
	pid_t pid;
	char *token;
	char *cmd_tokens[128];
	char *env_paths[1] = {NULL};
	int count = 0;

	/*Creating a child process*/
	pid = fork();
	if (pid == 0)
	{
		token = strtok(*cmd, " \t\n");
		while (token != NULL)
		{
			cmd_tokens[count++] = token;
			token = strtok(NULL, " \t\n");
		}
		/*Ensure the last item is NULL*/
		cmd_tokens[count] = NULL;
		execve(*cmd, cmd_tokens, env_paths);
		perror(sh_name);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}
}























