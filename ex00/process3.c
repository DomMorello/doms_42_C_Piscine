/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:27:54 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:30:08 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

/*
**	allocate the string from the file and put them in the char array(value[][])
*/

int		put_value(char *dict)
{
	int i;
	int j;
	int cnt;

	if ((g_data.value = (char **)malloc(sizeof(char *)
	* get_row_len(dict))) == 0)
		return (0);
	i = -1;
	while (g_data.key_value[++i])
	{
		j = 0;
		cnt = 0;
		while (g_data.key_value[i][j++] != ':')
			;
		while (g_data.key_value[i][j + (cnt++)] != '\0')
			;
		if ((g_data.value[i] = (char *)malloc(sizeof(char) * cnt + 1)) == 0)
			return (0);
		cnt = 0;
		while (!(g_data.key_value[i][j + cnt] < 32 || 
			g_data.key_value[i][j + cnt] >= 127))
			{
				g_data.value[i][cnt] = g_data.key_value[i][j + cnt];
				cnt++;
			}
		g_data.value[i][cnt] = '\0';
	}
	return (1);
}

/*
**	check all elements of the key array is valid or not
*/

int		check_key(char *dict)
{
	int i;
	int j;

	i = 0;
	while (g_data.key_value[i])
	{
		if ((i != 0) && (!(g_data.key_value[i][0] >= '1'
			&& g_data.key_value[i][0] <= '9')
		|| (g_data.key_value[i][0] == ':')))
			return (0);
		j = 0;
		while (g_data.key_value[i][j] >= '0' &&
			g_data.key_value[i][j] <= '9')
			j++;
		while (is_space(g_data.key_value[i][j]))
			j++;
		if (g_data.key_value[i][j] != ':')
			return (0);
		i++;
	}
	put_key(dict);
	return (1);
}

/*
**	check all elements of the value array is valid or not
*/

int		check_value(char *dict)
{
	int i;
	int j;

	i = -1;
	while (g_data.key_value[++i])
	{
		j = 0;
		while (g_data.key_value[i][j] != ':')
			j++;
		j++;
		if (g_data.key_value[i][j] < 32 || g_data.key_value[i][j] >= 127)
			return (0);
		while (is_space(g_data.key_value[i][j]))
			j++;
		if (g_data.key_value[i][j] < 32 || g_data.key_value[i][j] >= 127)
			return (0);
		while (!(g_data.key_value[i][j] < 32 ||
				g_data.key_value[i][j] >= 127))
			j++;
		if (g_data.key_value[i][j] != '\0')
			return (0);
	}
	put_value(dict);
	refactor_value(dict);
	return (1);
}

/*
**	the beginning function which opens files and reads
*/

int		solve(char *dict)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((g_data.size = get_len(dict)) == 0)
		return (0);
	if ((tmp = (char *)malloc(sizeof(char) * g_data.size)) == 0)
		return (0);
	tmp[g_data.size] = '\0';
	if (open_file(dict) == 0)
		return (0);
	read(g_open_file, tmp, g_data.size);
	if ((g_data.key_value = ft_split(tmp, "\n")) == 0)
		return (0);
	close(g_open_file);
	if ((check_key(dict) == 0 || check_value(dict)) == 0)
		return (0);
	free(tmp);
	return (1);
}

/*
**	free all the global variables
*/

void	free_global(char *dict)
{
	int i;

	i = 0;
	g_data.line_size = get_row_len(dict);
	while (i < g_data.line_size)
	{
		if (g_data.key[i] != 0)
			free(g_data.key[i]);
		if (g_data.value[i] != 0)
			free(g_data.value[i]);
		if (g_data.key_value[i] != 0)
			free(g_data.key_value[i]);
		i++;
	}
	if (g_data.key != 0)
		free(g_data.key);
	if (g_data.value != 0)
		free(g_data.value);
	if (g_data.key_value != 0)
		free(g_data.key_value);
}
