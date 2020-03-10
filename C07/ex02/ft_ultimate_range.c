/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:39:51 by donglee           #+#    #+#             */
/*   Updated: 2020/02/05 20:10:46 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int idx;
	int *arr;

	idx = 0;
	if (min >= max)
		return (0);
	if ((arr = (int *)malloc(sizeof(int) * (max - min) + 1)) == '\0')
		return (-1);
	while (min < max)
	{
		arr[idx] = min;
		min++;
		idx++;
	}
	*range = arr;
	return (idx);
}
