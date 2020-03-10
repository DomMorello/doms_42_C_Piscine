/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:00:45 by donglee           #+#    #+#             */
/*   Updated: 2020/01/24 15:03:14 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] = str[idx] + 32;
		idx++;
	}
	return (str);
}
