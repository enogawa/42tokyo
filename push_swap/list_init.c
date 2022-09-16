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
	int zipped_num;

	//a_list = malloc(sizeof(t_stacks));
	i = 0;
	printf("%ld\n", i);
	while (ziped_num[i] != -1)
	{
		num = malloc(sizeof(t_stacks));
		printf("%ld\n", i);
		num->data = ziped_num[i];
		num->prev = NULL;
		num->next = NULL;
		add_list(&a_list, &num[i]);
		i++;
	}

/* 
	printf("ziped\n");//test
	tmp = a_list;
	i = 0;
	while (ziped_num[i] >= 0)
	{
		printf("prev;  %lu\n", tmp->data);
		tmp = tmp->prev;
		i++;
	}
	printf("\n");
	i = 0;
	while (ziped_num[i] >= 0)
	{
		printf("next;  %lu\n", tmp->data);
		tmp = tmp->next;
		i++;
	}
//  */
	return ;
}
