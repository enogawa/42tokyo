#include "../push_swap.h"

 t_stacks *list_mv_back(t_stacks *stacks)
 {
	t_stacks *tmp;

	while (stacks->next)
	{
		tmp = stacks;
		stacks = stacks->next;
	}
	return (stacks);
 }