/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 17:49:30 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_string(t_game *g, char *string, int offset)
{
	int	len;
	int	index;

	len = ft_strlen1(string);
	index = -1;
	while (++index < 1 + len)
		put_img(g, offset + index, 0);
	mlx_string_put(g->m_ptr, g->m_win, 3 + offset * 16, -4, 0x00FF0000, string);
	free(string);
}

void	print_moves(t_game *g)
{
	static int	i = 0;
	static int	offset = 0;
	char		*moves;
	int			len;

	if (g->moves == 2147483647)
		finish_game(g, 'I');
	if (i == 0 && g->map.w >= 5)
	{
		mlx_string_put(g->m_ptr, g->m_win, 0, -5, 0xFFFFFFFF, "Move:");
		offset = 3;
		i++;
	}
	if (i < 2)
	{
		moves = ft_itoa(g->moves);
		len = ft_strlen(moves);
		if (g->map.w < offset + len)
		{	
			moves = ft_itoa(g->moves - 1);
			moves[len - 1] = '+';
			i = 2;
		}
		put_string(g, moves, offset);
	}
}

void	init_game(t_game *g, char *param)
{
	g->goal = 0;
	g->moves = 99;
	g->frame = 0;
	g->facing = 0;
	g->coord.x = 0;
	g->coord.y = 0;
	g->coord.e_y = 0;
	g->coord.e_x = 0;
	g->exit = &g->sprite[3];
	g->m_ptr = mlx_init();
	g->map = read_map(param);
	g->m_win = mlx_new_window(g->m_ptr, g->map.w * BIT, g->map.h * BIT, "S_l");
	environment_image(g);
	chara_image(g);
	map_render(g);
	if (g->goal == 0 || (g->coord.x == 0 && g->coord.y == 0) || \
	(g->coord.e_x == 0 && g->coord.e_y == 0))
	{
		write(2, "Error\nThere must be a player, a chest and an exit\n", 50);
		clean_exit(g);
	}
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
	mlx_loop(game.m_ptr);
	return (0);
}
