#include "sshell.h"

/**
 * main - Entry point
 * Return: int
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;

	while (1)
	{
		prompt_disp();
		if (sh_input(&input, &len))
			sh_execmd(input);
	}

	free(input);
	return (0);
}
