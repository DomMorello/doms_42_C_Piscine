/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:32:10 by donglee           #+#    #+#             */
/*   Updated: 2020/01/28 14:38:15 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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
