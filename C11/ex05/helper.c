/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:06:27 by donglee           #+#    #+#             */
/*   Updated: 2020/02/07 08:27:32 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_atoi(char *str)
{
	int result;
	int sign;
	int idx;

	sign = 1;
	result = 0;
	idx = 0;
	while (str[idx] && (str[idx] == ' ' ||
		(str[idx] >= '\t' && str[idx] <= '\r')))
		idx++;
	while (str[idx] && (str[idx] == '+' || str[idx] == '-'))
	{
		if (str[idx] == '-')
			sign *= (-1);
		idx++;
	}
	while (str[idx] && (str[idx] >= '0' && str[idx] <= '9'))
	{
		result = (10 * result) + (str[idx] - '0') * sign;
		idx++;
	}
	return (result);
}

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

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
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
