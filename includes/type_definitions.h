/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_definitions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:59:33 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 14:34:29 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_DEFINITIONS_H
# define TYPE_DEFINITIONS_H
# include "so_long.h"

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
	t_coord		coord;
	t_map		map;
	t_img		chest[4];
	t_img		sprite[5];
	t_img		chara[4][4];
	t_img		*exit;
	void		*m_ptr;
	void		*m_win;
	long int	moves;
	int			facing;
	int			goal;
	int			frame;
	int			last_moved[2];
}	t_game;
#endif /* TYPE_DEFINITIONS_H */
