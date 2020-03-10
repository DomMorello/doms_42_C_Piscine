/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:22:18 by donglee           #+#    #+#             */
/*   Updated: 2020/02/07 13:54:27 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int dest_idx;
	int src_idx;

	dest_idx = 0;
	src_idx = 0;
	while (dest[dest_idx])
		dest_idx++;
	while (src[src_idx])
	{
		dest[dest_idx] = src[src_idx];
		src_idx++;
		dest_idx++;
	}
	dest[dest_idx] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int		get_whole_len(char **strs, char *sep, int size)
{
	int count;
	int total;

	count = 0;
	total = 0;
	while (count < size)
	{
		total += ft_strlen(strs[count]);
		count++;
	}
	total = total + (size - 1) * ft_strlen(sep) + 1;
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		*result = 0;
		return (result);
	}
	i = 0;
	if (!(result = malloc(sizeof(char) * get_whole_len(strs, sep, size))))
		return (0);
	*result = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
