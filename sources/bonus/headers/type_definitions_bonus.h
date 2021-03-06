/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_definitions_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:59:33 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:10:00 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_DEFINITIONS_BONUS_H
# define TYPE_DEFINITIONS_BONUS_H
# include "so_long_bonus.h"

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
}	t_coord;

typedef struct s_game
{
	long int	moves;
	t_coord		coord;
	t_map		map;
	t_img		chest[4];
	t_img		sprite[5];
	t_img		chara[4][4];
	t_img		*exit;
	void		*m_ptr;
	void		*m_win;
	int			w_size[4];
	int			last_moved[2];
	int			facing;
	int			goal;
	int			frame;
}	t_game;
#endif /* TYPE_DEFINITIONS_BONUS_H */
