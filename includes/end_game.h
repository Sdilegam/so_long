/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:25:47 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/15 16:16:59 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_GAME_H
# define END_GAME_H

# include "so_long.h"

void	finish_game(t_game *g, char tile);

void	free_map(t_map map);

void	clean_exit(t_game *g);

int	close_game(t_game *g);
#endif
