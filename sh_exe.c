#include "sshell.h"

/**
 * sh_execmd - A function that execute commands
 * @cmd: Command
 * @sh_name: The name of the shell xcutable file
 */
void sh_execmd(char *cmd, char *sh_name)
{
	pid_t pid;
	char *cmd_tokens[2];
	char *env_paths[1] = {NULL};
	/*Creating a child process*/
	pid = fork();

	cmd_tokens[0] = cmd;
	cmd_tokens[1] = NULL;

	if (pid == 0)
	{
		/*Ensure the last item is NULL*/
		execve(cmd, cmd_tokens, env_paths);
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
