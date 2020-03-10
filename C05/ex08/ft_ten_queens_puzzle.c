/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:22:59 by donglee           #+#    #+#             */
/*   Updated: 2020/02/01 08:35:38 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_column[10];

void	print_row(void)
{
	char	print;
	int		i;

	i = 0;
	while (i < 10)
	{
		print = g_column[i] + '0';
		write(1, &print, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		is_safe(int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (g_column[i] == g_column[row])
			return (0);
		if (g_column[i] - g_column[row] == (row - i))
			return (0);
		if (g_column[row] - g_column[i] == (row - i))
			return (0);
		i++;
	}
	return (1);
}

void	solve_puzzle(int *count, int row)
{
	int i;

	i = 0;
	if (row == 10)
	{
		print_row();
		(*count)++;
	}
	else
	{
		while (i < 10)
		{
			g_column[row] = i;
			if (is_safe(row))
				solve_puzzle(count, row + 1);
			i++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int count;

	count = 0;
	solve_puzzle(&count, 0);
	return (count);
}

int main(int argc, char const *argv[])
{
	ft_ten_queens_puzzle();
	return 0;
}
