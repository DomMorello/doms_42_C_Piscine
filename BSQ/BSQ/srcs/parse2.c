/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:04:33 by donglee           #+#    #+#             */
/*   Updated: 2020/02/13 02:24:12 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	checks if the header has duplicated letters in it
*/

int		check_header_dup(char *str)
{
	if ((str[0] == str[1]) || (str[0] == str[2]) || str[1] == str[2])
		return (1);
	return (0);
}

/*
**	checks the temp header is valid
*/

int		check_header(char *header)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(header);
	while (header[i])
	{
		if (len < 3)
			return (print_map_error());
		if (check_header_num(header))
			return (print_map_error());
		if (check_header_dup(&(header[len - 3])))
			return (print_map_error());
		while (j < 3)
		{
			if (!(header[len - 3 + j] >= 32 && header[len - 3 + j] < 127))
				return (print_map_error());
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	reads the first line (header) of the file and
**	checks if it is valid then allocates 13 byte
**	(max digits of the integer data type 10 + three characters = 13 bytes)
**	and returns the header
*/

char	*save_header(int fd)
{
	char	buf;
	char	*tmp;
	int		i;

	tmp = NULL;
	if ((tmp = (char *)malloc(sizeof(char) * 13)) == 0)
		return (NULL);
	i = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			break ;
		tmp[i] = buf;
		i++;
	}
	tmp[i] = 0;
	if (check_header(tmp) == 0)
		return (NULL);
	return (tmp);
}

/*
**	reads the file(except for the header part) and
**	allocates the memory of the map array
*/

int		read_alloc_map(int fd, t_data *data)
{
	char	buf;
	int		cnt;
	int		flag;
	int		i;

	cnt = 0;
	flag = 0;
	i = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n' && flag == 0)
			flag = 1;
		else if (flag == 1 && buf != '\n')
			cnt++;
		else if (buf == '\n' && flag == 1)
		{
			if ((data->map[i++] =
				(char *)malloc(sizeof(char) * cnt + 1)) == 0)
				return (0);
			cnt = 0;
		}
	}
	return (1);
}

/*
**	allocates the memory of the map array
*/

int		alloc_map(char *input, t_data *data)
{
	int fd;

	if ((fd = open(input, O_RDONLY)) == -1)
		return (0);
	if (read_alloc_map(fd, data) == 0)
		return (0);
	close(fd);
	return (1);
}
