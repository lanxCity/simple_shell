#include "sshell.h"

/**
 * sh_input - A fuction that takes user input from the terminal
 * @input: user command unput
 * @len: length of the command inputted
 */
int sh_input(char **input, size_t *len)
{
	ssize_t read;
	char *input_dup = NULL;
	char *is_null;

	/*getline() returns either -1 or strlen (including "\n")*/
	read = getline(input, len, stdin);

	if (read <= 1)
	{
		if (feof(stdin))
		{
			sh_printf("\n");
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

	while (strtok(NULL, " \t\n"));


	if (is_null == NULL)
	{
		return (0);
	}

	return (1);

}















