/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:20:49 by donglee           #+#    #+#             */
/*   Updated: 2020/02/05 11:52:01 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_charcat(char *dest, char *src)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (dest[l])
		l++;
	dest[l] = src[0];
	dest[l + 1] = '\0';
	return (dest);
}

char	*copy_str(char *dest, char *src, int sign)
{
	int len;
	int i;
	int index;

	i = 0;
	index = 0;
	len = ft_strlen(src);
	if (sign < 0)
	{
		dest = (char *)malloc(sizeof(char) * (len + 2));
		dest[index++] = '-';
	}
	else
		dest = (char *)malloc(sizeof(char) * (len + 1));
	while (*src)
		dest[index++] = *(src++);
	dest[index] = '\0';
	return (dest);
}

char	*save_num(long nbr, long l, char *base, char *empty)
{
	if (nbr >= l)
		return (ft_charcat(save_num(nbr / l, l, base, empty),
					&base[(nbr % l)]));
	else
		return (ft_charcat(empty, &base[(nbr % l)]));
}
