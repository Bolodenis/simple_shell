#include "team.h"

/**
 * execute_function - Execute a shell command.
 * @args: The arguments of the command.
 *
 * Return: No return value.
 */
void execute_function(char **args)
{
int status;
pid_t child = fork();
if (child == -1)
{
perror("Error forking.\n");
exit(EXIT_FAILURE);
}
if (child == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("Error executing command");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}
