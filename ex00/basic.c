/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:04:33 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:03:33 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

/*
** print the string
*/

void	ft_putstr(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt])
	{
		write(1, &str[cnt], 1);
		cnt++;
	}
}

/*
** get the length of str(string)
*/

int		ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

/*
** compare the strings
*/

int		ft_strcmp(char *s1, char *s2)
{
	int idx;

	idx = 0;
	while (s1[idx] || s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}

/*
** add src(string) to the end of the dest(string)
*/

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

/*
** get length of string which is not included in charset
*/

int		get_strlen(char *str, char *charset)
{
	int len;

	len = 0;
	while (str[len] && !included(*str, charset))
		len++;
	return (len);
}
