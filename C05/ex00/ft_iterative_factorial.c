/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:49:03 by donglee           #+#    #+#             */
/*   Updated: 2020/01/28 17:25:19 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;
	int i;
	int j;

	if (nb < 0)
		return (0);
	result = 1;
	j = 0;
	i = 0;
	while (i < nb)
	{
		result *= nb - j;
		i++;
		j++;
	}
	return (result);
}
