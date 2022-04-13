/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/13 21:54:31 by sdi-lega         ###   ########.fr       */
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
	static int	index = -1;
	static int	index2 = 0;
	t_img		temp;

	if (++index2 == 1000)
	{
		if (++index <= 3)
			g->frame = index;
		else
			index = -1;
		put_img(g, g->coord.x, g->coord.y);
	}
	if (index2 == 1500)
	{
		update(g);
		index2 = 0;
	}
	if (g->goal == 0)
	{
		g->goal = -1;
		g->exit++;
		put_img(g, g->coord.e_x, g->coord.e_y);
	}
	return (0);
}

void	move_enemy(t_game *g, int x, int y, int dest[2])
{
	char	tile;

	tile = g->map.map[dest[1]][dest[0]];
	if (tile != '1' && tile != 'E' && tile != 'C' && tile != 'B' && tile != 'P')
	{
		g->map.map[y][x] = '0';
		put_img(g, x, y);
		g->map.map[dest[1]][dest[0]] = 'B';
		put_img(g, dest[0], dest[1]);
		g->last_moved[0] = dest[0];
		g->last_moved[1] = dest[1];
	}
	if (tile == 'P')
	{
		finish_game(g, 'B');
	}
}

void	enemy_path(t_game *g, int x, int y)
{
	int	dest[2];

	dest[0] = x;
	dest[1] = y;
	if (x > g->coord.x && g->facing != 2)
		dest[0]--;
	else if (x < g->coord.x && g->facing != 3)
		dest[0]++;
	else if (y > g->coord.y && g->facing != 1)
		dest[1]--;
	else if (y < g->coord.y && g->facing != 0)
		dest[1]++;
	move_enemy(g, x, y, dest);
}

void	update_enemy(t_game *g)
{
	int		i1;
	int		i2;
	char	tile;

	i2 = -1;
	while (++i2 < g->map.h)
	{
		i1 = -1;
		while (++i1 < g->map.w)
		{
			tile = g->map.map[i2][i1];
			if (tile == 'B' && g->last_moved[0] != i1 && g->last_moved[1] != i2)
				enemy_path(g, i1, i2);
		}
	}
	g->last_moved[0] = -1;
	g->last_moved[1] = -1;
}

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

void	move_character(t_game *g, int x, int y)
{
	char	*tile;

	tile = &g->map.map[y][x];
	if (*tile != '1' && *tile != 'E' && *tile != 'B')
	{
		update_enemy(g);
		if (*tile == 'B')
			finish_game(g, *tile);
		g->moves++;
		print_moves(g);
		if (g->map.map[y][x] == 'C')
			g->goal--;
		g->map.map[g->coord.y][g->coord.x] = '0';
		put_img(g, g->coord.x, g->coord.y);
		g->coord.x = x;
		g->coord.y = y;
		g->map.map[y][x] = 'P';
		put_img(g, x, y);
	}
	if ((*tile == 'E' && g->goal <= 0) || *tile == 'B')
		finish_game(g, *tile);
}

void	move_keys(int key, t_game *g)
{
	if (key == 0)
	{
		g->facing = 3;
		move_character(g, g->coord.x - 1, g->coord.y);
	}
	else if (key == 2)
	{
		g->facing = 2;
		move_character(g, g->coord.x + 1, g->coord.y);
	}
	else if (key == 1)
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

void	environment_image(t_game *g)
{
	t_img	*img;
	void	*(*f)();

	img = g->chest;
	f = mlx_xpm_file_to_image;
	img[0].img = f(g->m_ptr, "sprites/chest1.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "sprites/chest2.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "sprites/chest3.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "sprites/chest4.xpm", &(img[3].w), &(img[3].h));
	img = g->sprite;
	img[0].img = f(g->m_ptr, "sprites/wall.xpm", &(img[0].w), &(img[0].h));
	img[1].img = f(g->m_ptr, "sprites/floor.xpm", &(img[1].w), &(img[1].h));
	img[2].img = f(g->m_ptr, "sprites/enemy.xpm", &(img[2].w), &(img[2].h));
	img[3].img = f(g->m_ptr, "sprites/c_end.xpm", &(img[3].w), &(img[3].h));
	img[4].img = f(g->m_ptr, "sprites/o_end.xpm", &(img[4].w), &(img[4].h));
}

void	init_game(t_game *g, char *param)
{
	void	*(*f)();

	g->goal = 0;
	g->moves = 99;
	g->frame = 0;
	g->facing = 0;
	g->exit = &g->sprite[3];
	g->m_ptr = mlx_init();
	g->map = read_map(param);
	g->m_win = mlx_new_window(g->m_ptr, g->map.w * BIT, g->map.h * BIT, "S_l");
	environment_image(g);
	chara_image(g);
	map_render(g);
	print_moves(g);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game, argv[1]);
	mlx_key_hook(game.m_win, handle_keys, &game);
	mlx_loop_hook(game.m_ptr, loop_handler, &game);
	mlx_loop(game.m_ptr);
	return (0);
}
