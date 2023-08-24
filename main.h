#ifndef MAIN_H
#define MAIN_H
typedef struct node node_pointer;
typedef struct node
{
	char data;
	node_pointer *next;
}node;
node *sort(node *first);
#endif