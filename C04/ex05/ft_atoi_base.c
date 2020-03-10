/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:18:30 by donglee           #+#    #+#             */
/*   Updated: 2020/01/28 16:17:10 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char ch, char *base, int *test)
{
	int idx;

	idx = 0;
	while (base[idx])
	{
		if (ch == base[idx])
		{
			*test = idx;
			return (1);
		}
		idx++;
	}
	return (0);
}

int	ft_atoi(char *str, char *base, int *base_len)
{
	int result;
	int sign;
	int idx;
	int test;

	sign = 1;
	idx = 0;
	result = 0;
	while (str[idx] && (str[idx] == ' ' ||
		(str[idx] >= '\t' && str[idx] <= '\r')))
		idx++;
	while (str[idx] && (str[idx] == '+' || str[idx] == '-'))
	{
		if (str[idx] == '-')
			sign *= (-1);
		idx++;
	}
	while (check_base(str[idx], base, &test))
	{
		result = (result * (*base_len)) + test * sign;
		idx++;
	}
	return (result);
}

int	handle_exception(char *base, int *base_len)
{
	int i;
	int j;

	while (base[*base_len])
	{
		if (base[*base_len] == '+' || base[*base_len] == '-' || base[*base_len]
		== ' ' || (base[*base_len] >= '\t' && base[*base_len] <= '\r'))
			return (0);
		(*base_len)++;
	}
	if (*base_len < 2)
		return (0);
	i = -1;
	while (++i < *base_len)
	{
		j = i;
		while (++j < *base_len)
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int base_len;

	base_len = 0;
	if (handle_exception(base, &base_len))
		return (ft_atoi(str, base, &base_len));
	return (0);
}
