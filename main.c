#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main ()
{
	pid_t child;
	int status;
	size_t i;
	char *buf = NULL, *args[] = {buf};
	extern char **environ;

	while (1)
	{
		printf("$ ");
		getline(&buf, &i, stdin);
		child = fork();
		buf[(strlen(buf) - 1)] = '\0';
		if (child == -1)
		{
			perror("Error:\n");
			exit(1);
		}
	
		if (child == 0)
		{
			if (strcmp(buf, "cd") == 0)
				chdir("../");
			else
				execve(buf, args, environ);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}