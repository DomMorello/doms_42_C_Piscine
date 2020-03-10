/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:16:01 by donglee           #+#    #+#             */
/*   Updated: 2020/01/27 08:44:02 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_idx;
	unsigned int	dest_len;
	int				dest_idx;
	int				src_len;

	src_len = 0;
	src_idx = 0;
	dest_idx = -1;
	dest_len = 0;
	while (dest[++dest_idx])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	else
	{
		while (src[src_idx++] && (src_idx <= size - dest_len - 1))
		{
			dest[dest_idx] = src[src_idx - 1];
			dest_idx++;
		}
		dest[dest_idx] = '\0';
		return (dest_len + src_len);
	}
}
