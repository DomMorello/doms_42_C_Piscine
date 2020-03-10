/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:36:44 by donglee           #+#    #+#             */
/*   Updated: 2020/01/29 15:30:44 by donglee          ###   ########.fr       */
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
	return (0);
}
