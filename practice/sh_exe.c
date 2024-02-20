#include "sshell.h"

/**
 * sh_execmd - A function that execute commands
 * @cmd: Command
 */
void sh_execmd(char **cmd)
{
	/*Precess id variable*/
	pid_t pid;
	char cmd_path[50];
	char *cmd_token[2];
	char *env_paths[1] = {NULL};

	cmd_token[0] = strdup(*cmd);
	cmd_token[1] = NULL;

	/*Creating a path to the command*/
	strcpy(cmd_path, "/bin/");
	strcat(cmd_path, *cmd);

	/*Creating a child process*/
	pid = fork();

	if (pid == 0)
	{
		/*Executing the command in the child process*/
		execve(cmd_path, cmd_token, env_paths);
		sh_printf(*cmd);
		perror(" <<Command not found>>");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		/*If fork fails to create new process*/
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}

	/*Free the dynamically allocated memory*/
	free(cmd_token[0]);
}
