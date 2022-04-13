/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:46:52 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/19 15:17:51 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	convert_int(int number, int *flags)
{
	t_size			number_len;
	unsigned long	new_number;
	int				extra;

	number_len = ft_nbr_len(number, 10);
	extra = 0;
	if (flags[4] == 0 && number == 0)
		number_len = 0;
	if (number < 0 || flags[3] || flags[5])
		extra ++;
	if (flags[2] == '0' && flags[4] == -1)
		new_number = put_sign(number, flags);
	if (!flags[0])
		ft_nbr_padding(number_len, extra, flags);
	if (flags[2] != '0' || flags[4] != -1)
		new_number = put_sign(number, flags);
	ft_put_nbr(number_len, new_number, "0123456789", flags);
	if (flags[0])
		ft_nbr_padding(number_len, extra, flags);
	if (flags[6] > flags[4] + extra && flags[6] > (int)number_len + extra)
		return (flags[6]);
	else if (flags[4] > (int)number_len)
		return (flags[4] + extra);
	else
		return (number_len + extra);
}
