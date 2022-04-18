/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:28:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/18 16:59:59 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>

void	error(int error_id, char *ptr)
{
	if (error_id == 0)
	{
		write(2, "Error\nThe map given isn't rectangular!\n", 39);
		free(ptr);
	}
	if (error_id == 1)
	{
		write(2, "Error\nBad map element!\n", 23);
		free(ptr);
	}
	if (error_id == 2)
		perror("Error\n");
	if (error_id == 3)
		write(2, "Error\nError allocating memory for map!\n", 39);
	if (error_id == 4)
		write(2, "Error\nMap must be surrounded by walls!\n", 39);
	if (error_id == 5)
		write(2, "Error\nBad parameters!\n", 22);
	if (error_id == 6)
		write(2, "Error\nWrong file!", 17);
	if (error_id == 7)
		write(2, "Error\nMap must contain exactly 1 player and at least 1 chest\
 and exit!\n", 72);
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
