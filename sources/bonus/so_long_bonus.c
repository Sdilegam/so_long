/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:06:00 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_win_size(t_game *g)
{
	int	win_h;
	int	win_w;

	win_h = 482;
	win_w = 1000;
	g->w_size[0] = g->map.w;
	g->w_size[1] = g->map.h;
	g->w_size[2] = 0;
	g->w_size[3] = 0;
	if (g->w_size[0] * BIT > win_w)
		g->w_size[0] = win_w / BIT;
	if (g->w_size[1] * BIT > win_h)
		g->w_size[1] = win_h / BIT;
}

void	check_elements(t_game *g, int elem[2])
{
	if (elem[0] != 1 || elem[1] == 0 || g->goal <= 0)
		error(7, "");
}

void	get_elements(t_game *g)
{
	int	index1;
	int	index2;
	int	numbers[2];

	numbers[0] = 0;
	numbers[1] = 0;
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
				numbers[0]++;
				g->coord.x = index1;
				g->coord.y = index2;
			}
			else if (g->map.map[index2][index1] == 'E')
				numbers[1]++;
		}
	}
	check_elements(g, numbers);
}

void	init_game(t_game *g, char *param)
{
	g->goal = 0;
	g->moves = 0;
	g->frame = 0;
	g->facing = 0;
	g->coord.x = 0;
	g->coord.y = 0;
	g->exit = &g->sprite[3];
	g->m_ptr = mlx_init();
	g->map = read_map(param);
	set_win_size(g);
	g->m_win = mlx_new_window(g->m_ptr, g->w_size[0] * BIT, g->w_size[1] * BIT, \
																		"S_l");
	environment_image(g);
	chara_image(g);
	get_elements(g);
	frame_render(g);
	print_moves(g);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2 || ft_strlen(argv[1]) <= 4)
		error(5, "");
	check_extension(argv[1]);
	init_game(&game, argv[1]);
	mlx_key_hook(game.m_win, handle_keys, &game);
	mlx_loop_hook(game.m_ptr, loop_handler, &game);
	mlx_hook(game.m_win, 17, 0, close_game, &game);
	mlx_loop(game.m_ptr);
	return (0);
}
