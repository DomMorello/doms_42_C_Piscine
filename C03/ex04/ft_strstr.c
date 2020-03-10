/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:34:56 by donglee           #+#    #+#             */
/*   Updated: 2020/01/26 19:14:14 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int idx;
	int needle_size;
	int found_cnt;
	int check;

	idx = -1;
	needle_size = 0;
	found_cnt = 0;
	while (to_find[needle_size])
		needle_size++;
	if (needle_size == 0)
		return (str);
	while (str[++idx])
	{
		found_cnt = 0;
		check = idx;
		while (str[check] == to_find[found_cnt])
		{
			if (found_cnt == needle_size - 1)
				return (&(str[idx]));
			found_cnt++;
			check++;
		}
	}
	return (0);
}
