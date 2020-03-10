/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:36:24 by cbaek             #+#    #+#             */
/*   Updated: 2020/02/09 23:04:29 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** this struct contatins key, value data from the file
*/

typedef struct	s_dict
{
	int		size;
	int		line_size;
	char	**key_value;
	char	**key;
	char	**value;
}				t_dict;

t_dict			g_data;

int				g_open_file;

void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				included(char c, char *charset);
int				get_strlen(char *str, char *charset);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
void			print_digit(char *value);
char			*get_digit_key(int *length, int *idx);
char			*get_three_digit(char *input, int *idx, int *len);
char			*get_value(char *key);
int				is_readable(char c1, char c2);
char			*add_two_char(char c1, char c2);
void			print_head(char *str);
void			print_three_num(char *str);
int				chunk_len(char *str, char *charset);
char			*copy_str(char *dest, char *src, char *charset);
char			**ft_split(char *str, char *charset);
int				open_file(char *dict);
int				get_row_len(char *dict);
int				get_len(char *dict);
int				is_space(char ch);
void			refactor_value(char *dict);
int				put_key(char *dict);
int				put_value(char *dict);
int				check_key(char *dict);
int				check_value(char *dict);
int				solve(char *dict);
void			free_global(char *dict);
int				handle_condition(int argc, char *argv[],
				char **input, char **dict);
void			start(char *input);


#endif
