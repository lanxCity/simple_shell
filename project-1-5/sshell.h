#ifndef SSHELL_H
#define SSHELL_H

/*Header files section*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*External variable that represents the environment variables*/
extern char **environ;

/*Prototype Section*/
void sh_printf(const char *msg);
void prompt_disp(void);
int sh_input(char **input, size_t *len);
void sh_execmd(char *cmd, char *sh);
char *concatenate_args(char *args, char *new_arg);
int check_current_dir(char *new_cmd, char *sh_name, char **cmd);
int check_dir_in_path(char *new_cmd, char *args, char *sh_name);
void sh_cmdpath(char **cmd, char *sh_name);
void sh_exit(void);
void sh_env();


#endif
