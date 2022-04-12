/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/12 19:36:29 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int error_id)
{
	if (error_id == 1)
		write(2, "Error\nThe map given isn't rectangular.\n", 39);
	exit(1);
}

int	get_len(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\n' && string[index])
		index++;
	return (index);
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
	t_map	map;
	int		index;
	int		file_des;

	index = -1;
	map = get_map_size(path);
	file_des = open(path, O_RDONLY);
	while (++index < map.h)
		map.map[index] = get_next_line(file_des);
	return (map);
}

void	put_img(t_game *g, int x, int y)
{
	t_img	img;
	int		pixel_x;
	int		pixel_y;
	int		(*put)(void *, void *, void *, int, int);

	pixel_x = (x + 1) * BIT;
	pixel_y = (y + 1) * BIT;
	put = mlx_put_image_to_window;
	if (g->map.map[y][x] == '1')
		img = g->sprite[0];
	else
	{
		img = g->sprite[1];
		put(g->m_ptr, g->m_win, img.img, pixel_x - img.w, pixel_y - img.h);
		if (g->map.map[y][x] == 'C')
			img = g->chest[g->frame];
		else if (g->map.map[y][x] == 'P')
			img = g->chara[g->facing][g->frame];
		else if (g->map.map[y][x] == 'B')
			img = g->sprite[2];
		else if (g->map.map[y][x] == 'E')
			img = g->sprite[3];
	}
	if (g->map.map[y][x] != '0')
	{
		put(g->m_ptr, g->m_win, img.img, pixel_x - img.w, pixel_y - img.h);
	}
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

int loop_handler(t_game *g)
{
	static int index = -1;
	static int index2 = 0;
	static int index3 = -1;

	if (++index2 == 1000)
	{
		if (++index <= 3)
			g->frame = index;
		else
			index = -1;
		put_img(g, g->coord.x, g->coord.y);
	}
	if (index2 == 2000)
	{
		if (++index3 <= 3)
			g->frame = index3;
		else
			index3 = -1;
		update(g);
		index2 = 0;
	}
	if (g->goal == 0)
	{
		g->goal = -1;
		g->sprite[3] = g->sprite[4];
		put_img(g, g->coord.e_x, g->coord.e_y);
	}
	return (0);
}


void	move_enemy(t_game *g, int x, int y, int dest_x, int dest_y)
{
	int		pre_x;
	int		pre_y;
	char	tile;

	tile = g->map.map[dest_y][dest_x];
	if (tile != '1' && tile != 'E' && tile != 'C' && tile != 'B' && tile != 'P')
	{
		g->map.map[y][x] = '0';
		put_img(g, x, y);
		g->map.map[dest_y][dest_x] = 'B';
		put_img(g, dest_x, dest_y);
		g->last_moved[0] = dest_x;
		g->last_moved[1] = dest_y;
	}
	if (tile == 'P')
	{
		printf("You lost!");
		exit(0);
	}
}

void	enemy_path(t_game *g, int x, int y)
{
	if (x > g->coord.x && g->facing != 2)
		move_enemy(g, x, y, x - 1, y);
	else if (x < g->coord.x && g->facing != 3)
		move_enemy(g, x, y, x + 1, y);
	else if (y > g->coord.y && g->facing != 1)
		move_enemy(g, x, y, x, y - 1);
	else if (y < g->coord.y && g->facing != 0)
		move_enemy(g, x, y, x, y + 1);
}

void	update_enemy(t_game *g)
{
	int		index1;
	int		index2;

	index2 = -1;
	while (++index2 < g->map.h)
	{
		index1 = -1;
		while (++index1 < g->map.w)
		{
			if (g->map.map[index2][index1] == 'B' && g->last_moved[0] != index1 && g->last_moved[1] != index2)
				enemy_path(g, index1, index2);
		}
	}
	g->last_moved[0] = -1;
	g->last_moved[1] = -1;
}

void	move_character(t_game *g, int x, int y)
{
	int	pre_x;
	int	pre_y;

	pre_x = g->coord.x;
	pre_y = g->coord.y;
	if (g->map.map[y][x] != '1' && g->map.map[y][x] != 'E' && g->map.map[y][x] != 'B')
	{
		update_enemy(g);
		printf("You have done %d moves.\n", ++g->moves);
		if (g->map.map[y][x] == 'C')
			g->goal--;
		g->map.map[pre_y][pre_x] = '0';
		put_img(g, pre_x, pre_y);
		g->map.map[y][x] = 'P';
		g->coord.x = x;
		g->coord.y = y;
		put_img(g, x, y);
	}
	if (g->map.map[y][x] == 'E' && g->goal <= 0)
	{
		printf("the end");
		exit(0);
	}
	if (g->map.map[y][x] == 'B')
	{
		printf("You lost!");
		exit(0);
	}
}

void	move_keys(int key, t_game *g)
{
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
	else if (key == 125)
	{
		g->facing = 1;
		move_character(g, g->coord.x, g->coord.y + 1);
	}
	else
	{
		g->facing = 0;
		move_character(g, g->coord.x, g->coord.y - 1);
	}
}


int	handle_keys(int key, void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if (123 <= key && key <=126)
		move_keys(key, g);

	return(0);
}

void	chara_image(t_game *g)
{
	t_img	*img;
	void	*(*f)();

	img = g->chara[0];
	f = mlx_xpm_file_to_image;
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

void environment_image(t_game *g)
{
	t_img	*img;
	void	*(*f)();

	img = g->chest;
	f = mlx_xpm_file_to_image;
	img[0].img = f(g->m_ptr, "Sprites/chest1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/chest2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/chest3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/chest4.xpm", &(img[3].w), &(img[3].h));
	img = g->sprite;
	img[0].img = f(g->m_ptr, "Sprites/wall.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "Sprites/floor2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "Sprites/enemy.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "Sprites/c_end.xpm", &(img[3].w), &(img[3].h));
	img[4].img = f(g->m_ptr, "Sprites/o_end.xpm", &(img[4].w), &(img[4].h));
}

void	init_game(t_game *g, char *param)
{
	void	*(*f)();

	f = mlx_xpm_file_to_image;
	g->goal = 0;
	g->moves = 0;
	g->frame = 0;
	g->facing = 0;
	g->m_ptr = mlx_init();
	g->map = read_map(param);
	g->m_win = mlx_new_window(g->m_ptr, g->map.w * BIT, g->map.h * BIT, "S_l");
	environment_image(g);
	chara_image(g);
	map_render(g);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game, argv[1]);
	mlx_key_hook(game.m_win, handle_keys, &game);
	mlx_loop_hook(game.m_ptr, loop_handler, &game);
	mlx_do_key_autorepeaton(game.m_ptr);
	mlx_loop(game.m_ptr);
	return (0);
}
