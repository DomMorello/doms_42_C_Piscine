/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:19:48 by donglee           #+#    #+#             */
/*   Updated: 2020/01/25 18:53:44 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *arr, int n)
{
	int	idx;
	int	is_right;

	is_right = 1;
	idx = 0;
	while (++idx < n)
		if (arr[idx - 1] >= arr[idx])
			is_right = 0;
	if (!is_right)
		return ;
	idx = -1;
	while (++idx < n)
		ft_putchar(arr[idx] + '0');
	if (arr[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[10];

	i = -1;
	while (++i < n)
		arr[i] = i;
	while (arr[0] <= (10 - n))
	{
		print(arr, n);
		arr[n - 1]++;
		i = n;
		while (i > 1)
		{
			i--;
			if (arr[i] > 9)
			{
				arr[i - 1]++;
				arr[i] = 0;
			}
		}
	}
}
