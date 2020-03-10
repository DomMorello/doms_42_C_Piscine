/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:23:14 by donglee           #+#    #+#             */
/*   Updated: 2020/02/07 12:01:35 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	handle_exception(int argc)
{
	if (argc >= 3)
	{
		write(1, "Too many arguments.\n", 20);
		return (-1);
	}
	if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (-1);
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int input;
	char buf;
	int check;

	if (handle_exception(argc) != 1)
		return (-1);
	if ((input = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (-1);
	}
	else
	{
		check = 0;
		while ((check = read(input, &buf, 1)) > 0)
			write(1, &buf, 1);
	}
	close(input);
	return (0);
}
