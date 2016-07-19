#include<stdlib.h>
#include<stdio.h>
#include "sll_node.h"

#define FALSE	0
#define TRUE	1

int sll_insert(Node **rootp, int new_value)
{
	Node *current;
	Node *previous;
	Node *new;

	current = *rootp;
	previous = NULL;

	while(current != NULL && current->value < new_value){
		previous = current;

		current = current -> link;

	}

	new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		return FALSE;
	new->value = new_value;

	new->link = current;
	if (previous == NULL)
		*rootp = new;
	else
		previous->link = new;
	return TRUE;

}
