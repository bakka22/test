#include "main.h"
#include <stddef.h>
#include <stdlib.h>
node *sort(node *first)
{
	node  tmp, *now, *next;
	int rep;

	rep = 1;
	while (rep)
	{
		rep  = 0;
		next = first->next;
		if (first->data > next->data)
		{
			tmp.data = first->data;
			first->data = next->data;
			next->data = tmp.data;
			rep = 1;
		}
		now = first;
		while (1)
		{
			next = now->next;
			if (next == NULL)
				break;
			if (now->data > next->data)
			{
				tmp.data = now->data;
				now->data = next->data;
				next->data = tmp.data;
				rep = 1;
			}
			now = now->next;
		}
	}
	return (first);
}