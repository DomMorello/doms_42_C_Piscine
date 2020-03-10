/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:54:31 by donglee           #+#    #+#             */
/*   Updated: 2020/01/27 13:24:50 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	src_idx;
	int				dest_idx;

	dest_idx = 0;
	src_idx = 0;
	while (dest[dest_idx])
		dest_idx++;
	while (src[src_idx] && src_idx < nb)
	{
		dest[dest_idx] = src[src_idx];
		src_idx++;
		dest_idx++;
	}
	dest[dest_idx] = '\0';
	return (dest);
}
