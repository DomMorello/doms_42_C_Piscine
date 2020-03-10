/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:09:58 by donglee           #+#    #+#             */
/*   Updated: 2020/02/12 23:30:38 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_data(t_data *data)
{
	int i;

	i = 0;
	while (i < data->height)
	{
		if (data->map[i] != NULL)
			free(data->map[i]);
		i++;
	}
	if (data->map != NULL)
		free(data->map);
}

void	free_data2(t_data *data)
{
	if (data->map != NULL)
		free(data->map);
	free(data->source);
}

void	free_int_arr(int **map, int h)
{
	int i;

	i = 0;
	while (i < h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_solution(t_solution sol, t_data ref, int ***map)
{
	int i;
	int j;

	i = 0;
	while (i < ref.height)
	{
		j = 0;
		while (j < ref.width)
		{
			if (j >= (sol.x - sol.size + 1) && j <= sol.x
				&& i >= (sol.y - sol.size + 1) && i <= sol.y)
				write(1, &ref.fill, 1);
			else
				write(1, &ref.map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free_int_arr(*map, ref.height);
}

void	solution(t_data ref)
{
	int			i;
	int			j;
	int			**map;
	t_solution	sol;

	i = -1;
	sol.size = 0;
	map = init_map(ref);
	while (++i < ref.height)
	{
		j = -1;
		while (++j < ref.width)
		{
			if (ref.map[i][j] == ref.obs)
				continue ;
			map[i][j] = get_min(map, i, j);
			if (sol.size < map[i][j])
			{
				sol.size = map[i][j];
				sol.x = j;
				sol.y = i;
			}
		}
	}
	print_solution(sol, ref, &map);
}
