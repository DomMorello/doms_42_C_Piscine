/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:33:51 by yshim             #+#    #+#             */
/*   Updated: 2020/02/13 01:52:50 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	less_argc(t_data *data)
{
	if (parse_data(0, data))
	{
		solution(*data);
		free_data2(data);
	}
	else
		print_map_error();
}

int		main(int argc, char **argv)
{
	int		i;
	char	*input;
	t_data	data;

	i = 1;
	if (argc < 2)
		less_argc(&data);
	else
	{
		while (i < argc)
		{
			input = argv[i];
			if (data_open(input, &data) == 1)
			{
				solution(data);
				free_data(&data);
				write(1, "\n", 1);
			}
			i++;
		}
	}
	return (0);
}
