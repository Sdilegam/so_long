/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:12:33 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/26 15:12:44 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_ptr(unsigned long ptr, char *base, int *flags)
{
	int	ptr_len;
	int	extra;

	extra = 0;
	ptr_len = ft_hex_len(ptr, 16);
	flags[1] = 1;
	if (flags[1])
		extra = 2;
	if (flags[4] == 0 && ptr == 0)
		ptr_len = 0;
	if (flags[2] == '0' && flags[4] == -1)
		ft_put_pre(base, flags);
	if (!flags[0])
		ft_nbr_padding(ptr_len, extra, flags);
	if (flags[2] != '0' || flags[4] != -1)
		ft_put_pre(base, flags);
	ft_put_nbr(ptr_len, ptr, base, flags);
	if (flags[0])
		ft_nbr_padding(ptr_len, extra, flags);
	if (flags[6] > flags[4] + extra && flags[6] > (int)ptr_len + extra)
		return (flags[6]);
	else if (flags[4] > (int)ptr_len)
		return (flags[4] + extra);
	else
		return (ptr_len + extra);
}
