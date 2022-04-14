#ifndef HANDLERS_H
# define HANDLERS_H

# include "so_long.h"

void	update(t_game *g);

int		loop_handler(t_game *g);

int		handle_keys(int key, void *game);

#endif /* HANDLERS_H */
