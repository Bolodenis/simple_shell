#include "team.h"
/**
 * parse_input - Tokenize a string into an array of arguments.
 * @bufy: The input string to be tokenized.
 * @args: Array to store tokenized arguments.
 */
void parse_input(char *bufy, char *args[])
{
int count = 0;
char *delimita = " \n";
char *get_token = strtok(bufy, delimita);
while (get_token != NULL)
{
args[count] = get_token;
get_token = strtok(NULL, delimita);
count++;
}
args[count] = NULL;
}

