/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:04:18 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/01/28 15:38:11 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Find the position of "chara" in the "string".
 * 
 * @param string 
 * @param chara 
 * @return int Position of "chara" in the "string" or -1 if it hasn't
 * been found.
 */
int	ft_find_chara(char *string, int chara)
{
	int	index;

	index = -1;
	if (!string || !*string)
		return (-1);
	while (string[++index])
	{
		if (string[index] == chara)
			return (index);
	}
	return (-1);
}

/**
 * @brief Returns the length of the string in "string".
 * 
 * @param string 
 * @return int length of string.
 */
int	ft_strlen(char *string)
{
	int	index;

	index = -1;
	if (!string)
		return (-1);
	while (string[++index])
	{	
	}
	return (index);
}

/**
 * @brief Concatenate "string" to "static_buff" by allocating 
 * enough memory fo the two 
 * and moving them to this new memory
 * 
 * @param static_buff 
 * @param string 
 * @return int 1 in case of fail and 0 in case of success.
 */
int	ft_cat(char **static_buff, char **string)
{
	int		dest_len;
	int		src_len;
	char	*dest;
	int		index;
	int		dest_index;

	index = -1;
	src_len = ft_strlen(*static_buff);
	dest_len = src_len + ft_strlen(*string);
	dest = malloc(dest_len + 1);
	if (!dest)
		return (1);
	while (++index < src_len)
		dest[index] = static_buff[0][index];
	ft_free(static_buff);
	dest_index = index;
	index = -1;
	while (dest_index + ++index < dest_len)
		dest[dest_index + index] = string[0][index];
	dest[dest_len] = '\0';
	*static_buff = dest;
	ft_free(string);
	return (0);
}

/**
 * @brief Free a previously allocated pointer.
 * 
 * @param ptr Adress of the pointer to free.
 * @return void* null
 */
char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (0);
}
