/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:10:07 by donglee           #+#    #+#             */
/*   Updated: 2020/02/09 23:14:40 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** whether the c character is iscluded in charset(used in ft_split function)
*/

#include "ft_header.h"

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

/*
**	get the length of chunk in ft_split function
*/

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

/*
**	copy the string from src to dest when it's not included in chatset
**	(used in ft_split)
*/

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

/*
**	 if there is any character included in charset it will split the strings
*/

char    **ft_split(char *str, char *charset)
{
    char    **result;
    int     idx;
    int     len;
	
    result = NULL;
    if ((result = (char **)malloc(sizeof(char *) * (chunk_len(str, charset) + 1))) == 0)
        return (NULL);
    idx = 0;
    while (*str)
    {
        len = get_strlen(str, charset);
        if (idx == 0 && !included(*str, charset))
        {
            if ((result[idx] = (char *)malloc(sizeof(char) * len + 1)) == 0)
                return (NULL);
            str = copy_str(result[idx], str, charset);
            idx++;
        }
        else if (!included(*str, charset) && included(*(str - 1), charset))
        {
            if ((result[idx] = (char *)malloc(sizeof(char) * len + 1)) == 0)
                return(NULL);
            str = copy_str(result[idx], str, charset);
            idx++;
        }
        str++;
    }
    result[idx] = 0;
    return (result);
}

/*
**	check if the ch(character) is a white space
*/

int		is_space(char ch)
{
	if (ch == ' ' || ch == 9 || (ch >= 11 && ch <= 13))
		return (1);
	return (0);
}
