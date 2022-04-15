/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:25:47 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/15 16:17:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "end_game.h"

void	finish_game(t_game *g, char tile)
{
	if (tile == 'B')
		write(1, "You got killed by the evil painting! :(\n", 40);
	if (tile == 'I')
		write(1, "You made too much moves! :(\n", 28);
	else if (tile == 'E')
		ft_printf("YOU WON IN %d MOVES!\n", ++g->moves);
	clean_exit(g);
}

void	free_map(t_map map)
{
	int	index;

	index = -1;
	while (++index < map.h)
		free(map.map[index]);
	free(map.map);
}

void	clean_exit(t_game *g)
{
	int	index1;
	int	index2;

	index1 = -1;
	while (++index1 < 4)
		mlx_destroy_image(g->m_ptr, g->chest[index1].img);
	index1 = -1;
	while (++index1 < 5)
		mlx_destroy_image(g->m_ptr, g->sprite[index1].img);
	index1 = -1;
	while (++index1 < 4)
	{
		index2 = -1;
		while (++index2 < 4)
			mlx_destroy_image(g->m_ptr, g->chara[index1][index2].img);
	}
	mlx_destroy_window(g->m_ptr, g->m_win);
	free_map(g->map);
	exit(0);
}

int	close_game(t_game *g)
{
	clean_exit(g);
	return (0);
}
