#include "push_swap.h"

t_stacks *list_new(int	num)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if(!new)
		return (NULL);
	*new = (t_stacks){num, NULL, NULL};
	// new->data = num;
	// new->next = NULL;
	// new->prev = NULL;
	return (new);
}

// 作ったlistを後ろにくっつける。
void	lst_add_back(t_stacks *stacks, t_stacks *add)
{

	if (!stacks || !add)
		return ;
	stacks->next = add;
	add->prev = stacks;
}

 // 受け取ったリストの最後尾に移動する
 t_stacks *list_mv_back(t_stacks *stacks)
 {
	t_stacks *tmp;

	// while (stacks->next)
	// {
		tmp = stacks;
		stacks = stacks->next;
	// }
	return (stacks);
 }
 // 受け取ったリストの一番前に移動する
 t_stacks *list_mv_prev(t_stacks *stacks)
 {
	t_stacks *tmp;

	// while (stacks->prev)
	// {
		tmp = stacks;
		stacks = stacks->prev;
	// }
	return (stacks);
 }
 //end



// int	main()
// {
// 	int i = 100;
// 	int j = 200;
// 	int k = 300;
// 	t_stacks *tmp;
// 	t_stacks *new;
// 	t_stacks *new1;
// 	t_stacks *ans;
// 	tmp = list_new(i);
// 	new = list_new(j);
// 	new1 = list_new(k);
// 	lst_add_back(tmp, new);
// 	lst_add_back(new, new1);
// 	printf("tmp1; %ld\n", tmp->data);

// 	ans = list_mv_back(tmp);
// 	printf("ans1; %ld\n", ans->data);

// 	ans = list_mv_prev(ans);
// 	printf("ans2; %ld\n", ans->data);

// 	ans = list_mv_back(ans);
// 	printf("ans3; %ld\n", ans->data);
// 	return (0);
// }