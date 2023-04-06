#include "lists.h"

/*****prototypes********/
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of nodes
 * in a looped listint_t list.
 * @head: pointer to the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 */

size_t looped_listint_len(const listint_t *head)
{
const listint_t *current, *temp;
size_t n = 1;

/*checking if head head of next is pointing to NULL*/
if (head == NULL || head->next == NULL)
return (0);
current = head->next;
temp = (head->next)->next;

while (temp)
{
if (current == temp)
{
current = head;
while (current != temp)
{
n++;
current = current->next;
temp = temp->next;
}
current = current->next;
while (current != temp)
{
n++;
current = current->next;
}
return (n);
}
current = current->next;
temp = (temp->next)->next;
}
return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t n, ind = 0;

n = looped_listint_len(head);
if (n == 0)
{
for (; head != NULL; n++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (ind = 0; ind < n; ind++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
printf("-> [%p] %d\n", (void *)head, head->n);
}
return (n);
}
