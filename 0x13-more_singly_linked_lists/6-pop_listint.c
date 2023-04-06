#include "lists.h"
/**
 * pop_listint - deletes the head node of a linked list listint_t
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the elements that was deleted, or 0
 */

int pop_listint(listint_t **head)
{
listint_t *current;
int n;

/*checking if head points to NULL*/
if (!head || !*head)
return (0);

/*initializing n to get the data inside the element or node*/
n = (*head)->n;

/*using current to travers*/
current = (*head)->next;
/*freed head*/
free(*head);
*head = current;

return (n);
}
