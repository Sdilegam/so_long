/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:26:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 14:29:58 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

void	update(t_game *g)
{
	int		index1;
	int		index2;

	index2 = -1;
	while (++index2 < g->map.h)
	{
		index1 = -1;
		while (++index1 < g->map.w)
		{
			if (g->map.map[index2][index1] == 'C')
				put_img(g, index1, index2);
		}
	}
}

int	loop_handler(t_game *g)
{
	if (g->goal == 0)
	{
		g->goal = -1;
		g->exit++;
	}
	frame_render(g);
	return (0);
}

int	handle_keys(int key, void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if ((0 <= key && key <= 2) || key == 13)
		move_keys(key, g);
	else if (key == 53)
		clean_exit(g);
	return (0);
}
