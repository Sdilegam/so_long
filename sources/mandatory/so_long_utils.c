/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:13:22 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/13 11:30:11 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	recc_assign(long i, char *a, unsigned index)
{
	if (i >= 10)
		recc_assign(i / 10, a, index - 1);
	a[index] = i % 10 + '0';
}

char	*ft_itoa(int n)
{
	unsigned	int_len;
	long		temp_n;
	char		*result;

	int_len = 1;
	temp_n = n;
	if (temp_n < 0)
		int_len++;
	while (!(n < 10 && n > -10))
	{
		n /= 10;
		int_len++;
	}
	result = ft_calloc(int_len + 1, 1);
	if (!result)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		temp_n *= -1;
	}
	recc_assign(temp_n, result, int_len - 1);
	return (result);
}
