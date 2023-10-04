#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int i = 0;
	char *buf;
	buf = _getenv(name);
	if (buf && overwrite)
	{
		for(i = 0; buf[i] != '\0'; i++)
	}
	
}