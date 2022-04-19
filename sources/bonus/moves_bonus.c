/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:01:47 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 14:36:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves_bonus.h"

void	put_string(t_game *g, char *string, int offset, int id)
{
	int	len;
	int	index;

	len = ft_strlen1(string);
	index = -1;
	while (++index < 1 + len)
		put_img(g, offset + index + g->w_size[2], g->w_size[3]);
	mlx_string_put(g->m_ptr, g->m_win, 3 + offset * 16, -4, 0x00FF0000, string);
	if (id == 1)
		free(string);
}

void	print_moves(t_game *g)
{
	static int	i = 0;
	static int	offset = 0;
	char		*moves;
	int			len;
	static int	last_move;

	if (g->moves == 2147483647)
		finish_game(g, 'I');
	if (g->map.w >= 5)
	{
		put_string(g, "moves:", 0, 0);
		offset = 4;
	}
	moves = ft_itoa(g->moves);
	len = ft_strlen(moves);
	if (g->map.w < offset + len)
	{	
		free(moves);
		if (i < 2)
			last_move = g->moves - 1;
		moves = ft_itoa(last_move);
		moves[len - 1] = '+';
		i = 2;
	}
	put_string(g, moves, offset, 1);
}
