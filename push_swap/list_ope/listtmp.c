#include "push_swap.h"

t_stacks *listnew(int	num)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if(!new)
		return (NULL);
	*new = (t_stacks){num, NULL, NULL};
	// new->next = NULL;
	// new->prev = NULL;
	// new->data = num;
	return (new);
}

// lstaddback
 // １、受け取ったリストの最後尾に移動する
 // ２、そのポインターのnxtに引数のポインターをつける
 // 3, prev もいじる
 //end



int	main()
{
	int i = 100;
	t_stacks *tmp;
	tmp = listnew(i);
	printf("%ld", tmp->data);
}