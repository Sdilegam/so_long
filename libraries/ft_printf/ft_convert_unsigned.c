/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:34:34 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/19 15:18:01 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	ft_uint_len(unsigned int number)
{
	t_size	len;

	len = 1;
	while (number / 10 > 0)
	{
		number /= 10;
		len ++;
	}
	return (len);
}

t_size	convert_uint(unsigned int number, int *flags)
{
	t_size			number_len;

	number_len = ft_uint_len(number);
	if (flags[4] == 0 && number == 0)
		number_len = 0;
	if (!flags[0])
		ft_nbr_padding(number_len, 0, flags);
	ft_put_nbr(number_len, number, "0123456789", flags);
	if (flags[0])
		ft_nbr_padding(number_len, 0, flags);
	if (flags[6] > flags[4] && flags[6] > (int)number_len)
		return (flags[6]);
	else if (flags[4] > (int)number_len)
		return (flags[4]);
	else
		return (number_len);
}
