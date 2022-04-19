/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:21 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:10:18 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

# include "so_long_bonus.h"

void	error(int error_id, char *ptr);
void	free_map_error(char **map, int index);
void	check_extension(char *str);

#endif /* ERRORS_BONUS_H */
