/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:51:10 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/07 15:39:37 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define U_HEX "0123456789ABCDEF"
# define L_HEX "0123456789abcdef"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned long	t_size;

int				ft_isdigit(int i);
int				ft_strlen(const char *string);
int				ft_printf(const char *string, ...);
t_size			ft_putchar(char chr);
t_size			ft_putstr(char *string);
void			ft_putnbr(unsigned long nbr, char *base, int radix);
void			put_padding(int len, char padding);
t_size			ft_nbr_len(int number, int radix);
unsigned long	put_sign(int number, int *flags);
void			ft_nbr_padding(int len, int sign, int *flags);
int				ft_put_nbr(int len, t_size number, char *base, int *flags);
t_size			ft_hex_len(unsigned long number, int radix);
void			ft_put_pre(char *base, int *flags);
t_size			convert_hexa(unsigned long number, char *base, int *flags);
t_size			convert_char(char chr, int *flags);
t_size			convert_str(char *str, int *flags);
t_size			convert_int(int number, int *flags);
t_size			convert_uint(unsigned int number, int *flags);
int				convert_ptr(unsigned long ptr, char *base, int *flags);

#endif