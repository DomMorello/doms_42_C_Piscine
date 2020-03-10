/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:15:38 by donglee           #+#    #+#             */
/*   Updated: 2020/01/22 17:17:17 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char first;
	char second;
	char third;

	first = '0' - 1;
	while (++first <= '7')
	{
		second = first;
		while (++second <= '8')
		{
			third = second;
			while (++third <= '9')
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if (first != '7' || second != '8' || third != '9')
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}
