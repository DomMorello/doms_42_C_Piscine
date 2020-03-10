/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:01:09 by donglee           #+#    #+#             */
/*   Updated: 2020/02/12 23:32:31 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	counts the the number of lines of the file
**	,allocate the memory and puts it to the struct's height
*/

int		alloc_data(char *input, int fd, t_data *data)
{
	char	buf;
	int		len;
	int		cnt;

	cnt = 0;
	len = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf != data->empty && buf != data->obs && buf != '\n')
			return (print_map_error());
		if (buf == '\n')
		{
			len++;
			data->width = cnt;
			cnt = 0;
		}
		else
			cnt++;
	}
	if ((data->map = (char **)malloc(sizeof(char *) * len + 1)) == 0)
		return (0);
	if (data->height != len)
		return (print_map_error());
	alloc_map(input, data);
	return (1);
}

/*
**	gets the first line(header) of the file
**	and puts the information in it in the struct
*/

int		get_header(char *input, t_data *data)
{
	int		fd;
	char	*header;
	int		len;

	if ((fd = open(input, O_RDONLY)) == -1)
		return (0);
	if ((header = save_header(fd)) == NULL)
		return (0);
	len = ft_strlen(header);
	data->empty = header[len - 3];
	data->obs = header[len - 2];
	data->fill = header[len - 1];
	header[len - 3] = 0;
	if ((data->height = ft_atoi(header)) == 0)
		return (print_map_error());
	free(header);
	if (alloc_data(input, fd, data) == 0)
		return (0);
	close(fd);
	return (1);
}

/*
**	reads the file and puts them in the map array
*/

int		put_map(char *input, t_data *data)
{
	int		fd;
	char	buf;
	int		flag;
	int		i;
	int		j;

	flag = 0;
	i = 0;
	j = 0;
	if ((fd = open(input, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n' && flag == 0)
			flag = 1;
		else if (flag == 1 && buf != '\n')
			data->map[i][j++] = buf;
		else if (flag == 1 && buf == '\n')
		{
			data->map[i++][j] = 0;
			j = 0;
		}
	}
	close(fd);
	return (1);
}

/*
**	counts the length of each rows
**	and checks if it is same with
**	the height of the t_data data
*/

int		check_width(t_data *data)
{
	int len;
	int i;

	i = 0;
	while (i < data->height)
	{
		len = ft_strlen(data->map[i]);
		if (data->width != len)
			return (print_map_error());
		i++;
	}
	return (1);
}

/*
**	opens the file and parse it according as the given condition
*/

int		data_open(char *input, t_data *data)
{
	if (get_header(input, data) == 0)
		return (0);
	if (put_map(input, data) == 0)
		return (0);
	if (check_width(data) == 0)
		return (0);
	return (1);
}
