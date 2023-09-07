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
	buf = &(s2[i]) + 1;
	return (buf);
}

int main(int ac, char **av)
{
	char *value, *buf;
	extern char **environ;
	int i;

	while (environ[i])
	{
		buf = strcom(av[0], environ[i]);
		if (buf)
		{
			printf("%s\n", buf);
			break;
		}
		i++;
	}
	return (0);
}