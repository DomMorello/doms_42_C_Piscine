/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 09:05:44 by donglee           #+#    #+#             */
/*   Updated: 2020/01/26 12:53:46 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
