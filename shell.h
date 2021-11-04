#ifndef _SHELL_H
#define _SHELL_L

#define BUFFSIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * serverEnv_s - environment variable
 * @PathName: environment name 
 * @widepath: global path
 * @next: points to the next node
 */

typedef struct serverEnv_s
{
char *pathName;
char *value;
char *globPath;
struct serverEnv_s *next;
} serverEnv_t;

/**
 * server_s - stores data variable
 * @cmdName: command name
 * @cmdList: command list
 * @argument: argument's arrays
 * @buff: buffer
 */

typedef struct server_s
{
char *cmdName;
char **cmdList;
char *pgName;
char **history;
char *buff;
char **argument;
serverEnv_t *env;
} server_t;

/**
 * Error - a structure for error message
 * @input: error input
 * @errorMessage: pointer to error messange
 */

typedef struct Error
{
int input;
char *errorMessange;
} Error_t;

/**
 * convert_s - convert a structure to a function
 * @commandName: input string
 * @function: pointer to a function
 */

typedef struct convert_s
{
char *cmdName;
void (*function)(server_t *);
} convert_t;

void print_prompt(void);
int _write(char *ptrstr);
int _putchar(char c);
int main(int argc __attribute__((unused)), char **argv);
void _getline(server_t *strucptr);
void (*getFunc(char *cmd))(server_t *);
void _execve(server_t *ptrData);

void *_calloc(unsigned int n, unsigned int size);
char *_memset(char *str, char c, unsigned int n_Byte);
char *_memcpy(char *dest, char *src, unsigned int size);
void *_realloc(void *ptr, unsigned int size, unsigned int n); 
serverEnv_t *_AddNodeEnd(serverEnv_t **HeadNode, char *globvalue);
void _Envserver(server_t *ptr);
serverEnv_t *_CreateNode(char *glob);
serverEnv_t *_LastNode(serverEnv_t *Node);
server_t *_countvalue(char **str);
int _Arr(char c, char *array);
int wordNum(char *str, char *aps);
char **_strtow(char *str, char *ap, char *sep);
int _checker(char c, char *E_sep);
int _checksep(char c, char *sep);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strdup(char *str);
char * my_strcpy(char *dest, char *src);
void _printEnviron(serverEnv_t *_Env);
void _Environ(server_t *ptr);
serverEnv_t *_getenv(serverEnv_t *EnvHead, char *ptrName);
char *_EnvName(char *ptrvar);
char *EnvValue(char *ptrvar);
void _setEnviron(serverEnv_t *ptrEnv, char *ptrN, char *ptrV, int ptrOW);
void _cDir(server_t *ptrData);

void freeServerData(server_t *ptrData);
void freeArgument(char **ptr);
void freeList(serverEnv_t *HeadNode);

#endif/*SHELL_H*/