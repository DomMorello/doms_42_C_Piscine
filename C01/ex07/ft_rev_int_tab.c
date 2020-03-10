/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:55:04 by donglee           #+#    #+#             */
/*   Updated: 2020/01/24 08:51:58 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int idx;
	int tmp;

	idx = 0;
	while (idx < size / 2)
	{
		tmp = tab[idx];
		tab[idx] = tab[(size - 1) - idx];
		tab[(size - 1) - idx] = tmp;
		idx++;
	}
}
