/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:12:16 by donglee           #+#    #+#             */
/*   Updated: 2020/02/12 22:38:30 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		get_min(int **map, int i, int j)
{
	int a;
	int b;
	int c;

	if (i == 0 || j == 0)
		return (map[i][j]);
	a = map[i - 1][j];
	b = map[i][j - 1];
	c = map[i - 1][j - 1];
	a = (a > b) ? b : a;
	return (((a > c) ? c : a) + 1);
}

int		**init_map(t_data ref)
{
	int i;
	int j;
	int **map;

	i = 0;
	map = (int **)malloc(sizeof(int *) * ref.height);
	while (i < ref.height)
	{
		map[i] = (int *)malloc(sizeof(int) * ref.width);
		j = 0;
		while (j < ref.width)
		{
			if (i == 0 || j == 0)
				map[i][j] = (ref.map[i][j] == ref.empty ? 1 : 0);
			else
				map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
