# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeham <yeham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:29:59 by yeham             #+#    #+#              #
#    Updated: 2022/10/28 19:56:54 by yeham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fractal.c mandelbrot.c julia.c mlx_utils.c ft_atod.c
REAL_SRCS = $(addprefix mandatory/, $(SRCS))

BO_SRCS = fractal_bonus.c burningship_bonus.c mlx_utils_bonus.c
REAL_BO_SRCS = $(addprefix bonus/, $(BO_SRCS))

OBJS = $(REAL_SRCS:%.c=%.o)

BO_OBJS = $(REAL_BO_SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit

ifdef WITH_BONUS
	OBJ_FILE = $(BO_OBJS)
else
	OBJ_FILE = $(OBJS)
endif

all : $(NAME)

$(NAME): $(OBJ_FILE)
	cc $(CFLAGS) $(CLIB) $(OBJ_FILE) -o $(NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(BO_OBJS)

fclean :
	make clean
	rm -f $(NAME)

re : 
	make fclean
	make all

bonus:
	@make WITH_BONUS=1 all

.PHONY : all clean fclean re bonus
