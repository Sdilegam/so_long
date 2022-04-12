/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:43 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/12 04:47:17 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int x;
	int y;
	int e_x;
	int e_y;
}	t_coord;


typedef struct	s_game {
	void	*m_ptr;
	void	*m_win;
	t_map	map;
	t_img	sprite[6];
	t_img	chara[4][4];
	int		moves;
	int		facing;
	int		chest;
	t_coord	coord;
	int		frame;
}				t_game;
#endif