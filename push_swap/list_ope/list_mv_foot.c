#include "../push_swap.h"

 t_stacks *list_mv_foot(t_stacks *stacks)
 {
	t_stacks *tmp;

	if (stacks->data == -1)
	{
		tmp = stacks;
		stacks = stacks->prev;
		return (stacks);
	}
	while (stacks->next->data != -1)
	{
		tmp = stacks;
		stacks = stacks->next;
	}
	return (stacks);
 }