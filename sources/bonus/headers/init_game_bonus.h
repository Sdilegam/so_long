/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:54:39 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:10:00 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_BONUS_H
# define INIT_GAME_BONUS_H

# include "so_long_bonus.h"

void	chara_image(t_game *g);

void	environment_image(t_game *g);

t_map	get_map_size(char *path);

t_map	read_map(char *path);

#endif /* INIT_GAME_BONUS_H */
