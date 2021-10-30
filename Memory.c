#include "shell.h"

/**
 * _calloc - allocates memory for ana array
 * @n: number of a character
 * @size: size of memory
 */

void *_calloc(unsigned int n, unsigned int size)
{
void *ptr;

if (n == 0 || size == 0)
return (NULL);

ptr = malloc(size * n);

if (ptr == NULL)
return (NULL);

ptr = memset(ptr, 0, n * size);

return (ptr);
}

/**
 * memset - fills the memory area pointed to by the
 * constant byte
 * @str: memory area pointer
 * @ c: constant
 * @n_Byte: No of byte to fill
 *
 * Return: number of bytes to the memory area
 */

char *_memset(char *str, char c, unsigned int n_Byte)
{
unsigned int i = 0;

while (i < n_Byte)
{
str[i] = c;
i++;
}
return (str);
}
