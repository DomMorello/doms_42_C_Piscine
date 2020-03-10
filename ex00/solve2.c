/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:38:25 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:13:41 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	convert two char into one
*/

#include "ft_header.h"

char	*add_two_char(char c1, char c2)
{
	char *result;

	result = (char *)malloc(sizeof(char) * 3);
	result[0] = c1;
	result[1] = c2;
	result[2] = 0;
	return (result);
}

/*
**	print the head part of num
*/

void	print_head(char *str)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	len = ft_strlen(str);
	if (len == 1)
	{
		tmp = get_value(str);
		print_digit(str);
		return ;
	}
	if (is_readable(str[0], str[1]))
	{
		tmp = add_two_char(str[0], str[1]);
		tmp2 = get_value(tmp);
		print_digit(tmp2);
		return ;
	}
	tmp = add_two_char(str[0], '0');
	tmp = get_value(tmp);
	print_digit(tmp);
	tmp = get_value(&(str[1]));
	print_digit(tmp);
}

/*
**	print the three num
*/

void    print_three_num(char *str)
{
    char *tmp;
    char one[2];
	
    one[0] = str[0];
    one[1] = 0;
    if (str[0] != '0')
    {
        tmp = get_value(one);
        print_digit(tmp);
        tmp = get_value("100");
        print_digit(tmp);
    }
    if (is_readable(str[1], str[2]))
    {
        tmp = add_two_char(str[1], str[2]);
        tmp = get_value(tmp);
        print_digit(tmp);
        return ;
    }
    tmp = add_two_char(str[1], '0');
    tmp = get_value(tmp);
    print_digit(tmp);
    tmp = get_value(&(str[2]));
    print_digit(tmp);
}

/*
**	start to convert the key into value
*/

void	start(char *input)
{
	int		len;
	int		idx;
	char	*tmp;

	len = ft_strlen(input);
	idx = 0;
	if (len % 3 == 1)
		print_head(&(input[idx++]));
	else
	{
		print_head(add_two_char(input[0], input[1]));
		idx = idx + 2;
	}
	ft_putstr(get_value(get_digit_key(&len, &idx)));
	while (idx < len)
	{
		tmp = get_three_digit(input, &idx, &len);
		print_three_num(tmp);
		if (idx != len)
			ft_putstr(get_value(get_digit_key(&len, &idx)));
	}
}
