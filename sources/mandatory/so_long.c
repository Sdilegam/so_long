/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/12 05:46:42 by sdi-lega         ###   ########.fr       */
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
		put(g->m_ptr, g->m_win, img.img, (x + 1) * 16 - img.w, (y + 1) * 16 - img.h);
		if (g->map.map[y][x] == 'C')
		{
			(g->chest)++;
			img = g->sprite[3];
		}
		else if (g->map.map[y][x] == 'P')
		{
			img = g->chara[g->facing][g->frame];
			g->coord.x = x;
			g->coord.y = y;
		}
		else if (g->map.map[y][x] == 'E')
		{
			img = g->sprite[4];
			g->coord.e_x = x;
			g->coord.e_y = y;
		}
	}
	put(g->m_ptr, g->m_win, img.img, (x + 1) * 16 - img.w, (y + 1) * 16 - img.h);
}

void	map_render(t_game *g)
{
	int		index[2];

	index[1] = -1;
	while (++index[1] < g->map.h)
	{
		index[0] = -1;
		while (++index[0] < g->map.w)
			put_img(g, index[0], index[1]);
	}
}

void loop_handler(t_game *g)
{
	static int	index = -1;
	static int	index2 = 0;
	if (++index2 == 2000)
	{
		if (++index <= 3)
			g->frame = index;
		else 
			index = -1;
		index2 = 0;
		put_img(g, g->coord.x, g->coord.y);
	}	
	if (g->chest == 0)
	{
		g->chest = -1;
		g->sprite[4] = g->sprite[5];
		put_img(g, g->coord.e_x, g->coord.e_y);
	}
}

int move_character(t_game *g, int x, int y)
{
	int	pre_x;
	int	pre_y;
	
	pre_x = g->coord.x;
	pre_y = g->coord.y;
	// printf("%d\n", g->frame);

	if (g->map.map[y][x] != '1' && g->map.map[y][x] != 'E')
	{
		printf("You have done %d moves.\n", g->moves++);
		mlx_string_put(g->m_ptr, g->m_win,16, 30, 0, "test");
		if (g->map.map[y][x] == 'C')
			g->chest--;
		g->map.map[pre_y][pre_x] = '0';
		put_img(g, pre_x, pre_y);
		g->map.map[y][x] = 'P';
		put_img(g, x, y);
	}
	if (g->map.map[y][x] == 'E' && g->chest <= 0)
	{
		printf("the end");
		exit(0);
	}
}



int handle_keys(int key, void *game)
{
	t_game *g;

	g = (t_game *)game;
	if (key == 123)
	{
		g->facing = 3;
		move_character(g, g->coord.x - 1, g->coord.y);
	}
	else if (key == 124)
	{
		g->facing = 2;
		move_character(g, g->coord.x + 1, g->coord.y);
	}
	else if (key == 126)
	{
		g->facing = 0;
		move_character(g, g->coord.x, g->coord.y - 1);
	}
	else if (key == 125)
	{
		g->facing = 1;
		move_character(g, g->coord.x, g->coord.y + 1);
	}
}

void	chara_image(t_game *g)
{
	t_img *img;
	
	img = g->chara[0];
	void *(*f)() = mlx_xpm_file_to_image;
	img[0].img = f(g->m_ptr, "Sprites/u1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/u2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/u3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/u4.xpm", &(img[3].w), &(img[3].h));
	img = g->chara[1];
	img[0].img = f(g->m_ptr, "Sprites/d1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/d2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/d3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/d4.xpm", &(img[3].w), &(img[3].h));
	img = g->chara[2];
	img[0].img = f(g->m_ptr, "Sprites/r1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/r2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/r3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/r4.xpm", &(img[3].w), &(img[3].h));
	img = g->chara[3];
	img[0].img = f(g->m_ptr, "Sprites/l1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/l2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/l3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/l4.xpm", &(img[3].w), &(img[3].h));
}

void	environment_image(t_game *g)
{
	t_img *img;
	
	img = g->sprite;
	void *(*f)() = mlx_xpm_file_to_image;
	img[0].img = f(g->m_ptr, "Sprites/wall.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/floor.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/enemy.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/chest.xpm", &(img[3].w), &(img[3].h));
	img[4].img = f(g->m_ptr, "Sprites/c_end.xpm", &(img[4].w), &(img[4].h));
	img[5].img = f(g->m_ptr, "Sprites/o_end.xpm", &(img[5].w), &(img[5].h));
}

void	init_game(t_game *g, char *param)
{
	void *(*f)() = mlx_xpm_file_to_image;
	g->chest = 0;
	g->moves = 0;
	g->frame = -1;
	g->facing = 0;
	g->m_ptr = mlx_init();
	g->map = read_map(param);
	g->m_win =mlx_new_window(g->m_ptr, g->map.w * 16, g->map.h * 16, "So_long");
	environment_image(g);
	chara_image(g);
	map_render(g);
}

int	main(int argc, char *argv[])
{
	t_game game;
	init_game(&game, argv[1]);
	mlx_key_hook(game.m_win, handle_keys, &game);
	mlx_loop_hook(game.m_ptr, loop_handler, &game);
	mlx_loop(game.m_ptr);
	return (0);
}
