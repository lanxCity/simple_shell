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

	input = NULL;
	len = 0;

	ac = 0;

	prompt_disp();
	sh_input(&input, &len);
	sh_execmd(&input, av[ac]);

	/*Free memory allocated by getline*/
	free(input);

	return (0);
}
