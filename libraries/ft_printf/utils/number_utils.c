/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:57:45 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/19 15:12:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	ft_nbr_len(int number, int radix)
{
	t_size	len;

	len = 1;
	while (number / radix > 0 || number / radix < 0)
	{
		number /= radix;
		len ++;
	}
	return (len);
}

unsigned long	put_sign(int number, int *flags)
{
	unsigned long	value;

	if (number < 0)
	{
		ft_putchar('-');
		value = (long)number * -1;
	}
	else
	{
		if (flags[3])
			ft_putchar(' ');
		else if (flags[5])
			ft_putchar('+');
		value = number;
	}
	return (value);
}

void	ft_nbr_padding(int len, int sign, int *flags)
{
	if (flags[4] > len + sign)
		len = flags[4] + sign;
	else
		len = len + sign;
	if (!flags[0])
	{
		if (flags[4] != -1)
			put_padding(flags[6] - len, ' ');
		else
			put_padding(flags[6] - len, flags[2]);
	}
	else
	{
		if (flags[4] > len + sign)
			put_padding(flags[6] - len, ' ');
		else
			put_padding(flags[6] - len, ' ');
	}
}

int	ft_put_nbr(int len, t_size number, char *base, int *flags)
{
	int	radix;

	radix = ft_strlen(base);
	if (flags[4] != 0 || number != 0)
	{
		if (flags[4] < len)
		{
			ft_putnbr(number, base, radix);
			return (len);
		}
		else
		{
			put_padding(flags[4] - len, '0');
			ft_putnbr(number, base, radix);
			return (flags[4]);
		}
	}
	return (0);
}
