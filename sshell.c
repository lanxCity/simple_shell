#include "sshell.h"

/**
 * main - Entry point
 * @ac: shell args count
 * @av: array of shell args
 * Return: int
 */
int main(int ac, char *av[] )
{
	char *input = NULL;
	size_t len = 0;
	char *sh_name = NULL;

	sh_name = strdup(av[ac - ac]);
	while (1)
	{
		prompt_disp();
		if (sh_input(&input, &len))
			sh_execmd(input, sh_name);
	}

	free(sh_name);
	free(input);
	return (0);
}
