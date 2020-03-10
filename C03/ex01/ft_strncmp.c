/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 08:33:04 by donglee           #+#    #+#             */
/*   Updated: 2020/01/26 22:46:10 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	while ((s1[idx] || s2[idx]) && idx < n)
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}
