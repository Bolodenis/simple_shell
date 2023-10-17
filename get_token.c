#include "team.h"
/**
 * parse_input - Tokenize a string into an array of arguments.
 * @lineptr: The input string to be tokenized.
 * @args: An array of strings to store the tokenized arguments.
 *
 * Description:
 * This function takes an input string `lineptr` and tokenize it into individal
 * arguments, which are stored in the `args` array. It use whitespace characers
 * such as space, tab, and newline, as delimiters to separate the arguments.
 *
 * Parameters:
 *   lineptr: The input string to be tokenized.
 *   args: An array of strings to store the tokenized arguments.
 *
 * Return: No return value, but it populates the `args`
 * array with the tokenized arguments.
 */
void parse_input(char *buf, char *args[])
{
int count = 0;
char *delimiter = "\t\n ";
char *get_token = strtok(buf, delimiter);
while (get_token != NULL)
{
args[count] = get_token;
get_token = strtok(NULL, delimiter);
count++;
}
args[count] = NULL;
}

