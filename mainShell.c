#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
int i = 0;
void (*function)(server_t *);
server_t *serverptr = NULL;

serverptr = count(argv);

do
{
/* code */
print_prompt();

_getline(serverptr);

serverptr->history = strtow(serverptr->buff, ";\n", ":");

if (serverptr->history == NULL)
{
freeServerData(serverptr);
free(serverptr);
continue;
}

while (serverptr->history[i] != NULL)
{
serverptr->argument = _strtow(serverptr->history[i], "\n", ":");

if (serverptr->argument == NULL)
{
freeserverData(serverptr);
freeList(serverptr->env);
serverptr->env = NULL;
free(serverptr);
serverptr = NULL;
break;
}

serverptr->cmdName = strdup(serverptr->argument[0]);

if (serverptr->cmdName != NULL)
{
function = getFunc(serverptr->cmdName);

if (function != NULL)
function(serverptr);
else
executeCmd(serverptr);
}
freeArgument(serverptr->argument);
serverptr->argument = NULL;
free(serverptr->cmdName);
serverptr->cmdName = NULL;
}
freeserverptr(serverptr);
i++;
} while (1);

return (EXIT_SUCCESS);
}

/**
 * _getline - return a command line by user
 * @strucptr: a structure pointer
 */
 
void _getline(server_t *strucptr)
{
int i = 0, read_line, size = BUFFSIZE;
char s = '\0';

strucptr->buff = _calloc(sizeof(char), BUFFSIZE);

while (s != '\n' && s != EOF)
{
read_line = read(STDIN_FILENO, &s, 1);

if (read_line == 0)
{
_write('\n');
if (strucptr->env != NULL)
freeList(strucptr);
free(strucptr);
exit(EXIT_SUCCESS);
}
if (i >= size - 1)
{
strucptr->buff = _realloc(strucptr->buff, size, sizeof(char) * (i + 2));
size = i + 2;
}
strucptr->buff[i] = s;
i++;
}
strucptr->buff[i] = '\0';
}
