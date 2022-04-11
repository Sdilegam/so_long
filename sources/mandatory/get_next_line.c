/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:45:15 by sdi-lega          #+#    #+#             */
/*   Updated: 2021/12/22 09:45:15 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Get the next line out of a file descriptor
 * 
 * @param file_des 
 * @return char* the next line
 */
char	*get_next_line(int file_des)
{
	static char	*buffer = 0;
	char		*buffer_text;
	int			found;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (0);
	found = ft_find_chara(buffer, '\n');
	while (found == -1)
	{
		buffer_text = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer_text)
			return (0);
		if (0 >= read(file_des, buffer_text, BUFFER_SIZE))
		{
			ft_free(&buffer_text);
			break ;
		}
		found = ft_find_chara(buffer_text, '\n');
		ft_cat(&buffer, &buffer_text);
	}
	if (!*buffer)
		return (ft_free(&buffer));
	return (ft_return(&buffer));
}

/**
 * @brief Return everything before a newline characters and deletes
 * this part in the static variable.
 * 
 * @param string the static variable containing everything that
 * has been read so far.
 * @return char* the next line.
 */
char	*ft_return(char **string)
{
	int		len;
	char	*answer;
	int		index;

	index = -1;
	len = ft_find_chara(*string, '\n') + 1;
	if (len == 0)
		len = ft_strlen(*string);
	answer = malloc (len + 1);
	if (!answer)
		return (0);
	while (++index <= len)
		answer[index] = string[0][index];
	answer[--index] = '\0';
	while (string[0][index])
	{
		string[0][index - len] = string[0][index];
		index ++;
	}
	string[0][index - len] = '\0';
	return (answer);
}

/**
 * @brief Allocate memory for "number" elements of "size" and fill it with 0s;
 * 
 * @param number Number of elements
 * @param size size of each elements
 * @return void* a pointer to te memory allocated.
 */
void	*ft_calloc(int number, int size)
{
	void	*pointer;
	int		index;

	index = -1;
	pointer = malloc(number * size);
	if (!pointer)
		return (0);
	while (++index < number * size)
		((char *)pointer)[index] = 0;
	return (pointer);
}
