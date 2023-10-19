#include "team.h"
/**
 * parse_input - Tokenize a string into an array of arguments.
 * @buf: The input string to be tokenized.
 * @args: Array to store tokenized arguments.
 */
void parse_input(char *buf, char *args[])
{
int count = 0;
char *delimiter = " \n";
char *get_token = strtok(buf, delimiter);
while (get_token != NULL)
{
args[count] = get_token;
get_token = strtok(NULL, delimiter);
count++;
}
args[count] = NULL;
}

