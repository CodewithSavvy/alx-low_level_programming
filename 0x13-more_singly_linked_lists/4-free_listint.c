#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: the pointer to be free
 *
 * Return: nothing(void)
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (current)
	{
		current = current->next;
		free(head);
		head = current;
	}

}
