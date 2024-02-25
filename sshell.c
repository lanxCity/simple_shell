#include "sshell.h"

/**
 * main - Entry point
 * @ac: shell args count
 * @av: array of shell args
 * Return: int
 */
int main(int ac, char *av[])
{
	char *input;
	size_t len;
	char *sh_name = NULL;

	sh_name = strdup(av[ac - ac]);
	while (1)
	{
		input = NULL;
		len = 0;

		prompt_disp();
		sh_input(&input, &len);


		if (strcmp(input, "exit") == 0)
		{
			free(input);
			sh_exit();
		}
		/*sh_execmd(input, sh_name);*/
		sh_cmdpath(&input, sh_name);
		free(input);
	}
	return (0);
}
