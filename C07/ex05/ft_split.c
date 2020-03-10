/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:02:16 by donglee           #+#    #+#             */
/*   Updated: 2020/02/12 16:17:52 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		included(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		chunk_len(char *str, char *charset)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && !included(str[i], charset))
			cnt++;
		else if (!included(str[i], charset) &&
					included(str[i - 1], charset))
			cnt++;
		i++;
	}
	return (cnt);
}

int		get_strlen(char *str, char *charset)
{
	int len;

	len = 0;
	while (str[len] && !included(*str, charset))
		len++;
	return (len);
}

char	*copy_str(char *dest, char *src, char *charset)
{
	while (*src && !included(*src, charset))
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (src - 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		idx;
	int		len;

	result = (char **)malloc(sizeof(char *) * (chunk_len(str, charset) + 1));
	idx = 0;
	while (*str)
	{
		len = get_strlen(str, charset);
		if (idx == 0 && !included(*str, charset))
		{
			result[idx] = (char *)malloc(sizeof(char) * len + 1);
			str = copy_str(result[idx], str, charset);
			idx++;
		}
		else if (!included(*str, charset) && included(*(str - 1), charset))
		{
			result[idx] = (char *)malloc(sizeof(char) * len + 1);
			str = copy_str(result[idx], str, charset);
			idx++;
		}
		str++;
	}
	result[idx] = 0;
	return (result);
}
