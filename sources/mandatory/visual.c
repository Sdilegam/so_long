/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:13:38 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 17:49:26 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	put_itow(t_game *g, int x, int y, t_img sprite)
{
	void	*ptr;
	void	*win;
	t_img	*img;
	int		size[2];

	x = (x + 1) * BIT;
	y = (y + 1) * BIT;
	ptr = g->m_ptr;
	win = g->m_win;
	img = sprite.img;
	size[0] = sprite.w;
	size[1] = sprite.h;
	mlx_put_image_to_window(ptr, win, img, x - size[0], y - size[1]);
}

void	put_img(t_game *g, int x, int y)
{
	t_img	img;

	if (g->map.map[y][x] == '1')
		img = g->sprite[0];
	else
	{
		img = g->sprite[1];
		put_itow(g, x, y, img);
		if (g->map.map[y][x] == 'C')
			img = g->chest[g->frame];
		else if (g->map.map[y][x] == 'P')
			img = g->chara[g->facing][g->frame];
		else if (g->map.map[y][x] == 'B')
			img = g->sprite[2];
		else if (g->map.map[y][x] == 'E')
			img = *g->exit;
	}
	if (g->map.map[y][x] != '0')
		put_itow(g, x, y, img);
}

void	map_render(t_game *g)
{
	int	index1;
	int	index2;

	index2 = -1;
	while (++index2 < g->map.h)
	{
		index1 = -1;
		while (++index1 < g->map.w)
		{
			if (g->map.map[index2][index1] == 'C')
				g->goal++;
			else if (g->map.map[index2][index1] == 'P')
			{
				g->coord.x = index1;
				g->coord.y = index2;
			}
			else if (g->map.map[index2][index1] == 'E')
			{
				g->coord.e_x = index1;
				g->coord.e_y = index2;
			}
			put_img(g, index1, index2);
		}
	}
}
