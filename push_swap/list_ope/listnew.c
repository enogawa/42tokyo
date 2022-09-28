#include "../push_swap.h"

t_stacks *list_new(long	num)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if(!new)
		return (NULL);
	*new = (t_stacks){num, NULL, NULL};
	// new->data = num;
	// new->next = NULL;
	// new->prev = NULL;
	return (new);
}