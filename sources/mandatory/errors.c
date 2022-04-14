/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:28:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 17:49:16 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>

void	error(int error_id, char *ptr)
{
	if (error_id == 0)
	{
		write(2, "Error\nThe map given isn't rectangular1\n", 39);
		free(ptr);
	}
	if (error_id == 1)
	{
		write(2, "Error\nBad map element\n", 22);
		free(ptr);
	}
	if (error_id == 2)
		perror("Error\n");
	if (error_id == 3)
		write(2, "Error\nError allocating memory for map1\n", 38);
	if (error_id == 4)
		write(2, "Error\nMap must be surrounded by walls1\n", 38);
	if (error_id == 5)
		write(2, "Error\nBad parameters\n", 38);
	if (error_id == 6)
		write(2, "Error\nfile doesn't end with \".ber\"\n", 38);
	exit(1);
}

void	check_extension(char *str)
{
	str += ft_strlen(str) - 4;
	if (str[0] != '.' || str[1] != 'b' || str[2] != 'e' || str[3] != 'r')
		error(6, "");
}

void	free_map_error(char **map, int index)
{
	while (--index >= 0)
		free(map[index]);
	error(2, "");
}
