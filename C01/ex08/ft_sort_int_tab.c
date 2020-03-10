/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:31:47 by donglee           #+#    #+#             */
/*   Updated: 2020/01/24 09:03:50 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int idx;
	int tmp;
	int cnt;

	idx = 0;
	cnt = 0;
	while (cnt < size)
	{
		idx = 0;
		while (idx < size - cnt - 1)
		{
			if (tab[idx] > tab[idx + 1])
			{
				tmp = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = tmp;
			}
			idx++;
		}
		cnt++;
	}
}
