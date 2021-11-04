#include "shell.h"

/**
 * freeServerData - free all pointers 
 * @ptrData: pointer to data stored
 */

void freeServerData(server_t *ptrData)
{
if (ptrData == NULL)
return;

if (ptrData->argument != NULL)
freeArgument(ptrData->argument);
ptrData->argument = NULL;

if (ptrData->buff != NULL && ptrData->cmdName !=  NULL)
free(ptrData->buff);
ptrData->buff = NULL;
free(ptrData->cmdName);
ptrData->cmdName = NULL;

if (ptrData->cmdList != NULL && ptrData->history != NULL)
freeArgument(ptrData->cmdList);
ptrData->cmdList = NULL;
freeArgument(ptrData->history);
ptrData->history = NULL;

}

/**
 * freeArgument - free the memory of a double pointer
 * @ptr: double pointer
 */

void freeArgument(char **ptr)
{
int i;

if (ptr == NULL)
return;

for (i = 0; ptr[i] != NULL; i++)
{
free(ptr[i]);
ptr[i] = NULL;
}
free(ptr);
}

void freeList(serverEnv_t *HeadNode)
{
if (HeadNode == NULL)
return;

freeList(HeadNode->next);
free(HeadNode->pathName);
HeadNode->pathName = NULL;

free(HeadNode->value);
HeadNode->value = NULL;

free(HeadNode->globPath);
HeadNode->globPath = NULL;
free(HeadNode);
}