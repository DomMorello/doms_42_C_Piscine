/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:50:17 by donglee           #+#    #+#             */
/*   Updated: 2020/01/23 19:29:04 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	two_digit_print(int num)
{
	char first;
	char second;

	if (num < 10)
	{
		first = '0';
		second = num + '0';
		write(1, &first, 1);
		write(1, &second, 1);
	}
	else
	{
		first = (num / 10) + '0';
		second = (num % 10) + '0';
		write(1, &first, 1);
		write(1, &second, 1);
	}
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = -1;
	while (first++ <= 98)
	{
		second = first;
		while (second++ < 99)
		{
			two_digit_print(first);
			write(1, " ", 1);
			two_digit_print(second);
			if (first != 98 || second != 99)
			{
				write(1, ", ", 2);
			}
		}
	}
}
