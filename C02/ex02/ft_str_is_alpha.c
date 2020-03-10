/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:52:18 by donglee           #+#    #+#             */
/*   Updated: 2020/01/26 10:46:49 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int cnt;

	cnt = 0;
	if (str[cnt] == '\0')
		return (1);
	while (str[cnt] != '\0')
	{
		if (!
		((str[cnt] >= 'a' && str[cnt] <= 'z')
			|| (str[cnt] >= 'A' && str[cnt] <= 'Z')))
			return (0);
		cnt++;
	}
	return (1);
}
