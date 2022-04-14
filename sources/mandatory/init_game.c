/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:33:56 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 17:12:30 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

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

t_map	get_map_size(char *path)
{
	t_map	map;
	int		file_des;
	char	*reading;

	file_des = open(path, O_RDONLY);
	reading = get_next_line(file_des);
	if (!reading)
		error(2, "");
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
				error(0, reading);
		}
	}
	map.map = malloc(map.h * sizeof(char *));
	close(file_des);
	return (map);
}

void	check_elements(t_map map)
{
	int	index;

	index = -1;
	while (++index < map.w)
		if (map.map[0][index] != '1' || map.map[map.h - 1][index] != '1')
			error(4, "");
	index = -1;
	while (++index < map.h)
		if (map.map[index][0] != '1' || map.map[index][map.w - 1] != '1')
			error(4, "");
}

t_map	read_map(char *path)
{
	t_map	map;
	int		index;
	int		file_des;

	index = -1;
	map = get_map_size(path);
	if (!map.map)
		error(3, "");
	file_des = open(path, O_RDONLY);
	while (++index < map.h)
	{
		map.map[index] = get_next_line(file_des);
		if (!map.map[index])
			free_map_error(map.map, index);
	}
	check_elements(map);
	return (map);
}
