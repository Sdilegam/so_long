/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:12:33 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/10/26 11:36:21 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	convert_str(char *str, int *flags)
{
	int	index;
	int	len;

	index = -1;
	if (!str)
		return (convert_str("(null)", flags));
	len = ft_strlen(str);
	if (flags[4] < len && flags[4] != -1)
		len = flags[4];
	if (flags[0] != 1 && flags[6] != -1)
		while (++index < flags[6] - (int)len)
			ft_putchar(' ');
	index = -1;
	while (++index < len)
		ft_putchar(str[index]);
	index = -1;
	if (flags[0] == 1 && flags[6] != -1)
		while (++index < flags[6] - (int)len)
			ft_putchar(' ');
	if (len < flags[6] && flags[6] != -1)
		return (flags[6]);
	else
		return (len);
}
