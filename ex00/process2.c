/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:13:10 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:21:50 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	open the dict(file) returns 0 when it fails
*/

#include "ft_header.h"

int		open_file(char *dict)
{
	if ((g_open_file = open(dict, O_RDONLY)) == -1)
		return (0);
	return (1);
}

/*
**	count the row line of the file
*/

int		get_row_len(char *dict)
{
	char	buf;
	int		check;
	int		flag;
	int		line_num;

	flag = 0;
	line_num = 0;
	if (open_file(dict) == 0)
		return (0);
	check = 0;
	while ((check = read(g_open_file, &buf, 1)) > 0)
	{
		if (flag == 0 && buf == ':')
			flag = 1;
		if (flag == 1 && buf == '\n')
		{
			line_num++;
			flag = 0;
		}
	}
	close(g_open_file);
	return (line_num);
}

/*
**	count the number of characters in the file
*/

int		get_len(char *dict)
{
	char	buf;
	int		check;
	int		len;

	len = 0;
	g_data.line_size = get_row_len(dict);
	if (open_file(dict) == 0)
		return (0);
	check = 0;
	while ((check = read(g_open_file, &buf, 1)) > 0)
		len++;
	close(g_open_file);
	return (len);
}

/*
**	get rid of the space followed by the value(string)
*/

void	refactor_value(char *dict)
{
	int i;
	int j;
	int len;

	i = -1;
	while (++i < get_row_len(dict))
	{
		len = ft_strlen(g_data.value[i]);
		j = len - 1;
		while (j >= 1)
		{
			if (g_data.value[i][len - 1] != ' ' && !(9 <= g_data.value[i][j - 1]
				&& g_data.value[i][j - 1] <= 13))
				break ;
			if ((g_data.value[i][j] == ' ' || (9 <= g_data.value[i][j]
			&& g_data.value[i][j] <= 13))
			&& g_data.value[i][j - 1] != ' '
			&& !(9 <= g_data.value[i][j - 1] && g_data.value[i][j - 1] <= 13))
			{
				g_data.value[i][j] = '\0';
				break ;
			}
			j--;
		}
	}
}

/*
**	allocate the string from the file and put them in the char array(key[][])
*/

int		put_key(char *dict)
{
	int i;
	int j;

	if ((g_data.key = (char **)malloc(sizeof(char *) * get_row_len(dict))) == 0)
		return (0);
	i = 0;
	while (g_data.key_value[i])
	{
		j = 0;
		while (g_data.key_value[i][j] != ':')
			j++;
		if ((g_data.key[i] = (char *)malloc(sizeof(char) * j + 1)) == 0)
			return (0);
		j = 0;
		while (g_data.key_value[i][j] >= '0' && g_data.key_value[i][j] <= '9')
		{
			g_data.key[i][j] = g_data.key_value[i][j];
			j++;
		}
		g_data.key[i][j] = '\0';
		i++;
	}
	return (1);
}
