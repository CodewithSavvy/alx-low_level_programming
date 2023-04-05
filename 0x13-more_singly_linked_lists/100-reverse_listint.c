#include "lists.h"
/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *back = NULL;
listint_t *front = NULL;

while (*head)
{
front = (*head)->next;
(*head)->next = back;
back = *head;
*head = front;
}
*head = back;
return (*head);
}
