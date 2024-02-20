#include "sshell.h"

/**
 * main - Entry point
 * Return: int
 */
int main(void)
{
	char *input;
	size_t len;

	input = NULL;
	len = 0;

	prompt_disp();
	sh_input(&input, &len);
	sh_execmd(&input);

	/*Free memory allocated by getline*/
	free(input);

	return (0);
}
