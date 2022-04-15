/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:14:38 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/15 11:44:20 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "so_long.h"

void	put_itow(t_game *g, int x, int y, t_img sprite);

void	put_img(t_game *g, int x, int y);
void	frame_render(t_game *g);
void	update(t_game *g);

#endif /* VISUAL_H */
