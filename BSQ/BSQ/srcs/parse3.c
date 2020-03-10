/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:08:04 by donglee           #+#    #+#             */
/*   Updated: 2020/02/12 22:38:15 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	counts the length of the string
*/

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

/*
**	converts string(number) to integer
*/

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

/*
**	prints the map erroe message and returns zero
*/

int		print_map_error(void)
{
	write(1, "map error\n", 10);
	return (0);
}

/*
**	checks the header number part is consist of
**	only integers
*/

int		check_header_num(char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	while (i < len - 3)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
