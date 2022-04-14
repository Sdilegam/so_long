/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:21 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 17:13:11 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "so_long.h"

void	error(int error_id, char *ptr);
void	free_map_error(char **map, int index);
void	check_extension(char *str);

#endif /* ERRORS_H */
