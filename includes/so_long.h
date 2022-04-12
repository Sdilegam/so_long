/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:43 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/12 19:35:11 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BIT 16

# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_img {
	void	*img;
	int		w;
	int		h;	
}	t_img;

typedef struct s_map {
	int		w;
	int		h;
	char	**map;
}	t_map;
typedef struct s_coord
{
	int	x;
	int	y;
	int	e_x;
	int	e_y;
	int	b_x;
	int	b_y;
}	t_coord;

typedef struct s_game
{
	t_coord	coord;
	t_map	map;
	t_img	chest[4];
	t_img	sprite[5];
	t_img	chara[4][4];
	void	*m_ptr;
	void	*m_win;
	int		moves;
	int		facing;
	int		goal;
	int		frame;
	int		last_moved[2];
}	t_game;
#endif
