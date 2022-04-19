# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/04/19 16:49:05 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLESe								   #
#																			   #
################################################################################

NAME			=	so_long

#####################################
#									#
#			Directories				#
#									#
#####################################


MANDATORY_DIR		=	sources/mandatory/
BONUS_DIR			=	sources/bonus/
OBJECTS_DIR			=	${MANDATORY_DIR}objects/
BONUS_OBJECTS_DIR	=	${BONUS_DIR}objects/
LIB_DIR				=	libraries/

#####################################
#									#
#			Sources & objects		#
#									#
#####################################

SOURCES			=	\
					end_game.c \
					errors.c \
					ft_itoa.c \
					handlers.c \
					init_game.c \
					moves.c \
					player_movements.c \
					so_long.c \
					so_long_utils.c \
					visual.c
					

BONUS_SOURCES	=	\
					end_game_bonus.c \
					enemies_bonus.c \
					errors_bonus.c \
					ft_itoa_bonus.c \
					handlers_bonus.c \
					init_game_bonus.c \
					moves_bonus.c \
					player_movements_bonus.c \
					so_long_bonus.c \
					so_long_utils_bonus.c \
					visual_bonus.c
					
OBJECTS			=	${addprefix ${OBJECTS_DIR}, ${SOURCES:.c=.o}}
BONUS_OBJECTS	=	${addprefix ${BONUS_OBJECTS_DIR}, ${BONUS_SOURCES:.c=.o}}
DEPENDS			=	${OBJECTS:.o=.d} ${BONUS_OBJECTS:.o=.d}
LIBRARIES		=	gnl/libgnl.a ft_printf/libprintf.a
EXECUTABLES		=	${NAME} ${NAME}_bonus #Modify if other executables needed#

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
bonus:				${NAME}_bonus

#####################################
#									#
#				COMPILING			#
#									#
#####################################

${OBJECTS_DIR}%.o:	${addprefix ${MANDATORY_DIR}, %.c}
			${SILENT} echo  "\rCreating \"${@F:.c=.o}\".\033[K\c"
			${SILENT} ${CC} -I${MANDATORY_DIR}headers/ ${CC_FLAGS} -MMD -c $< -o ${OBJECTS_DIR}${@F:.c=.o} -g
			${SILENT} sleep ${SLEEP_TIME}
			
${BONUS_OBJECTS_DIR}%.o:	${addprefix ${BONUS_DIR}, %.c}
			${SILENT} echo  "\rCreating \"${@F:.c=.o}\".\033[K\c"
			${SILENT} ${CC} -I${BONUS_DIR}headers/ ${CC_FLAGS} -MMD -c $< -o ${BONUS_OBJECTS_DIR}${@F:.c=.o} -g
			${SILENT} sleep ${SLEEP_TIME}

${addprefix ${LIB_DIR}, ${LIBRARIES}}:		
			${SILENT} echo  "\rCreating \"${notdir $@}\".\033[K\c"
			${SILENT} make -sC $(@D)
			${SILENT} echo "\rLibrary \"${notdir $@}\" created\033[K"

${NAME}:		${OBJECTS_DIR} ${addprefix ${LIB_DIR}, ${LIBRARIES}} ${OBJECTS}
			${SILENT} echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} -lmlx ${addprefix -L, ${addprefix ${LIB_DIR},${dir ${LIBRARIES}}}} ${addprefix -l, ${patsubst lib%.a, %, ${notdir ${LIBRARIES}}}} -framework OpenGL -framework AppKit ${OBJECTS} -o $@ -g
			${SILENT} sleep ${SLEEP_TIME}
${NAME}_bonus:		${BONUS_OBJECTS_DIR} ${addprefix ${LIB_DIR}, ${LIBRARIES}} ${BONUS_OBJECTS}
			${SILENT} echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} -lmlx ${addprefix -L, ${addprefix ${LIB_DIR},${dir ${LIBRARIES}}}} ${addprefix -l, ${patsubst lib%.a, %, ${notdir ${LIBRARIES}}}} -framework OpenGL -framework AppKit ${BONUS_OBJECTS} -o $@ -g
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
			${SILENT} echo "\rRemoving bonnus objects files (${notdir ${BONUS_OBJECTS}}).\033[K\c"
			${SILENT} ${RM} ${BONUS_OBJECTS} ${DEPENDS}
			${SILENT} sleep ${SLEEP_TIME}

${addprefix clean_,${dir ${LIBRARIES}}}:
			${SILENT} echo "\rRemoving libraries (${patsubst clean_%,%, $@}).\033[K\c"
			${SILENT} make clean -sC ${patsubst clean_%, libraries/%, $@}
			${SILENT} sleep ${SLEEP_TIME}

clean_exe:
			${SILENT} echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES}
			${SILENT} sleep ${SLEEP_TIME}

fclean:			clean ${addprefix clean_,${dir ${LIBRARIES}}} clean_exe clean_bonus
			${SILENT} echo "\rEverything removed.\033[K"
				
#####################################
#									#
#			INITIALIZATION			#
#									#
#####################################

${OBJECTS_DIR}:
			mkdir ${OBJECTS_DIR}
${BONUS_OBJECTS_DIR}:
			mkdir ${BONUS_OBJECTS_DIR}

start:				
			${SILENT} mkdir -p sources/mandatory/objects
			${SILENT} mkdir -p sources/bonus/objects
			${SILENT} mkdir -p libraries
			${SILENT} touch -a ${addprefix ${SOURCES_DIR}${SUB_DIR}, ${SOURCES}}
			${SILENT} touch -a includes/${NAME}.h

.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 

