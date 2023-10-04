#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
typedef struct list_t 
{
	char *str;
	struct list_t *next;
} list_t;
void printpath();
char *_getenv(char *name);
list_t *creatlp();
#endif
