/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:43 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:10:00 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define BIT 16

# include "ft_printf.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "type_definitions_bonus.h"
# include "end_game_bonus.h"
# include "enemies_bonus.h"
# include "errors_bonus.h"
# include "ft_itoa_bonus.h"
# include "handlers_bonus.h"
# include "init_game_bonus.h"
# include "moves_bonus.h"
# include "player_movements_bonus.h"
# include "so_long_utils_bonus.h"
# include "visual_bonus.h"
# include "get_next_line.h"

void	finish_game(t_game *g, char tile);

void	clean_exit(t_game *g);

void	put_string(t_game *g, char *string, int offset, int id);

void	print_moves(t_game *g);

#endif
