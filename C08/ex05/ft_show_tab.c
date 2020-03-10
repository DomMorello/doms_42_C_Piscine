/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:46:47 by donglee           #+#    #+#             */
/*   Updated: 2020/02/05 10:06:40 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	get_digits(long num, long *result)
{
	long	len;
	int		count;

	len = 0;
	count = 0;
	if (num == 0)
	{
		*result = 1;
		return ;
	}
	else if (num > 0)
		len = num;
	else
		len = num * (-1);
	while (len > 0)
	{
		len = len / 10;
		count++;
	}
	*result = count;
}

void	get_pow(int exponent, long *result)
{
	if (exponent <= 0)
		*result *= 1;
	else
	{
		*result = 10 * (*result);
		get_pow(--exponent, result);
	}
}

void	ft_putnbr(int nb)
{
	long	pow1;
	long	pow2;
	char	print;
	long	len;

	get_digits(nb, &len);
	while (len-- != 0)
	{
		pow1 = 1;
		pow2 = 1;
		get_pow(len + 1, &pow1);
		get_pow(len, &pow2);
		print = ((nb % pow1) / pow2) + '0';
		write(1, &print, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i++;
	}
}
