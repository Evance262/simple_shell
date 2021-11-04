#include "shell.h"

/**
 * _printEnviron - prints environ variables
 * @_Env: variable list
 */

void _printEnviron(serverEnv_t *_Env)
{
if (_Env == NULL)
return;

_write(_Env->pathName);
_write("=");
if (_Env->value != NULL)
_write(_Env->value);
_write("\n");
_printEnviron(_Env->next);
}

/**
 * _Environ - prints the environ variable
 * @ptr: data structure
 */

void _Environ(server_t *ptr)
{
_printEnviron(ptr->env);
}

serverEnv_t *_getenv(serverEnv_t *EnvHead, char *ptrName)
{
if (EnvHead == NULL)
return (NULL);

if (_strcmp(EnvHead->pathName, ptrName) == 0)
return (EnvHead);

return (_getenv(EnvHead->next, ptrName));
}

char *_EnvName(char *ptrvar)
{
char **ptr, *name;

ptr = _strtow(ptrvar, "=", NULL);

if (ptr == NULL)
return (NULL);

name = _strdup(ptr[0]);
freeArgument(ptr);
ptr = NULL;

return (name);
}

char *EnvValue(char *ptrvar)
{
char **ptr, *name;
ptr = _strtow(ptrvar, "=", NULL);

if (ptr == NULL)
return(NULL);

ptr = _strdup(ptr[1]);
freeArgument(ptr);
ptr = NULL;

return (name);
}
