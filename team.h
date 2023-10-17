#ifndef TEAM_H_
#define TEAM_H_

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_function(char **args);
void parse_input(char *buf, char *args[]);
int handle_special_commands(char *lineptr, char **env);
void print_env(char **env);
#endif
