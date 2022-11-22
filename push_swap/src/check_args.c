/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:42:51 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/22 13:22:18 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_digit(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j])
		{
			if (nums[i][j] == '-' || nums[i][j] == '+')
				j++;
			if (!ft_isdigit(nums[i][j]))
			{
				write(2, "Error; include character", 24);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

static int	*split_args(char *argv)
{
	int		len;
	char	**nums;
	int		*num;

	len = 0;
	nums = ft_split(argv, ' ');
	check_digit(nums);
	while (nums[len])
		len++;
	num = malloc(sizeof(int) * (len + 1));
	if (!num)
		exit (0);
	len = 0;
	while (nums[len])
	{
		num[len] = push_swap_atoi(nums[len]);
		len++;
	}
	num[len] = -1;
	return (num);
}


int	*check_args(int argc, char **argv)
{
	int	*num;
	int	num_len;

	if (argc == 1)
		exit (1);
	else if (argc == 2)
		return (split_args(argv[1]));
	check_digit(&argv[1]);
	num = malloc(sizeof(int) * (argc - 1));
	if (!num)
		exit (0);
	num_len = 0;
	while (argv[num_len + 1])
	{
		num[num_len] = push_swap_atoi(argv[num_len + 1]);
		num_len++;
	}
	num[num_len] = -1;
	return (num);
}