# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 14:30:28 by sdi-lega          #+#    #+#              #
#    Updated: 2022/04/13 14:03:22 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libprintf.a

SRCS 		= ft_convert_char.c ft_convert_hexa.c ft_convert_nbr.c ft_convert_ptr.c ft_convert_str.c ft_convert_unsigned.c ft_printf.c utils/number_utils.c utils/string_utils.c utils/utils.c

OBJS 		= ${SRCS:.c=.o}

CC			= gcc

FLAGS		= -I. -Wextra -Werror -Wall -MMD

RM			= rm -f

DEPENDS	=	${OBJS:.o=.d}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}
			
bonus:		${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${DEPENDS} ${NAME}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

list:
			ar -t ${NAME}
			
.PHONY:		all clean fclean re bonus list

-include ${DEPENDS}
