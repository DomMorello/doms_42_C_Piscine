/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:02:17 by donglee           #+#    #+#             */
/*   Updated: 2020/01/26 11:06:05 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_hexadecimal(int decimal)
{
	unsigned char	hexa[2];
	int				idx;
	int				mod;

	idx = 0;
	if (decimal < 16)
		hexa[1] = '0';
	while (decimal != 0)
	{
		mod = decimal % 16;
		if (mod < 10)
			hexa[idx] = '0' + mod;
		else
			hexa[idx] = 'a' + (mod - 10);
		decimal = decimal / 16;
		idx++;
	}
	write(1, "\\", 1);
	write(1, &hexa[1], 1);
	write(1, &hexa[0], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*print;
	int				idx;

	print = (unsigned char *)str;
	idx = 0;
	while (print[idx])
	{
		if (print[idx] < 32 || print[idx] >= 127)
			get_hexadecimal(print[idx]);
		else
			write(1, &print[idx], 1);
		idx++;
	}
}
