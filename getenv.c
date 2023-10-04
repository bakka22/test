#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *strcom(char *s1, char *s2)
{
	int i;
	char *buf;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (NULL);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '=')
		return (NULL);
	buf = &(s2[i]) + 1;
	return (buf);
}

char *_getenv(char *name)
{
	char *value, *buf;
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		buf = strcom(name, environ[i]);
		if (buf)
		{
			return(buf);
		}
		i++;
	}
	buf = environ[i];
	return (buf);
}