#include "team.h"
/**
 * main - Entry point of the shell program.
 *
 * Description:
 * This is the main function that serves
 * as the entry point of the shell program.
 * It initializes the shell, processes user input, and executes commands.
 *
 * Parameters:
 *   @argc: The number of command-line arguments.
 *   @argv: An array containing the command-line arguments.
 *   @env: The environment variables.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(int argc, char **argv, char **env)
{
char kommand[] = "$";
char *bufy = NULL;
ssize_t nread;
size_t bufycount = 0;
char *args[100];
bool source_pipe = isatty(STDIN_FILENO);
(void)argc;
(void)argv;
while (true)
{
if (source_pipe)
{
write(STDOUT_FILENO, kommand, strlen(kommand));
}
nread = getline(&bufy, &bufycount, stdin);
if (nread != -1)
{
int should_proceed = handle_special_commands(bufy, env);
if (!should_proceed)
{
free(bufy);
break;
}
parse_input(bufy, args);
execute_function(args);
}
if (nread == -1)
{
perror("getline not found");
free(bufy);
exit(EXIT_FAILURE);
}
if (bufy[nread - 1] == '\n')
{
bufy[nread - 1] = '\0';
}
}
return (0);
}

