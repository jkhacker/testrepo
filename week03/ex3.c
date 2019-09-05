#include "stdio.h"
#include "stdlib.h"
#ifndef EXIT_ERROR
#define EXIT_ERROR 1
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

typedef struct _Node
{
	struct _Node *next;
	int data;
} Node;

typedef struct
{
	Node *head;
	unsigned int size;
} List;

int insert_node(List *list, int data, unsigned int index)
{
	if(index == 0)
	{
		if(list->size == 0)
		{
			list->head = malloc(sizeof(Node));
			if(!list->head)
			{
				return EXIT_ERROR;
			}
			list->head->data = data;
			list->head->next = NULL;
			list->size = 1;
		}
		else
		{
			Node *temp = list->head;
			list->head = malloc(sizeof(Node));
			if(!list->head)
			{
				return EXIT_ERROR;
			}
			list->head->data = data;
			list->head->next = temp;
			list->size++;
		}
	}
	else if(index > list->size)
	{
		return EXIT_ERROR;
	}
	else
	{
		Node *temp = list->head;
		for(unsigned int i = 0; i <= index; i++)
		{
			temp = temp->next;
		}
		Node *insert = malloc(sizeof(Node));
		if(!insert)
		{
			return EXIT_ERROR;
		}
		insert->next = temp->next;
		insert->data = data;
		temp->next = insert;
		list->size++;
	}
	
	return EXIT_SUCCESS;
}

int delete_node(List *list, unsigned int index)
{
	if(index >= list->size)
	{
		return EXIT_ERROR;
	}
	Node *temp = list->head;
	Node *del = NULL;
	if(index == 0)
	{
		temp = list->head->next;
		free(list->head);
		list->head = del;
		list->size--;
		return EXIT_SUCCESS;
	}
	for(unsigned int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	del = temp->next;
	temp->next = temp->next->next;
	free(del);
	list->size--;
	
	return EXIT_SUCCESS;
}

int print_list(List list)
{
	if(list.size == 0)
	{
		return EXIT_ERROR;
	}
	unsigned int i = 0;
	Node *temp = list.head;
	while(temp)
	{
		printf("Index: %u Data: %d\n", i, temp->data);
		temp = temp->next;
	}
	return EXIT_SUCCESS;
}