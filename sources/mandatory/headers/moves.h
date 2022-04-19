/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:03:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 14:31:27 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "so_long.h"

void	put_string(t_game *g, char *string, int offset, int id);

void	print_moves(t_game *g);

#endif /* MOVES_H */
