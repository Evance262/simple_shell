// #include "shell.h"

// /**
//  * takeInput - Display a prompt
//  * Return: Command entered by the user
//  */

// char *takeInput(void)
// {
// int index;
// char *buffer;
// size_t size = 0;

// if (isatty(STDIN_FILENO))
// printf("$:");
// index = getline (&buffer, &size, stdin);
// if (index == EOF)
// {
// free(buffer);

// if (isatty(STDOUT_FILENO));
// write(STDOUT_FILENO, "\n", 1);
// exit(EXIT_SUCCESS);
// }
// buffer[index - 1] = '\0';

// return (buffer);
// }



/**
 * This is a new updated function 
 * Date: Oct 29, 2021
*/

#include "shell.h"

void print_prompt(void)
{
_write("$ ");
}
