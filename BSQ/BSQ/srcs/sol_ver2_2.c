/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_ver2_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:17:21 by donglee           #+#    #+#             */
/*   Updated: 2020/02/13 09:08:12 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char	*ft_extend_arr(char *orig, char *n_cont, int old_len, int len)
{
	char *dest;

	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (orig != NULL)
		ft_strncpy(dest, orig, old_len);
	ft_strncpy(dest + old_len, n_cont, len - old_len);
	if (orig != NULL)
		free(orig);
	return (dest);
}

int		read_full(int fd, char **content, int *total)
{
	char	buffer[300000];
	int		byte_read;

	if (read(fd, 0, 0) == -1)
		return (0);
	*total = 0;
	*content = NULL;
	while ((byte_read = read(fd, buffer, 300000)) > 0)
	{
		if (!(*content = ft_extend_arr(*content,
				buffer, *total, *total + byte_read)))
			return (0);
		(*total) += byte_read;
	}
	if (byte_read == 0)
		return (1);
	return (0);
}
