#include "push_swap.h"

void	add_list(t_stacks **a_list, t_stacks *new)
{
	t_stacks	*tmp;

	a_list = malloc(sizeof(t_stacks));
	tmp = *a_list;

	if(tmp == NULL)
	{
		*a_list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		tmp = tmp->prev;
		tmp->next = new;
		new->prev = tmp;
		new->next = *a_list;
		(*a_list)->prev = new;
	}
	return ;

}

int	main (void)
{
	t_stacks	*num;
	t_stacks	*a_list;
	long i = 0;

	num = malloc(sizeof(t_stacks));
	while (i <= 10)
	{
		num->data = i;
		add_list(&a_list, num);
		num = num->next;
		i++;
	}
	i = 0;
	while (i <= 10)
	{
		printf("a_list %lu\n", a_list->data);
		a_list = a_list->prev;
		i++;
	}
	return (0);
}
