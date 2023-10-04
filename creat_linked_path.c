#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
*add_node_end - add a new list node at head
*@head :the head of the node
*@str :string on the node
*Return: a pointer to the head of the list
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tmp;

	tmp = *head;
	if (tmp != NULL)
	{
		while (1)
		{
			if (tmp->next == NULL)
			{
				break;
			}
			tmp = tmp->next;
		}
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
		tmp->next = new;
	return (new);
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
list_t *creatlp()
{
	char *buf;
	list_t *head = NULL;

	buf = _getenv("PATH");
	if (buf)
	{
		buf = strtok(buf, "/");
		while (buf)
		{
			add_node_end(&head, buf);
			buf = strtok(NULL, "/");
		}
	}
	return (head);
}