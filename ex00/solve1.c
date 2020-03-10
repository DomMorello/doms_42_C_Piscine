/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:35:23 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:00:04 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	print an element of value array
*/

#include "ft_header.h"

void	print_digit(char *value)
{
	int i;

	i = 0;
	while (value[i])
	{
		write(1, &value[i], 1);
		i++;
	}
	write(1, " ", 1);
}

/*
**	 make digits divied by three digits
*/

char	*get_digit_key(int *length, int *idx)
{
	int		digit_count;
	char	*zero;
	char	*result;

	zero = "0";
	digit_count = *length - *idx;
	result = (char *)malloc(sizeof(char) * (digit_count + 2));
	result[0] = '1';
	while (0 < digit_count)
	{
		ft_strcat(result, zero);
		digit_count--;
	}
	return (result);
}

/*
**	make a chunk with 3 digits
*/

char	*get_three_digit(char *input, int *idx, int *len)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(sizeof(char) * 4);
	if ((*len) > (*idx))
	{
		while (i < 3)
		{
			result[i] = input[*idx];
			i++;
			(*idx)++;
		}
	}
	return (result);
}

/*
**	get an element of the value array
*/

char	*get_value(char *key)
{
	int		i;
	char	*result;

	i = 0;
	while (i < g_data.line_size)
	{
		if (!(ft_strcmp(key, g_data.key[i])))
			result = g_data.value[i];
		i++;
	}
	return (result);
}

/*
**	check if the two numbers are readable at once
*/

int		is_readable(char c1, char c2)
{
	int tmp;

	tmp = (c1 - '0') * 10 + (c2 - '0');
	if ((tmp > 0 && tmp < 20) || (tmp % 10 == 0))
		return (1);
	return (0);
}
