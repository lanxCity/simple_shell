#include "sshell.h"

/**
 * sh_input - A fuction that takes user input from the terminal
 * @input: user command unput
 * @len: length of the command inputted
 * Return: int
 */
int sh_input(char **input, size_t *len)
{
	ssize_t read;
	char *input_dup;
	char *is_null;

	/*getline() returns either -1 or strlen (including "\n")*/
	read = getline(input, len, stdin);

	if (read <= 1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else if (read == 1 && *input[0] == '\n')
		{
			return (0);
		}
		else
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	(*input)[strcspn(*input, "\n")] = '\0';

	/*If only spaces line are read*/
	input_dup = strdup(*input);
	is_null = strtok(input_dup, " \t\n");

	while (strtok(NULL, " \t\n"))
		continue;

	free(input_dup);

	return ((is_null == NULL) ? 0 : 1);

}















