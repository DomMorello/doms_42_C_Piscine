/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:56:30 by donglee           #+#    #+#             */
/*   Updated: 2020/01/29 16:35:00 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int start;
	int mid;
	int end;

	start = 0;
	end = 46341;
	mid = (end + start) / 2;
	while (end - start >= 0)
	{
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
			start = mid + 1;
		else
			end = mid - 1;
		mid = (end + start) / 2;
	}
	return (mid + 1);
}

int	ft_is_prime(int nb)
{
	int i;

	i = 1;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (i < ft_sqrt(nb))
	{
		i++;
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int start;

	start = nb;
	while (1)
	{
		if (ft_is_prime(start))
			return (start);
		start++;
	}
	return (0);
}
