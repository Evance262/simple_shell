#include "shell.h"

/**
 * _write - prints a character to stdout
 * @c: a character to print
 * 
 * Return: numebr of printed characters
 */

int _write(char c)
{
return(write(STDIN_FILENO, &c, 1));
}

/**
 * _printstr - prints all characters from string to stdout.
 * @c: characters in string form
 *
 * Return: No of printed characters
 */

int _printstr(char *c)
{
int i, overall = 0;

for (i = 0; c[i]; i++)
{
overall += _write(c[i]);
}
return (overall);
}
