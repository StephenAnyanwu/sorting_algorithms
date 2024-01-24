#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: head pointer of the doubly linked list to sort.
 *
 * Description: print the list after each time two nodes are swapped.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr1, *ptr2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	ptr2 = (*list)->next;
	while (ptr2 != NULL)
	{
		ptr1 = ptr2->prev;
		while (ptr1 && ptr1->n > ptr2->n)
		{
			if (ptr1->prev != NULL)
				ptr1->prev->next = ptr2;
			ptr2->prev = ptr1->prev;
			ptr1->next = ptr2->next;
			if (ptr2->next != NULL)
				ptr2->next->prev = ptr1;
			ptr1->prev = ptr2;
			ptr2->next = ptr1;
			ptr1 = ptr2->prev;
			if (ptr1 == NULL)
				*list = ptr2;
			print_list((const listint_t *)*list);
		}
		ptr2 = ptr2->next;
	}
}
