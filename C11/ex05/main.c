/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:44:47 by donglee           #+#    #+#             */
/*   Updated: 2020/02/07 08:56:02 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		handle_exception(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	if ((argv[2][0] == '/' && argv[3][0] == '0'))
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (argv[2][0] == '%' && argv[3][0] == '0')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (argv[2][1] != 0 || !(argv[2][0] == '+' || argv[2][0] == '-'
	|| argv[2][0] == '/'
		|| argv[2][0] == '*' || argv[2][0] == '%'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

void	solve(char *value1, char *value2, int (*f)(int, int))
{
	int first;
	int second;
	int result;

	first = ft_atoi(value1);
	second = ft_atoi(value2);
	result = f(first, second);
	ft_putnbr(result);
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	int (*fp[5])(int, int);

	fp[0] = ft_plus;
	fp[1] = ft_minus;
	fp[2] = ft_multiply;
	fp[3] = ft_divide;
	fp[4] = ft_modulo;
	if (handle_exception(argc, argv))
	{
		if (argv[2][0] == '+')
			solve(argv[1], argv[3], fp[0]);
		if (argv[2][0] == '-')
			solve(argv[1], argv[3], fp[1]);
		if (argv[2][0] == '*')
			solve(argv[1], argv[3], fp[2]);
		if (argv[2][0] == '/')
			solve(argv[1], argv[3], fp[3]);
		if (argv[2][0] == '%')
			solve(argv[1], argv[3], fp[4]);
	}
	return (0);
}
