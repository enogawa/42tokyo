#include "../push_swap.h"

void	lst_add_back(t_stacks *stacks, t_stacks *add)
{
	t_stacks	*node;

	if (!stacks || !add)
		return ;
	stacks->next = add;
	add->prev = stacks;
	node = list_mv_head(stacks);
	node = node->prev;
	//printf("add; %ld, ", node->data);
	add->next = node;
	node->prev = add;//tmp
}