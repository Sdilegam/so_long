/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:45:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/02/03 23:00:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int file_des);
char	*ft_return(char **string);
int		ft_strlen(char *string);
int		ft_find_chara(char *string, int chara);
int		ft_cat(char **static_buff, char **string);
char	*ft_free(char **ptr);
void	*ft_calloc(int number, int size);
#endif