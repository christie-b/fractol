# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 14:14:45 by cboutier          #+#    #+#              #
#    Updated: 2021/07/23 10:17:30 by cboutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= srcs

NAMES		= fractol.c fractal_sets.c hooks.c \
				fractol_utils.c fractol_utils2.c \
				colors.c calculations.c mlx_utils.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(NAMES))

INCLUDES	= -Iincl

HEADER		= incl/fractol.h incl/structs.h incl/defines.h

OBJS		= ${SRCS:.c=.o}

NAME		= fractol

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM		= rm -f

MLX_DIR		= ./mlx_linux
MLX_FLAGS	= -lX11 -lXext -lm -lz

.c.o:
		$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $(<:.c=.o)

${NAME}:	${OBJS} ${HEADER}
		${CC} ${CFLAGS} ${OBJS} ${INCLUDES} -L${MLX_DIR} -lmlx ${MLX_FLAGS} -o ${NAME} 

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean
