#include "shell.h"

/**
 * _env - prints  built-in of the current environment.
*/
void _env(void)
{
int i;
for (size_t i = 0; environ[i]; i++)
{
printf("%s\n", environ[i]);
}
}
