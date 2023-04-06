#include "lists.h"
/**
 * sum_listint - adds the sum of all the data in a linked list
 * @head: first node in the linked list
 *
 * Return: added sum
 */
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *current = head;

/*Using temp to travers through the list*/
while (current)
{
sum += current->n;
current = current->next;
}

return (sum);
}
