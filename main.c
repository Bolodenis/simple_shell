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
char kommand[160] = "Denis$";
char *lineptr = NULL;
size_t len = 0;
int read_bytes;
char *args[135];
bool source_pipe = isatty(STDIN_FILENO);
while (true)
{
if (source_pipe)
{
write(STDOUT_FILENO, kommand, strlen(kommand));
read_bytes = getline(&lineptr, &len, stdin);
if (read_bytes == -1)
{
perror("getline not found");
free(lineptr);
exit(EXIT_FAILURE);
}
if (read_bytes > 1)
{
int numb_count = 0;
char *get_token = strtok(lineptr, "\t\n ");
while (get_token != NULL)
{
args[numb_count++] = get_token;
get_token = strtok(NULL, "\t\n ");
}
args[numb_count] = NULL;
execute_function(args);
}
}
if (lineptr[read_bytes - 1] == '\n')
lineptr[read_bytes - 1] = '\0';
}
return (0);
}
