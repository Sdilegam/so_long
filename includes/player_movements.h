/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:45:21 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 11:47:09 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVEMENTS_H
# define PLAYER_MOVEMENTS_H

# include "so_long.h"

void	move_character(t_game *g, int x, int y);

void	move_keys(int key, t_game *g);

#endif /* PLAYER_MOVEMENTS_H */
