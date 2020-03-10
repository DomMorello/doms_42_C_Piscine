/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:32:57 by donglee           #+#    #+#             */
/*   Updated: 2020/01/30 14:19:56 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		idx;

	idx = 0;
	while (src[idx])
		idx++;
	if ((copy = (char *)malloc(sizeof(char) * (idx + 1))) == '\0')
		return (0);
	idx = 0;
	while (src[idx])
	{
		copy[idx] = src[idx];
		idx++;
	}
	copy[idx] = '\0';
	return (copy);
}
