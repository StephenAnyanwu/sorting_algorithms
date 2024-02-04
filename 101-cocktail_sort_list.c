#include "sort.h"

/**
 * swap_nodes - swap the nodes of listint_t doubly linked list.
 * @list: list to swap its nodes.
 * @node1: first node.
 * @node2: second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	node2->prev = node1->prev;
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node1 = node2->prev;
	if (node1 == NULL)
		*list = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr1, *ptr2, *tmp, *start = NULL, *end = NULL, *check = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	swapped = 1;
	ptr2 = (*list)->next;
	while (swapped)
	{
		tmp = ptr2->next;
		swapped = 0;
		/* Forward Pass */
		while (ptr2 != end)
		{
			ptr1 = ptr2->prev;
			if (ptr1->n > ptr2->n)
			{
				swap_nodes(list, ptr1, ptr2);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			ptr2 = tmp;
			if (tmp != end)
				tmp = tmp->next;
			if (ptr2 && ptr2->next == end)
				check = ptr2;
		}
		if (swapped == 0 || check == NULL)
			break;
		swapped = 0;
		ptr1 = check;
		tmp = ptr1->prev;
		end = check->next;
		/* Backward Pass */
		while (ptr1 != start)
		{
			ptr2 = ptr1->next;
			if (ptr1->n > ptr2->n)
			{
				swap_nodes(list, ptr1, ptr2);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			ptr1 = tmp;
			if (tmp != start)
				tmp = tmp->prev;
			if (ptr1 && ptr1->prev == start)
				check = ptr1;
		}
		ptr2 = check->next;
		start = check->prev;
	}
}
