#include <stdio.h>
#include <stdlib.h>

/* Contains value & reference to the next node (if any) */
struct Node
{
	int value;
	struct Node * next_node;
};

/* Constructor function for the Node structure */
struct Node * N_constr(int value, struct Node * next_node); // Node constructor

/* Contains the size of the list & reference to the head node */
struct LinkedList
{
	int size;
	struct Node * head;
};

/* Constructor function for the LinkedList structure */
struct LinkedList * LL_constr(); // LinkedList constructor
	
/* Returns a pointer to the i'th element of the list */
struct Node * get_node(struct LinkedList * list, int index);

/* Allows to insert node to the certain index with integer value */
void insert_node(struct LinkedList * list, int index, int value);

/* Removes the i'th node & returns it's value */
int delete_node(struct LinkedList * list, int index);

/* Prints every element of the list to the screen */
void print_list(struct LinkedList * list);

int main()
{
	struct LinkedList * list = LL_constr();

	insert_node(list, 0, 10);
	print_list(list);	
	insert_node(list, 1, 30);
	print_list(list);	
	insert_node(list, 2, 50);
	print_list(list);	
	insert_node(list, 3, 70);
	print_list(list);	
	printf("Deleted node is 0 with value %d\n", delete_node(list, 0));
	print_list(list);	

	return 0;
}

struct LinkedList * LL_constr()
{
	struct LinkedList * list = malloc(sizeof(struct LinkedList));
	list->size = 0;
	list->head = NULL;
	return list;
}
struct Node * N_constr(int value, struct Node * next_node)
{
	struct Node * node = malloc(sizeof(struct Node));
	node->value = value;
	node->next_node = next_node;
	return node;
}

struct Node * get_node(struct LinkedList * list, int index)
{
	if (index >= list->size || index < 0)
	{
		printf("Wrong index! (Size of the list is %d)\n", list->size);
	}
	else
	{	
		struct Node * node = list->head;
		for (int i = 0; i < index; ++i)
			node = node->next_node;
		return node;
	}
	return NULL;
}
void insert_node(struct LinkedList * list, int index, int value)
{
	if (index > list->size || index < 0)
	{
		printf("Wrong index! (Size of the list is %d)\n", list->size);
	}
	else
	{
		if (list->size == 0)
		{
			struct Node * node = N_constr(value, NULL);
			list->head = node;
		}
		else
		{
			if (index == 0)
			{
				struct Node * node = N_constr(value, list->head);
				list->head = node;	
			}
			else if (index == list->size)
			{
				struct Node * node = N_constr(value, NULL);
				get_node(list, index - 1)->next_node = node;
			}
			else
			{
				struct Node * node = N_constr(value, get_node(list, index));
				get_node(list, index - 1)->next_node = node;
			}
		}
		list->size++;
	}
}
int delete_node(struct LinkedList * list, int index)
{
	int value = 0;
	if (index >= list->size || index < 0)
	{
		printf("Wrong index! (Size of the list is %d)\n", list->size);
	}
	else
	{
		value = get_node(list, index)->value;
		if (index == 0)
		{
			if (list->size > 1) 
			{
				struct Node * temp = list->head;
				list->head = get_node(list, index)->next_node;
				temp->next_node = NULL;
				free(temp);	
			}
			else
			{
				struct Node * temp = list->head;
				list->head = NULL;
				free(temp);
			}	
		}
		else if (index == list->size - 1)
		{
			struct Node * temp = get_node(list, index);
			get_node(list, index - 1)->next_node = NULL;
			free(temp);
		}
		else
		{
			struct Node * temp = get_node(list, index);
			get_node(list, index - 1)->next_node = temp->next_node;
			free(temp);
		}
		list->size--;
	}
	return value;
}
void print_list(struct LinkedList * list)
{
	printf("List:\n");
	struct Node * node = list->head;
	for (int i = 0; i < list->size; ++i)
	{
		printf("%d ", node->value);
		node = node->next_node;
	}
	printf("\n");
}
