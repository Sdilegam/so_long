/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:25:47 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:10:22 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_GAME_BONUS_H
# define END_GAME_BONUS_H

# include "so_long_bonus.h"

void	finish_game(t_game *g, char tile);

void	free_map(t_map map);

void	clean_exit(t_game *g);

int		close_game(t_game *g);

#endif /* END_GAME__BONUS_H */
