/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:54:39 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 14:31:29 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "so_long.h"

void	chara_image(t_game *g);

void	environment_image(t_game *g);

t_map	get_map_size(char *path);

t_map	read_map(char *path);

#endif /* INIT_GAME_H */
