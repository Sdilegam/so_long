# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/04/18 17:06:08 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME			=	so_long

#####################################
#									#
#			Directories				#
#									#
#####################################

SOURCES_DIR		=	sources/
SUB_DIR			=	mandatory/
OBJECTS_DIR		=	${SOURCES_DIR}${SUB_DIR}objects/
LIB_DIR			=	libraries/

#####################################
#									#ƒ
#			Sources & objects		#
#									#
#####################################

SOURCES			=	\
					end_game.c \
					enemies.c \
					errors.c \
					ft_itoa.c \
					handlers.c \
					init_game.c \
					moves_bonus.c \
					player_movements.c \
					so_long.c \
					so_long_utils.c \
					visual.c
					
OBJECTS 		=	${addprefix ${OBJECTS_DIR}, ${SOURCES:.c=.o}}
DEPENDS			=	${OBJECTS:.o=.d}
LIBRARIES		=	gnl/libgnl.a ft_printf/libprintf.a
EXECUTABLES		=	${NAME} #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC				=	gcc
CC_FLAGS		=	-Iincludes ${addprefix -I, ${addprefix ${LIB_DIR},${dir ${LIBRARIES}}}} -Wall -Werror -Wextra
RM				=	rm -f
SLEEP_TIME		=	0.2
SILENT			=	@


################################################################################
#																			   #
#										RULES								   #
#																			   #
################################################################################

#####################################
#									#
#				GENERAL				#
#									#
#####################################

all:				mandatory bonus
re:					fclean all

mandatory:			${NAME}
bonus:				

#####################################
#									#
#				COMPILING			#
#									#
#####################################

${OBJECTS_DIR}%.o:	${addprefix ${SOURCES_DIR}${SUB_DIR}, %.c}
			${SILENT} echo  "\rCreating \"${@F:.c=.o}\".\033[K\c"
			${SILENT} ${CC} ${CC_FLAGS} -MMD -c $< -o ${OBJECTS_DIR}${@F:.c=.o} -g
			${SILENT} sleep ${SLEEP_TIME}

${addprefix ${LIB_DIR}, ${LIBRARIES}}:		
			${SILENT} echo  "\rCreating \"${notdir $@}\".\033[K\c"
			${SILENT} make -sC $(@D)
			${SILENT} echo "\rLibrary \"${notdir $@}\" created\033[K"

${NAME}:		${OBJECTS_DIR} ${addprefix ${LIB_DIR}, ${LIBRARIES}} ${OBJECTS}
			${SILENT} echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} -lmlx ${addprefix -L, ${addprefix ${LIB_DIR},${dir ${LIBRARIES}}}} ${addprefix -l, ${patsubst lib%.a, %, ${notdir ${LIBRARIES}}}} -framework OpenGL -framework AppKit ${OBJECTS} -o $@ -g
			${SILENT} sleep ${SLEEP_TIME}

			
-include ${DEPENDS}

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean:
			${SILENT} echo "\rRemoving objects files (${notdir ${OBJECTS}}).\033[K\c"
			${SILENT} ${RM} ${OBJECTS} ${DEPENDS}
			${SILENT} sleep ${SLEEP_TIME}

clean_bonus:
			#${SILENT} echo "\rSwitching to bonus files.\033[K\c"
			#${SILENT} make clean SUFFIX=_bonus SUB_DIR=bonus/
			#${SILENT} make clean_exe SUFFIX=_bonus SUB_DIR=bonus/

${addprefix clean_,${dir ${LIBRARIES}}}:
			${SILENT} echo "\rRemoving libraries (${patsubst clean_%,%, $@}).\033[K\c"
			${SILENT}make clean -sC ${patsubst clean_%, libraries/%, $@}
			${SILENT} sleep ${SLEEP_TIME}

clean_exe:
			${SILENT} echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES}
			${SILENT} sleep ${SLEEP_TIME}

fclean:			clean ${addprefix clean_,${dir ${LIBRARIES}}} clean_exe #clean_bonus
			${SILENT} echo "\rEverything removed.\033[K"
				
#####################################
#									#
#			INITIALIZATION			#
#									#
#####################################

${OBJECTS_DIR}:
			mkdir ${OBJECTS_DIR}

start:				
			${SILENT} mkdir -p sources/mandatory/objects
			${SILENT} mkdir -p sources/bonus/objects
			${SILENT} mkdir -p includes
			${SILENT} mkdir -p libraries
			${SILENT} touch -a ${addprefix ${SOURCES_DIR}${SUB_DIR}, ${SOURCES}}
			${SILENT} touch -a includes/${NAME}.h

.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 

