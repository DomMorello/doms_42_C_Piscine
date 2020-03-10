/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:28:00 by donglee           #+#    #+#             */
/*   Updated: 2020/01/25 13:34:32 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	while (src[idx] != 0)
	{
		dest[idx] = src[idx];
		idx++;
		if (idx == n)
			break ;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		idx++;
	}
	return (dest);
}
