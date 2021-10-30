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
 * str_env_s - envirnment variable
 * @PathName: environment name 
 * @widepath: global path
 * @next: points to the next node
 */

typedef struct serverEnv_s
{
char *pathName;
char *value;
char *widePath;
struct Next_node *next;
} serverEnv_t;

/**
 * storeData - stores data variable
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
char *history;
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
char *commandName;
void (*function)(server_t *);
} convert_t;

void print_prompt(void);
int _write(char *str);
int _putchar(char c);
int main(int argc __attribute__((unused)), char **argv);
void _getline(server_t *strucptr);
void *_calloc(unsigned int n, unsigned int size);
char *_memset(char *str, char c, unsigned int n_Byte);

#endif/*SHELL_H*/