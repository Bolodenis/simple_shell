#include "team.h"

/**
 * execute_function - Execute a shell command.
 * @args: The arguments of the command.
 *
 * Return: No return value.
 */
void execute_function(char **args)
{
char *command = NULL;
if (args)
{
command = args[0];
if (execve(command, args, NULL) == -1)
{
perror("Error:");
}
}
}
