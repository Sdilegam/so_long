/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:43 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/14 14:45:35 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BIT 16

# include "ft_printf.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "type_definitions.h"
# include "end_game.h"
# include "enemies.h"
# include "errors.h"
# include "ft_itoa.h"
# include "handlers.h"
# include "init_game.h"
# include "player_movements.h"
# include "so_long_utils.h"
# include "visual.h"
# include "get_next_line.h"

void	finish_game(t_game *g, char tile);

void	clean_exit(t_game *g);

void	put_string(t_game *g, char *string, int offset);

void	print_moves(t_game *g);

#endif
