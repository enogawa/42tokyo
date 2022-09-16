#include "push_swap.h"

t_stacks	*test(void)
{
	t_stacks	*a_list;
	t_stacks	*tmp;
	int			num[] = {1,7,3,98,36,267};
	int			i;

	a_list = malloc(sizeof(t_stacks));
	a_list->data = num[0];
	tmp = a_list;
	i = 1;
	while (i <= 5)
	{
		tmp->next = malloc(sizeof(t_stacks));
		tmp = tmp->next;
		tmp->data = num[i];
		i++;
	}
	tmp->next = malloc(sizeof(t_stacks));
	tmp = tmp->next;
	tmp->data = -1;
	return (a_list);
}

int	main(void)
{
	t_stacks *a_list;

	a_list = test();
	while (a_list->data != -1)
	{
		printf("%ld,", a_list->data);
		a_list = a_list->next;
	}
	return (0);
}