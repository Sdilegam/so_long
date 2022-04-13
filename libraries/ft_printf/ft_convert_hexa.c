/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:14:18 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/26 11:27:04 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	ft_hex_len(unsigned long number, int radix)
{
	t_size	len;

	len = 1;
	while (number / radix > 0 || number / radix <= 0)
	{
		number /= radix;
		len ++;
	}
	return (len);
}

void	ft_put_pre(char *base, int *flags)
{
	if (flags[1])
	{
		if (base[10] == 'A')
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
}

t_size	convert_hexa(unsigned long number, char *base, int *flags)
{
	t_size			number_len;
	int				extra;

	number_len = ft_hex_len(number, 16);
	extra = 0;
	if (flags[1] && number != 0)
		extra = 2;
	if (flags[4] == 0 && number == 0)
		number_len = 0;
	if (flags[2] == '0' && flags[4] == -1 && number != 0)
		ft_put_pre(base, flags);
	if (!flags[0])
		ft_nbr_padding(number_len, extra, flags);
	if ((flags[2] != '0' || flags[4] != -1) && number != 0)
		ft_put_pre(base, flags);
	ft_put_nbr(number_len, number, base, flags);
	if (flags[0])
		ft_nbr_padding(number_len, extra, flags);
	if (flags[6] > flags[4] + extra && flags[6] > (int)number_len + extra)
		return (flags[6]);
	else if (flags[4] > (int)number_len)
		return (flags[4] + extra);
	else
		return (number_len + extra);
}
