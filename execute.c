#include "team.h"

/**
 * execute_function - Execute a shell command.
 * @args: The arguments of the command.
 *
 * Return: No return value.
 */
void execute_function(char **args)
{
char *execute_command = NULL;
if (args)
{
execute_command = args[0];
if (execve(execute_command, args, NULL) == -1)
{
perror("Error:");
}
}
}
