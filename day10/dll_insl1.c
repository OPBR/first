#include<stdlib.h>
#include<stdio.h>
#include "doubly_linked_list_node.h"


int dll_insert( Node *rootp, int value )
{
	Node *this;
	Node *next;
	Node *newnode;


	for ( this = rootp; (next = this->fwd) != NULL; this = next ){
	
		if ( next->value == value){
			return 0;
		}

		if (next->value > value){
			break;
		}
	}

	newnode = (Node *)malloc(sizeof(Node));
	if (newnode == NULL)
		return -1;
	newnode->value = value;

	if (next != NULL)			//The node is located in the middle or at the begining
	{
		if (this == rootp){		//The node is located in the begining
			rootp->fwd = newnode;
			newnode->fed = next;
			next->bwd = newnode;
			newnode->bwd = NULL;
	
		}	

		else{				//The node is located in the middle
			this->fwd = newnode;
			newnodw->fwd = next;
			next->bwd = newnode;
			newnode->bwd = this;
		
		}	
	
	}

	else					//The node is located in the end or begining
	{
		if (this == rootp){		//The node is located in the begining
			rootp->fwd = newnode;
			newnode->fwd = NULL;
			rootp->bwd = newnode;
			newnode->bwd = NULL;
		
		}

		else{				//The node is located in the end
			this->fwd = newnode;
			newnode->fwd = NULL;
			rootp->bwd = newnode;
			newnode->bwd = this;
		
		}
	
	}

	return 1;

}
