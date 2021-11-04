#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
int i;
void (*function)(server_t *);
server_t *serverptr = NULL;

serverptr = _countvalue(argv);

do
{
/* code */
print_prompt();

_getline(serverptr);

serverptr->history = _strtow(serverptr->buff, ";\n", ":");

if (serverptr->history == NULL)
{
freeServerData(serverptr);
free(serverptr);
continue;
}

for (i = 0; serverptr->history[i] != NULL; i++)
{
serverptr->argument = _strtow(serverptr->history[i], "\n", ":");

if (serverptr->argument == NULL)
{
freeServerData(serverptr);
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
_execve(serverptr);
}
freeArgument(serverptr->argument);
serverptr->argument = NULL;
free(serverptr->cmdName);
serverptr->cmdName = NULL;
}
freeServerData(serverptr);
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
_putchar('\n');
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
void (*getFunc(char *ptrcmd))(server_t *)
{
int i = 0;

convert_t ops[] = 
{
{"cd", _cDir},
{"env", _Environ},
{"setenv", _setEnviron},
{"unsetenv", _unsetEnviron},
{"exit", _Exit},
{"help", _Help}

};

while (i < 6)
{
if (_strcmp(ptrcmd, (ops + 1)->cmdName) == 0)
return ((ops + i)->function);
i++;
}
return (NULL);
}

void _execve(server_t *ptrData)
{
pid_t pid;
char *cmd;
int s;

if (ptrData->cmdName == NULL)
return;

cmd = _which(ptrData);

if (cmd != NULL)
{
if (ptrData->cmdName != cmd)
free(ptrData->cmdName);
ptrData->cmdName = cmd;
}
else
{
return;
}

pid = fork();
if (pid == 0)
{
if (execve(ptrData->cmdName, ptrData->argument, NULL) == -1)
_Error(ptrData, 103);
return;
}
else if (pid == -1)
{
_Error(ptrData, 102);
}
else
waitpid(pid, &s, WUNTRACED);
}
