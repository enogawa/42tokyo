#include "../push_swap.h"

 t_stacks *list_mv_head(t_stacks *stacks)
 {
	t_stacks *tmp;

	if (stacks->data == -1)//test
	{
		tmp = stacks;
		stacks = stacks->next;
		return (stacks);
	}
	while (stacks->prev->data != -1)
	{
		tmp = stacks;
		stacks = stacks->prev;
	}
	return (stacks);
 }