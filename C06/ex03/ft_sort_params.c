/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:55:30 by donglee           #+#    #+#             */
/*   Updated: 2020/01/29 14:49:33 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_argv(int size, char *arr[])
{
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (arr[i][j])
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int idx;

	idx = 0;
	while (s1[idx] || s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	print_argv(argc, argv);
	return (0);
}
