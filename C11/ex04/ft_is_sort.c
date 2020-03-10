/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:50:55 by donglee           #+#    #+#             */
/*   Updated: 2020/02/06 19:45:17 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
		{
			if (flag == -1)
				return (0);
			flag = 1;
		}
		if (f(tab[i - 1], tab[i]) > 0)
		{
			if (flag == 1)
				return (0);
			flag = -1;
		}
		i++;
	}
	return (1);
}
