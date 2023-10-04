#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int arc, char **arv)
{
	int i, j, x, y;
	FILE *source, *target;
	char *buf = NULL, tmp[1024], tmp2[1024];
	size_t n;

	if (arc < 2)
	{
		fprintf(stderr, "usage : tabtosp <filename>\n");
		return (1);
	}
	/*tmp2 = malloc(sizeof(char) * 1024);
	if (tmp2 = NULL)
	{
		fprintf(stderr, "unxpected error\n");
		exit(1);
	}*/
	for (i = 1; i <= arc; i++)
	{
		strcpy(tmp, arv[i]);
		strcat(tmp, "___");
		source = fopen(arv[i], "r");
		if (source == NULL)
		{
			fprintf(stderr, "couldn't open file \"%s\"\n", arv[i]);
			continue;
		}
		target = fopen(tmp, "a");
		if (target == NULL)
		{
			fprintf(stderr, "unxpected error\n");
			continue;
		}
		while (getline(&buf, &n, source) != -1)
		{
			j = 0;
			x = 0;
			printf("%s", buf);
			while (buf[j] != '\0')
			{
				if (buf[j] == '\t')
				{
					for (y = 0; y < 4; y++)
					{
						tmp2[x] = ' ';
						x++;
					}
					j++;
				}
				else
				{
					tmp2[x] = buf[j];
					j++;
					x++;
				}
			}
			tmp2[x] = '\0';
			printf("%s", tmp2);
			fputs(tmp2, target);
		}
	}
	return (0);
}