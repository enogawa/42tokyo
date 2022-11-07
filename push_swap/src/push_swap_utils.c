#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	push_swap_atoi(const char *str)
{
	long int		ans;
	size_t			i;
	int				m;

	ans = 0;
	i = 0;
	m = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		   	 || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - 48;
		i++;
	}
	return (ans * m);
}

char	*ft_strdup(const char	*str)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	while (str[i] != '\0')
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

int		already_sorted(t_stacks	*stack_a)
{
	t_stacks *tmp;

	tmp = stack_a;
	if (tmp->next->data == -1)
		return (1);
	while (tmp->next->data != -1)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}