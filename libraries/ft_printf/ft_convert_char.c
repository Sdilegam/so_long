/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:12:33 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/26 11:26:46 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	convert_char(char chr, int *flags)
{
	int		index;

	index = -1;
	if (flags[0] != 1 && flags[6] != -1)
		while (++index < flags[6] - 1)
			ft_putchar(' ');
	ft_putchar(chr);
	if (flags[0] == 1 && flags[6] != -1)
		while (++index < flags[6] - 1)
			ft_putchar(' ');
	if (1 < flags[6] && flags[6] != -1)
		return (flags[6]);
	else
		return (1);
}
