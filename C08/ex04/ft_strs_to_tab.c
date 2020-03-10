/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:07:02 by donglee           #+#    #+#             */
/*   Updated: 2020/02/05 08:44:37 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char					*ft_strcpy(char *dest, char *src)
{
	int idx;

	idx = 0;
	while (src[idx] != 0)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*result;
	int				i;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = (char *)malloc(sizeof(char) * (result[i].size + 1));
		result[i].copy = (char *)malloc(sizeof(char) * (result[i].size + 1));
		ft_strcpy(result[i].str, av[i]);
		ft_strcpy(result[i].copy, av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
