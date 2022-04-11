/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/11 23:52:07 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	error(int error_id)
{
	if (error_id == 1)
		write (2, "Error\nThe map given isn't rectangular.\n", 39);
	exit(1);
}

int	get_len(char* string)
{
	int	index;

	index = 0;
	while (string[index] != '\n' && string[index])
		index++;
	return(index);
}

t_map	get_map_size(char *path)
{
	t_map	map;
	int		file_des;
	char	*reading;

	file_des = open(path, O_RDONLY);
	reading = get_next_line(file_des);
	map.w = get_len(reading);
	map.h = 1;
	while (reading != 0)
	{
		free(reading);
		reading = get_next_line(file_des);
		if (reading)
		{
			map.h++;
			if (get_len(reading) != map.w && reading)
				error(1);
		}
	}
	map.map = malloc(map.h * sizeof(char *));
	close(file_des);
	return (map);
}

t_map	read_map(char *path)
{
	t_map map;
	int	index;
	int	file_des;

	index= -1;
	map = get_map_size(path);
	file_des = open(path, O_RDONLY);
	while (++index < map.h)
		map.map[index] = get_next_line(file_des);
	return (map);
}

void put_img(t_game *g, int x, int y)
{
	t_img img;
	int (*put)(void *, void *, void *, int, int) = mlx_put_image_to_window;
	
	if (g->map.map[y][x] == '1')
		img = g->sprite[0];
	else
	{
		img = g->sprite[1];
		put(g->m_ptr, g->m_win, img.img, (x + 1) * 15 - img.w, (y + 1) * 15 - img.h);
		if (g->map.map[y][x] == 'C')
			img = g->sprite[2];
		else if (g->map.map[y][x] == 'P')
		{
			img = g->sprite[3];
			g->coord.x = x;
			g->coord.y = y;
		}
	}
	put(g->m_ptr, g->m_win, img.img, (x + 1) * 15 - img.w, (y + 1) * 15 - img.h);
}

void	map_render(t_game *g)
{
	int		index[2];
	t_img	*img;

	img = g->sprite;
	index[1] = -1;
	void *(*f)() = mlx_xpm_file_to_image;
	img[0].img = f(g->m_ptr, "Sprites/wall.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/Sol.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/Collectible.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/ir1.xpm", &(img[3].w), &(img[3].h));
	while (++index[1] < g->map.h)
	{
		index[0] = -1;
		while (++index[0] < g->map.w)
			put_img(g, index[0], index[1]);
	}
}

void loop_handler(t_game *g)
{
	static int	index = 0;
	int			index2;
	t_img img[4];
	
	int (*put)(void *, void *, void *, int, int) = mlx_put_image_to_window;
	void *(*f)() = mlx_xpm_file_to_image;
	index2 = 0;
	img[0].img = f(g->m_ptr, "Sprites/ir1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/ir2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/ir3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/ir4.xpm", &(img[3].w), &(img[3].h));
	put(g->m_ptr, g->m_win, g->sprite[1].img, (g->coord.x+ 1) * 15 - g->sprite[1].w, (g->coord.y+ 1) * 15 - g->sprite[1].h);
	put(g->m_ptr, g->m_win, img[index].img, (g->coord.x + 1) * 15 - img[index].w, (g->coord.y + 1) * 15 - img[index].h);
	if (index < 3)
		index++;
	else
		index = 0;
	while (++index2 < 100000000)
	{}
	
		
	
}

int move_character(t_game *g, int x, int y)
{
	int	pre_x;
	int	pre_y;
	
	pre_x = g->coord.x;
	pre_y = g->coord.y;
	if (g->map.map[y][x] != '1')
	{
		g->map.map[pre_y][pre_x] = '0';
		put_img(g, pre_x, pre_y);
		put_img(g, pre_x, pre_y - 1);
		g->map.map[y][x] = 'P';
		put_img(g, x, y);
	}
}



int handle_keys(int key, void *game)
{
	t_game *g;

	g = (t_game *)game;
	if (key == 123)
	{
		move_character(g, g->coord.x - 1, g->coord.y);
	}
	else if (key == 124)
	{
		move_character(g, g->coord.x + 1, g->coord.y);
	}
	else if (key == 126)
	{
		move_character(g, g->coord.x, g->coord.y - 1);
	}
	else if (key == 125)
	{
		move_character(g, g->coord.x, g->coord.y + 1);
	}
}

int	main(int argc, char *argv[])
{
	t_game game;
	game.m_ptr = mlx_init();
	game.map = read_map(argv[1]);
	game.m_win = mlx_new_window(game.m_ptr, game.map.w * 15, game.map.h * 15, "So_long_test");
	map_render(&game);
	mlx_key_hook(game.m_win, handle_keys, &game);
	mlx_loop_hook(game.m_ptr, loop_handler, &game);
	mlx_loop(game.m_ptr);
	return (0);
}
