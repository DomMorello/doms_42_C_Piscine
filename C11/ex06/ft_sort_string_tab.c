/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:05:51 by donglee           #+#    #+#             */
/*   Updated: 2020/02/06 15:36:32 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		get_tab_len(char **tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = get_tab_len(tab);
	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < len - i + 1)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
