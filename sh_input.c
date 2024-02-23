#include "sshell.h"

/**
 * sh_input - A fuction that takes user input from the terminal
 * @input: user command unput
 * @len: length of the command inputted
 */
void sh_input(char **input, size_t *len)
{
	ssize_t read;

	/*getline() returns either -1 or strlen (including "\n")*/
	read = getline(input, len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			sh_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			sh_printf("Command not found\n");
			exit(EXIT_FAILURE);
		}
	}
	/**
	 * strcspn returns the length of character(s)
	 * before reaching the delimiter e.g '\n'
	 */
	(*input)[strcspn(*input, "\n")] = '\0';
}
