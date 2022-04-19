/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:10:38 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:10:39 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_BONUS_H
# define HANDLERS_BONUS_H

# include "so_long_bonus.h"

void	update(t_game *g);

int		loop_handler(t_game *g);

int		handle_keys(int key, void *game);

#endif /* HANDLERS_BONUS_H */
