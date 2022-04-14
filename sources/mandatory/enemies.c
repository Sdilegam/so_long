/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:18:58 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 12:20:36 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"

void	move_enemy(t_game *g, int x, int y, int dest[2])
{
	char	tile;

	tile = g->map.map[dest[1]][dest[0]];
	if (tile != '1' && tile != 'E' && tile != 'C' && tile != 'B' && tile != 'P')
	{
		g->map.map[y][x] = '0';
		put_img(g, x, y);
		g->map.map[dest[1]][dest[0]] = 'B';
		put_img(g, dest[0], dest[1]);
		g->last_moved[0] = dest[0];
		g->last_moved[1] = dest[1];
	}
	if (tile == 'P')
	{
		finish_game(g, 'B');
	}
}

void	enemy_path(t_game *g, int x, int y)
{
	int	dest[2];

	dest[0] = x;
	dest[1] = y;
	if (x > g->coord.x && g->facing != 2)
		dest[0]--;
	else if (x < g->coord.x && g->facing != 3)
		dest[0]++;
	else if (y > g->coord.y && g->facing != 1)
		dest[1]--;
	else if (y < g->coord.y && g->facing != 0)
		dest[1]++;
	move_enemy(g, x, y, dest);
}

void	update_enemy(t_game *g)
{
	int		i1;
	int		i2;
	char	tile;

	i2 = -1;
	while (++i2 < g->map.h)
	{
		i1 = -1;
		while (++i1 < g->map.w)
		{
			tile = g->map.map[i2][i1];
			if (tile == 'B' && g->last_moved[0] != i1 && g->last_moved[1] != i2)
				enemy_path(g, i1, i2);
		}
	}
	g->last_moved[0] = -1;
	g->last_moved[1] = -1;
}
