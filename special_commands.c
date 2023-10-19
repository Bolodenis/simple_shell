#include "team.h"
/**
 * handle_special_commands - Handle special built-in commands.
 *
 * Description:
 * This function processes the input command line and performs actions
 * for special built-in commands like "exit" and "env." If the input
 * command matches one of these special commands, the corresponding action
 * is taken, such as exiting the shell or displaying the environment variables.
 *
 * @bufy: The input command line to be processed.
 * @env: The environment variables.
 *
 * Return:
 * - 1 if the input command was a special command and was successfully handled.
 * - 0 if the input command was not a special command.
 */
int handle_special_commands(char *bufy, char **env)
{
if (bufy == NULL)
{
return (1);
}
if (strcmp(bufy, "exit\n") == 0)
{
free(bufy);
exit(0);
}
else if (strcmp(bufy, "env\n") == 0)
{
print_env(env);
free(bufy);
return (1);
}
return (1);
}

