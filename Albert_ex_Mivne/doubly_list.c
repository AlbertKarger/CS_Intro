#include <stdlib.h>
#include "doubly_list.h"

void init_list(list *lst)
{
	lst->head = lst->tail = NULL;	
}

//is list empty
int isEmpty(list *lst)
{
	return lst->head == NULL;
}

int length(list *lst)
{
	int length = 0;
	node *current;
	
	for(current = lst->head; current != NULL; current = current->next)
		length++;
	
   return length;
}

//insert link at the first location
void insertFirst(list *lst, list_type value)
{
	//create a new link
	node *link = (node*)malloc(sizeof(node));
	link->value = value;
	link->next = NULL;
	link->prev = NULL;
	
	if(isEmpty(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;	
	}
	else 
	{
		//update first prev link
		lst->head->prev = link;
		//point it to old first link
		link->next = lst->head;
		//point first to new first link
		lst->head = link;
	}
}

//insert link at the last location
void insertLast(list *lst, list_type value)
{
	//create a new link
	node *link = (node*)malloc(sizeof(node));
	link->value = value;
	link->next = NULL;
	link->prev = NULL;
	
	if(isEmpty(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;		 
	}
	else 
	{
		//make link a new last link
		lst->tail->next = link;     
		//mark old last node as prev of new link
		link->prev = lst->tail;
		//point last to new last node
		lst->tail = link;
	}
}

//delete first item
int deleteFirst(list *lst)
{	
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to first link
		node *temp = lst->head;

		//if only one link
		if(temp->next == NULL)
		{			
			init_list(lst);
		}
		else
		{
			lst->head->next->prev = NULL;
			lst->head = lst->head->next;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link at the last location
int deleteLast(list *lst)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to last link
		node *temp = lst->tail;

		//if only one link
		if(temp->prev == NULL)
		{			
			init_list(lst);
		}
		else
		{
			lst->tail->prev->next = NULL;
			lst->tail = lst->tail->prev;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete a link at spesific index
int deleteLink(list *lst, int idx)
{
	if (!isEmpty(lst))
	{
		int i;
		//start from the first link
		node* current = lst->head;

		//navigate through list
		for (i=0; i<idx && current != NULL ;i++)
			current = current->next;

		if (current == NULL)
			return 0;
		if (current == lst->head)
			return deleteFirst(lst);
		if (current == lst->tail)
			return deleteLast(lst);
		
		//bypass the current link
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		return 1;
	}
	return 0;
}

int insertAfter(list *lst, list_type value, int idx)
{
	if (!isEmpty(lst))
	{
		int i;
		//start from the first link
		node* current = lst->head;
		node* newLink = NULL;

		//navigate through list
		for (i=0; i<idx && current != NULL ;i++)
			current = current->next;

		if (current == NULL)
			return 0;
		if (current == lst->tail)
		{
			insertLast(lst,value);
			return 1;
		}

		//create a link
		newLink = (node*)malloc(sizeof(node));
		newLink->value = value;
		//assign new link pointers
		newLink->prev = current;
		newLink->next = current->next;
		//chain current and current->next to new link
		current->next->prev = newLink;
		current->next = newLink;
		return 1;
	}
	return 0;
}

int insertBefore(list *lst, list_type value, int idx)
{
	return 0;
}
