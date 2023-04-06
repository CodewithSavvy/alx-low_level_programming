#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to be look for
 *
 * Return: address of the node, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *up = head;
listint_t *down = head;

/*checking if head even exists*/
if (!head)
return (NULL);

while (down && up && up->next)
{
up = up->next->next;
down = down->next;
if (up == down)
{
down = head;
while (down != up)
{
down = down->next;
up = up->next;
}
return (up);
}
}

return (NULL);
}
