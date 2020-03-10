/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:40:42 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:08:35 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

/*
**	handle conditions
*/

int		handle_condition(int argc, char *argv[], char **input, char **dict)
{
	int	i;

	if (argc == 2)
	{
		(*input) = argv[1];
		(*dict) = "numbers.dict";
	}
	else if (argc == 3)
	{
		(*dict) = argv[1];
		(*input) = argv[2];
	}
	else
		return (0);
	i = 0;
	while ((*input)[i])
	{
		if (!((*input)[i] >= '0' && (*input)[i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
**	main function
*/

int		main(int argc, char *argv[])
{
	char	*input;
	char	*dict;

	g_open_file = 0;
	if (handle_condition(argc, argv, &input, &dict))
	{
		if (solve(dict) == 0)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		start(input);
		free_global(dict);
	}
	return (1);
}
