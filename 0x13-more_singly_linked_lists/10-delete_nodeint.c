#include "lists.h"
/**
 * delete_nodeint_at_index - deletes a node in a linked list at an index
 * @head: pointer to the first element in the linked list
 * @index: index of the node to be deleted
 *
 * Return: 1 Success or -1 Fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current = *head;
listint_t *temp = NULL;
unsigned int n = 0;

/*checking if the list even exist*/
if (*head == NULL)
return (-1);

/* checking if given index is zero*/
if (index == 0)
{
*head = (*head)->next;
free(current);
return (1);
}

while (n < index - 1)
{
if (!current || !(current->next))
return (-1);
current = current->next;
n++;
}

temp = current->next;
current->next = temp->next;
free(temp);

return (1);
}
