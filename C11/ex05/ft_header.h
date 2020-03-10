/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee <donglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:03:51 by donglee           #+#    #+#             */
/*   Updated: 2020/02/06 13:01:21 by donglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>

int		ft_plus(int a, int b);
int		ft_minus(int a, int b);
int		ft_multiply(int a, int b);
int		ft_divide(int a, int b);
int		ft_modulo(int a, int b);
int		ft_atoi(char *str);
void	get_digits(long num, long *result);
void	get_pow(int exponent, long *result);
void	ft_putnbr(int nb);

#endif
