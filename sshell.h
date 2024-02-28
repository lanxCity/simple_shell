#ifndef SSHELL_H
#define SSHELL_H

/*Header files section*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Prototype Section*/
void sh_printf(const char *msg);
void prompt_disp(void);
int sh_input(char **input, size_t *len);
void sh_execmd(char *cmd);

#endif
