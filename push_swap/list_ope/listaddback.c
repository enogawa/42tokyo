#include "../push_swap.h"

void	lst_add_back(t_stacks *stacks, t_stacks *add)
{
	if (!stacks || !add)
		return ;
	stacks->next = add;
	add->prev = stacks;
}