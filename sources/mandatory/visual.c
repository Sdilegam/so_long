/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:13:38 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/15 15:06:46 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	put_itow(t_game *g, int x, int y, t_img sprite)
{
	void	*ptr;
	void	*win;
	t_img	*img;
	int		size[2];

	x = (x + 1 - g->w_size[2]) * BIT;
	y = (y + 1 - g->w_size[3]) * BIT;
	ptr = g->m_ptr;
	win = g->m_win;
	img = sprite.img;
	size[0] = sprite.w;
	size[1] = sprite.h;
	mlx_put_image_to_window(ptr, win, img, x - size[0], y - size[1] );
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

void	get_offset(t_game *g)
{
	if (g->coord.x >= (g->w_size[0] / 2) && g->map.w - (g->w_size[0] / 2) > g->coord.x)
		g->w_size[2] = g->coord.x - (g->w_size[0] / 2);
	if (g->map.w - (g->w_size[0] / 2) < g->coord.x)
		g->w_size[2] = g->map.w - (g->w_size[0]);
	if (g->coord.y >= (g->w_size[1] / 2) && g->map.h - (g->w_size[1] / 2) > g->coord.y)
		g->w_size[3] = g->coord.y - (g->w_size[1] / 2);
	if (g->map.h - (g->w_size[1] / 2) < g->coord.y)
		g->w_size[3] = g->map.h - (g->w_size[1]);
}

void	frame_render(t_game *g)
{
	int	index1;
	int	index2;

	index2 = -1;
	get_offset(g);
	if (g->coord.y - (g->w_size[1] / 2) > 0)
		index2 = g->w_size[3] - 1;
	while (++index2 < g->w_size[1] + g->w_size[3])
	{
		index1 = -1;
		if (g->coord.x < (g->w_size[0] / 2))
			index1 = g->w_size[2] - 1;
		while (++index1 < g->w_size[0] + g->w_size[2])
		{
			put_img(g, index1, index2);
		}
	}
	print_moves(g);
}
