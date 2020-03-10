/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:10:49 by donglee           #+#    #+#             */
/*   Updated: 2020/01/24 14:43:45 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int cnt;

	cnt = 0;
	if (str[cnt] == '\0')
		return (1);
	while (str[cnt] != '\0')
	{
		if (!(str[cnt] >= 32 && str[cnt] <= 126))
			return (0);
		cnt++;
	}
	return (1);
}
