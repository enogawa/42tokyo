/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:42:51 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/26 15:49:29 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_nums(char **nums, int flag)
{
	int	i;

	i = 0;
	if (nums)
	{
		while (nums[i])
		{
			free(nums[i]);
			i++;
		}
		free(nums);
	}
	if (flag == 1)
		exit(1);
}

static void	check_digit(char **nums, int c)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
			{
				write(2, "Error; include character\n", 25);
				if (c == 1)
					free_nums(nums, 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	return_len(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

static int	*split_args(char *argv)
{
	char	**nums;
	int		*num;
	int		len;
	int		i;

	nums = ft_split(argv, ' ');
	if (!nums)
		exit(1);
	check_digit(nums, 1);
	len = return_len(nums);
	if (len <= 0)
		free_nums(nums, 1);
	num = malloc(sizeof(int) * (len + 1));
	if (!num)
		free_nums(nums, 1);
	i = 1;
	while (i < len + 1)
	{
		num[i] = push_swap_atoi(nums[i - 1], num, nums);
		i++;
	}
	// if (!num)
	// {
	// 	free(num);
	// 	exit(1);
	// }
	num[0] = len;
	free_nums(nums, 0);
	return (num);
}

int	*check_args(int argc, char **argv)
{
	int	*num;
	int	num_len;

	if (argc == 1)
		exit(1);
	else if (argc == 2)
		return (split_args(argv[1]));
	check_digit(&argv[1], 0);
	num = malloc(sizeof(int) * (argc));
	if (!num)
		exit(0);
	num_len = 1;
	while (num_len < argc)
	{
		num[num_len] = push_swap_atoi(argv[num_len], num, NULL);
		num_len++;
	}
	num[0] = num_len - 1;
	return (num);
}
