/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:54:09 by donglee           #+#    #+#             */
/*   Updated: 2020/01/30 14:48:45 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int idx;

	idx = 0;
	if (min >= max)
		return (0);
	if ((arr = (int *)malloc(sizeof(int) * (max - min) + 1)) == '\0')
		return (0);
	while (min < max)
	{
		arr[idx] = min;
		min++;
		idx++;
	}
	return (arr);
}
