#include "../push_swap.h"

 t_stacks *list_mv_prev(t_stacks *stacks)
 {
	t_stacks *tmp;

	while (stacks->prev)
	{
		tmp = stacks;
		stacks = stacks->prev;
	}
	return (stacks);
 }