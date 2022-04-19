/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:19:32 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 14:31:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H

# include "so_long.h"

void	move_enemy(t_game *g, int x, int y, int dest[2]);

void	enemy_path(t_game *g, int x, int y);

void	update_enemy(t_game *g);
#endif /* ENEMIES_H */
