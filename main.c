#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	node *first, *tmp;

	first = malloc(sizeof(node));
	tmp = first;
	for (i = 3; i >= 0; i--)
	{
		tmp->data = (48 + i);
		tmp->next = malloc(sizeof(node));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp = first;
	for (i = 0; i < 4; i++)
	{
		printf("%d%c\n", i, tmp->data);
		tmp = tmp->next;
	}
	first = sort(first);
	tmp = first;
	for (i = 0; i < 4; i++)
	{
		printf("%d%c\n", i, tmp->data);
		tmp = tmp->next;
	}
	tmp  = first;
	for (i = 0; i < 4; i++)
	{
		first = tmp;
		tmp = tmp->next;
		free(first);
	}
	return (0);
}