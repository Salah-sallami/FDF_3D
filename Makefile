# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 11:03:50 by ssallami          #+#    #+#              #
#    Updated: 2025/04/03 15:36:34 by ssallami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -rf

MLX_LIB     =	-L minilibx/ -lmlx
FRAMEWORKS  =	-framework OpenGL -framework AppKit
INCLUDES    =	-I minilibx/

SRCS		=	fdf.c srcs/alg_utils.c srcs/controls.c srcs/mouse.c srcs/keyboard.c srcs/draw.c srcs/line_alg.c srcs/project.c srcs/parse_map.c srcs/utils.c \
				get_next_line/get_next_line.c \
				libft/ft_strjoin.c libft/ft_bzero.c libft/ft_split.c libft/ft_atoi.c libft/ft_putendl_fd.c \
				libft/ft_strlen.c libft/ft_isdigit.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_atoi_base.c \
				libft/ft_strncmp.c libft/ft_toupper.c


OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C minilibx/ all
				@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(FRAMEWORKS)  -o $(NAME)



%.o: %.c fdf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make -C minilibx/ clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all