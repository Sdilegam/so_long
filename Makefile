# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/04/11 17:49:22 by sdi-lega         ###   ########.fr        #
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
#									#
#			Sources & objects		#
#									#
#####################################

SOURCES			=	${NAME}.c get_next_line.c get_next_line_utils.c#Files to compile#
OBJECTS 		=	${addprefix ${OBJECTS_DIR}, ${SOURCES:.c=.o}}
DEPENDS			=	${OBJECTS:.o=.d}
LIBRARIES		=	mlx/libmlx.dylib
EXECUTABLES		=	${NAME} #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC				=	gcc
CC_FLAGS		=	-Iincludes ${addprefix -I, ${LIB_DIR}${dir ${LIBRARIES}}}# -Wall -Werror -Wextra
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
${NAME}:			mandatory
re:					fclean all

mandatory:			${OBJECTS_DIR} ${EXECUTABLES}
bonus:				
			#Bonus rule 

#####################################
#									#
#				COMPILING			#
#									#
#####################################

${OBJECTS_DIR}%.o:	${addprefix ${SOURCES_DIR}${SUB_DIR}, %.c}
			${SILENT} echo  "\033[K\rCreating \"${@F:.c=.o}\".\c"
			${SILENT}${CC} ${CC_FLAGS} -MMD -c $< -o ${OBJECTS_DIR}${@F:.c=.o}
			${SILENT} sleep ${SLEEP_TIME}

${LIB_DIR}${LIBRARIES}:		
			${SILENT} make -C $(@D)

${EXECUTABLES}:		${OBJECTS} ${addprefix ${LIB_DIR}, ${LIBRARIES}}
			${SILENT} echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${addprefix -L, ${LIB_DIR}${dir ${LIBRARIES}}} ${addprefix -l, ${patsubst lib%.dylib, %, ${notdir ${LIBRARIES}}}} -framework OpenGL -framework AppKit $? -o $@
			${SILENT} sleep ${SLEEP_TIME}

			
-include ${DEPENDS}

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean:

			${SILENT} echo "\rRemoving objects files (${notdir ${OBJECTS}}).\033[K\c"
			${SILENT} ${RM} ${OBJECTS}
			${SILENT} sleep ${SLEEP_TIME}

clean_bonus:

			#${SILENT} echo "\rSwitching to bonus files.\033[K\c"
			#${SILENT} make clean SUFFIX=_bonus SUB_DIR=bonus/
			#${SILENT} make clean_exe SUFFIX=_bonus SUB_DIR=bonus/

clean_libs:

			${SILENT} echo "\rRemoving libraries (${notdir ${LIBRARIES}}).\033[K\c"
			${SILENT} make clean -C ${addprefix ${LIB_DIR}, ${dir ${LIBRARIES}}}
			${SILENT} sleep ${SLEEP_TIME}

clean_exe:

			${SILENT} echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES} ${EXECUTABLES}
			${SILENT} sleep ${SLEEP_TIME}

fclean:			clean clean_libs clean_exe clean_bonus
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

