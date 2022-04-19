/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:35:37 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:06:29 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_movements_bonus.h"

void	move_character(t_game *g, int x, int y)
{
	char	*tile;

	tile = &g->map.map[y][x];
	if (*tile != '1' && *tile != 'E' && *tile != 'B')
	{
		update_enemy(g);
		if (*tile == 'B')
			finish_game(g, *tile);
		g->moves++;
		if (g->map.map[y][x] == 'C')
			g->goal--;
		g->map.map[g->coord.y][g->coord.x] = '0';
		g->coord.x = x;
		g->coord.y = y;
		g->map.map[y][x] = 'P';
	}
	if ((*tile == 'E' && g->goal <= 0) || *tile == 'B')
		finish_game(g, *tile);
}

void	move_keys(int key, t_game *g)
{
	if (key == 0)
	{
		g->facing = 3;
		move_character(g, g->coord.x - 1, g->coord.y);
	}
	else if (key == 2)
	{
		g->facing = 2;
		move_character(g, g->coord.x + 1, g->coord.y);
	}
	else if (key == 1)
	{
		g->facing = 1;
		move_character(g, g->coord.x, g->coord.y + 1);
	}
	else
	{
		g->facing = 0;
		move_character(g, g->coord.x, g->coord.y - 1);
	}
}
