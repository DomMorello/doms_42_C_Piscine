/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:45:46 by donglee           #+#    #+#             */
/*   Updated: 2020/01/24 14:59:50 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
			str[idx] = str[idx] - 32;
		idx++;
	}
	return (str);
}
