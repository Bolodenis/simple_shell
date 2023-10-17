#include "team.h"
/**
 * print_env - Display system environment variables.
 * it takes an array of system environment variables
 * and prints them to the standard output.
 * @env: An array of strings containing system environment variables.
 */
void print_env(char **env)
{
int i = 0;
while (env[i] != NULL)
{
size_t len = strlen(env[i]);
write(STDOUT_FILENO, env[i], len);
write(STDOUT_FILENO, "\n", 1);
i++;
}
}

