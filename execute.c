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
if (args)
{
pid_t child = fork();
if (child == -1)
{
perror("Fork error:");
return;
}
if (child == 0)
{
char *execute_kommand = args[0];
if (execve(execute_kommand, args, NULL) == -1)
{
perror("Error:");
}
exit(EXIT_FAILURE);
}
else
{
wait(&status);
}
}
}
