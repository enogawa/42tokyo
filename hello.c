#include "push_swap.h"

void	add_list(t_stacks **a_list, t_stacks *new)
{
	t_stacks	*tmp;
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

int	main(void)
{
	t_stacks	*num;
	t_stacks	*a_list;
	t_stacks	*tmp;
	long i = 0;

	num = malloc(sizeof(t_stacks));
	// a_list = malloc(sizeof(t_stacks));
	i = 0;
	while (i < 10)
	{
		num[i].data =  i;
		num[i].prev = NULL;
		num[i].next = NULL;
		add_list(&a_list, &num[i]);
		i++;
	}
	printf("ziped\n");//test
	tmp = a_list;
	i = 0;
	while (i < 10)
	{
		printf("prev;  %lu\n", tmp->data);
		tmp = tmp->prev;
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 10)
	{
		printf("next;  %lu\n", tmp->data);
		tmp = tmp->next;
		i++;
	}
	return (0);
}