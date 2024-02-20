#include "sshell.h"

/**
 * sh_printf - A custom printf
 * @msg: parameter
*/
void sh_printf(const char *msg)
{
	write(STDOUT_FILENO, msg, strlen(msg));
}
