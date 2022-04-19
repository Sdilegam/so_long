/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:11:39 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 16:11:40 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "so_long.h"

void	update(t_game *g);

int		loop_handler(t_game *g);

int		handle_keys(int key, void *game);

#endif /* HANDLERS_H */
