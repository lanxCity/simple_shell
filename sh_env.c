#include "sshell.h"

/**
 * sh_env - A function that prints environment variables
 */
void sh_env(void)
{
	char **env, *env_name, *env_val;
	/*Iterate through the environment variables and print them*/
	for (env = environ; *env != NULL; env++)
	{
		env_name = strtok(*env, "=");
		env_val = strtok(NULL, "=");
		/**/
		if (env_name != NULL && env_val != NULL)
		{
			sh_printf(env_name);
			sh_printf("=");
			sh_printf(env_val);
		}
		sh_printf("\n");
	}
}
