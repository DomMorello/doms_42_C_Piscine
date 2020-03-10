/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:13:22 by donglee           #+#    #+#             */
/*   Updated: 2020/01/25 11:47:12 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		is_minor(char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		is_major(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int idx;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] = str[0] - 32;
	idx = 1;
	while (str[idx] != '\0')
	{
		if (is_alpha(str[idx]))
		{
			if (is_alphanum(str[idx - 1]))
			{
				if (is_major(str[idx]))
					str[idx] = str[idx] + 32;
			}
			else if (is_minor(str[idx]))
				str[idx] = str[idx] - 32;
		}
		idx++;
	}
	return (str);
}
