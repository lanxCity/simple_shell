#include "sshell.h"

/**
 * sh_env - A function that prints environment variables
 */
void sh_env(void)
{
	char **env, *name, *value;
	/*Iterate through the environment variables and print them*/
	for (env = environ; *env != NULL; env++)
	{
		name = strtok(*env, "=");
		value = strtok(NULL, "=");
		/**/
		if (name != NULL && value != NULL)
		{
			sh_printf(name);
			sh_printf("=");
			sh_printf(value);
		}
		sh_printf("\n");
	}
}
