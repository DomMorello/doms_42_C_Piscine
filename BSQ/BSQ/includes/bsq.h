/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:41:04 by yshim             #+#    #+#             */
/*   Updated: 2020/02/12 23:30:07 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	int		width;
	int		height;
	char	empty;
	char	obs;
	char	fill;
	char	**map;
	char	*source;
}				t_data;

typedef struct	s_solution
{
	int x;
	int y;
	int size;
}				t_solution;

int				data_open(char *input, t_data *data);
int				check_width(t_data *data);
int				put_map(char *input, t_data *data);
int				get_header(char *input, t_data *data);
int				alloc_data(char *input, int fd, t_data *data);
int				alloc_map(char *input, t_data *data);
int				read_alloc_map(int fd, t_data *data);
char			*save_header(int fd);
int				check_header(char *header);
int				check_header_dup(char *str);
int				check_header_num(char *str);
int				print_map_error(void);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
void			solution(t_data ref);
void			free_int_arr(int **map, int h);
void			print_solution(t_solution sol, t_data ref, int ***map);
void			free_data2(t_data *data);
void			free_data(t_data *data);
int				**init_map(t_data ref);
int				get_min(int **map, int i, int j);
int				check_width2(t_data *data, unsigned int *curr_w);
int				parse_normal_line(t_data *data, char *line, int length);
int				process_lines(t_data *data, int index,
				char *content, int total);
int				parse_header_line(t_data *data, char *line, int length);
int				parse_data(int fd, t_data *data);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_extend_arr(char *orig, char *n_cont, int old_len, int len);
int				read_full(int fd, char **content, int *total);

#endif
