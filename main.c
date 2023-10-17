#include"team.h"

/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: Always returns 0.
 */
int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{
char kommand[] = "$";
char *buf = NULL;
ssize_t nread;
size_t bufcount = 0;
char *args[100];
while (1)
{
write(STDOUT_FILENO, kommand, strlen(kommand));
nread = getline(&buf, &bufcount, stdin);
if (nread == -1)
{
perror("leaving shell");
free(buf);
exit(EXIT_FAILURE);
}
parse_input(buf, args);
if (args[0] != NULL)
{
execute_function(args);
}
if (buf[nread - 1] == '\n')
buf[nread - 1] = '\0';
}
free(buf);
return (0);
}
