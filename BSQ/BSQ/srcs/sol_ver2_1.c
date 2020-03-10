/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_ver2_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:14:40 by donglee           #+#    #+#             */
/*   Updated: 2020/02/13 09:27:43 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		check_width2(t_data *data, unsigned int *curr_w)
{
	if (*curr_w == (unsigned int)-1)
		*curr_w = data->width;
	return (*curr_w != (unsigned int)data->width);
}

int		parse_normal_line(t_data *data, char *line, int length)
{
	int		index;
	char	current;

	if (length < 1)
		return (0);
	data->width = length;
	index = 0;
	while (index < length)
	{
		current = line[index];
		if ((current != data->empty
				&& current != data->obs
				&& current != '\n') || !(current >= 32 && current < 127))
			return (0);
		index++;
	}
	return (1);
}

int		process_lines(t_data *data, int index,
							char *content, int total)
{
	int				jndex;
	int				y;
	unsigned int	curr_w;

	y = 0;
	curr_w = -1;
	while (index < total && y < data->height)
	{
		jndex = index;
		while (content[jndex] != '\n')
			if (jndex++ + 1 >= total)
				return (0);
		if (parse_normal_line(data, content + index, jndex - index))
		{
			data->map[y++] = (char *)(content + index);
			if (check_width2(data, &curr_w))
				return (0);
		}
		else
			return (0);
		index = jndex + 1;
	}
	return (y == data->height);
}

int		parse_header_line(t_data *data, char *line, int length)
{
	int result;
	int i;

	if (length < 4)
		return (0);
	data->fill = line[length - 1];
	data->obs = line[length - 2];
	data->empty = line[length - 3];
	if (check_header_dup(line + length - 3))
		return (0);
	i = 0;
	while (i < 3)
	{
		if (!(line[length - 3 + i] >= 32 && line[length - 3 + i] < 127))
			return (0);
		i++;
	}
	line[length - 3] = 0;
	data->height = ft_atoi(line);
	result = data->height;
	if (result == 0)
		return (0);
	return (result);
}

int		parse_data(int fd, t_data *data)
{
	char	*dump;
	int		total;
	int		idx;

	data->map = 0;
	if (!read_full(fd, &dump, &total))
		return (0);
	data->source = dump;
	idx = 0;
	while (idx < total)
	{
		if (dump[idx] == '\n')
		{
			if (!parse_header_line(data, dump, idx))
				return (0);
			if (!(data->map = (char **)malloc(sizeof(char *) * data->height)))
				return (0);
			return (process_lines(data, idx + 1, dump, total));
		}
		idx++;
	}
	return (0);
}
