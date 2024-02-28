#include "sshell.h"

/**
 * main - Entry point
 * @ac: shell args count
 * @av: array of shell args
 * Return: int
 */
int main(int ac, char *av[])
{
	char *input = NULL;
	size_t len = 0;
	char *sh_name = NULL;
	int is_input;

	sh_name = strdup(av[ac - ac]);
	while (1)
	{
		prompt_disp();
		is_input = sh_input(&input, &len);

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			sh_exit();
		}
		else if (strcmp(input, "env") == 0)
		{
			sh_env();
		}
		else
		{
			if (is_input)
				sh_cmdpath(&input, sh_name);
		}
	}

	free(input);
	return (0);
}
