#include <dirent.h>
#include <stdio.h>
int main()
{
	dirent *p;

	p = readdir("/home/vagrant");
	printf("%s\n", p->d_name);
	return (0);
}
