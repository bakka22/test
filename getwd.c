#include <unistd.h>
#include <stdio.h>
int main()
{
	char buf[1024];

	getcwd(buf, 1024);
	if (buf)
	{
		printf("%s\n", buf);
	}
	chdir("/home/vagrant");
	getcwd(buf, 1024);
	printf("%s\n", buf);
	return (0);
}