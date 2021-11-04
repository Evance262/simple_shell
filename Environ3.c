#include "shell.h"

void _setEnviron(serverEnv_t *ptrEnv, char *ptrN, char *ptrV, int ptrOW)
{
serverEnv_t *E_node;
char *ptr;

if (ptrN == NULL || ptrV == NULL)
return;

E_node = _getenv(ptrEnv, ptrN);

if (E_node == NULL)
{
ptr = _getenv(ptrN, ptrV);
_AddNodeEnd(&ptrEnv, ptr);
free(ptr);
}
else if (ptrOW == 1)
{
free(E_node->value);
E_node->value = _strdup(ptrV);
}
}

/**
 * _cDir - change current directory
 * @ptrData: data structure
 */

void _cDir(server_t *ptrData)
{
	char cD[500];

	getcwd(cD, 500);

	if (ptrData == NULL)
		return;

	if (
		!ptrData->argument[1] ||
		_strcmp(ptrData->argument[1], "~") == 0 ||
		_strcmp(ptrData->argument[1], "~/") == 0
	)
		_cDHome(ptrData, cD);
	else if (_strcmp(ptrData->argument[1], "-") == 0)
		_cD_prev(ptrData, cD);
	else
		_changeToAnyDirectory(ptrData, cD);
}
