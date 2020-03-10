/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:10:33 by donglee           #+#    #+#             */
/*   Updated: 2020/02/05 11:51:40 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_charcat(char *dest, char *src);
char	*copy_str(char *dest, char *src, int sign);
char	*save_num(long nbr, long l, char *base, char *empty);
int		ft_strlen(char *str);

int		get_base_idx(char *base, char find)
{
	int count;

	count = 0;
	while (base[count])
	{
		if (base[count] == find)
			return (count);
		count++;
	}
	return (-1);
}

int		check_base(char *str)
{
	int count;
	int index;
	int len;

	count = 0;
	len = ft_strlen(str);
	while (str[count])
	{
		if (str[count] == '+' || str[count] == '-' || str[count] == ' '
				|| (str[count] >= '\t' && str[count] <= '\r'))
			return (0);
		index = count;
		while (index < (len - 1))
		{
			if (str[count] == str[(index + 1)])
				return (0);
			index++;
		}
		count++;
	}
	if (count < 2)
		return (0);
	return (1);
}

int		ft_atoi(char *str, char *base, int len)
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
	while (str[idx] && (str[idx] == '-' || str[idx] == '+'))
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (get_base_idx(base, str[idx]) >= 0)
	{
		result = ((result * len) + (get_base_idx(base, str[idx]) * sign));
		idx++;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	char	result[1];
	long	from;
	char	*dest;

	sign = 1;
	result[0] = '\0';
	dest = NULL;
	if (!(check_base(base_from) && check_base(base_to)))
		return (NULL);
	from = (long)ft_atoi(nbr, base_from, ft_strlen(base_from));
	if (from < 0)
	{
		from *= -1;
		sign = -1;
	}
	save_num(from, ft_strlen(base_to), base_to, result);
	return (copy_str(dest, result, sign));
}
