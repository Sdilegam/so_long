# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/04/13 19:35:09 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME			=	libgnl.a

#####################################
#									#
#			Directories				#
#									#
#####################################

SOURCES_DIR		=	./
OBJECTS_DIR		=	objects/

#####################################
#									#ƒ
#			Sources & objects		#
#									#
#####################################

SOURCES			=	get_next_line.c get_next_line_utils.c
OBJECTS 		=	${addprefix ${OBJECTS_DIR}, ${SOURCES:.c=.o}}
DEPENDS			=	${OBJECTS:.o=.d}
EXECUTABLES		=	${NAME} #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
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

all:				mandatory
re:					fclean all

mandatory:			${NAME}

#####################################
#									#
#				COMPILING			#
#									#
#####################################

${OBJECTS_DIR}%.o:	${addprefix ${SOURCES_DIR}, %.c}
			${SILENT} echo  "\rCreating \"${@F:.c=.o}\".\033[K\c"
			${SILENT}${CC} ${CC_FLAGS} -MMD -c $< -o ${OBJECTS_DIR}${@F:.c=.o}
			${SILENT} sleep ${SLEEP_TIME}

${NAME}:		${OBJECTS_DIR} ${OBJECTS}
			${SILENT} echo "\r\"$@\" library created\033[K"
			${SILENT} ar -r $@ ${OBJECTS}
			${SILENT} sleep ${SLEEP_TIME}

			
-include ${DEPENDS}

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean: clean_lib

			${SILENT} echo "\rRemoving objects files (${notdir ${OBJECTS}}).\033[K\c"
			${SILENT} ${RM} ${OBJECTS} ${DEPENDS}
			${SILENT} sleep ${SLEEP_TIME}

clean_lib:

			${SILENT} echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES}
			${SILENT} sleep ${SLEEP_TIME}

fclean:			clean clean_lib
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

