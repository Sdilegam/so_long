/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 15:04:33 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

int	check_map_element(char element)
{
	if (element != '1' && element != '0' && element != 'P' && \
		element != 'E' && element != 'C' && element != 'B')
		return (1);
	return (0);
}

int	get_len(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\n' && string[index])
	{
		if (check_map_element(string[index]) == 1)
			error(1, string);
		index++;
	}
	return (index);
}
