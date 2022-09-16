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

void	list_init(int	*ziped_num)
{
	t_stacks	*num;
	t_stacks	*a_list;
	t_stacks	*tmp;
	long i = 0;

	num = malloc(sizeof(t_stacks));
	printf("ziped\n");//test
    while(ziped_num[i] >= 0)
    {
        printf("%d,", ziped_num[i]);
        i++;
    }//test
	i = 0;
	while (ziped_num[i] >= 0)
	{
		num[i].data = ziped_num[i];
		num[i].prev = NULL;
		num[i].next = NULL;
		add_list(&a_list, &num[i]);
		i++;
	}
	// tmp = a_list;
	// i = 0;
	// while (ziped_num[i] >= 0)
	// {
	// 	printf("prev;  %lu\n", tmp->data);
	// 	tmp = tmp->prev;
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (ziped_num[i] >= 0)
	// {
	// 	printf("next;  %lu\n", tmp->data);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	return ;
}
