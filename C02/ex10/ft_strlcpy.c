/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:35:08 by donglee           #+#    #+#             */
/*   Updated: 2020/01/25 21:55:39 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int idx;
	unsigned int cnt;

	idx = 0;
	cnt = 0;
	while (src[cnt])
		cnt++;
	if (!size)
		return (cnt);
	while (src[idx] && idx < size - 1)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (cnt);
}
