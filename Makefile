# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/05/05 19:37:08 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[48;5;196m
SKIN = \033[0m\033[48;5;223m
BROWN = \033[48;5;88m
BLUE = \033[48;5;21m
YELLOW = \033[48;5;226m
GREEN = \033[38;5;10m
GREY = \033[38;5;242m
CYAN = \033[38;5;87m
END = \033[0m

NAME = fractol
FLAG = -Wall -Werror -Wextra
FRAMEWORK = -Ofast -framework OpenGL -framework AppKit
OBJS = ./main.o ./print_point.o ./key_hook.o ./error.o ./init.o ./fractal.o \
		./key_hook_fractal_1.o ./init_event.o ./loop_fractal.o ./mouse_hook.o

INCLUDE = $(wildcard ./includes/fractol.h ./includes/keyboard.h)

LFT = -L./libft/ -lft
LMLX = -L./minilibx_macos/ -lmlx

VPATH = sources/

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(CYAN)Compiling libft.a ...$(CYAN)"
	@make -s -C ./libft/
	@printf "           [$(GREEN)Success$(CYAN)]\n"
	@printf "Compiling mlx.a ..."
	@make -s -C ./minilibx_macos/
	@printf "             [$(GREEN)Success$(CYAN)]\n"
	@printf "Compiling .o ..."
	@printf "                [$(GREEN)Success$(CYAN)]\n"
	@printf "Compiling Fractol ..."
	@gcc $(FLAG) -o $(NAME) $(OBJS) $(LMLX) $(LFT) $(FRAMEWORK)
	@printf "           [$(GREEN)Success$(CYAN)]\n$(END)"

%.o : %.c ${INCLUDE}
		@gcc -c $(FLAG) $< -o $@

clean:
	@printf "$(CYAN)deleting all .o ..."
	@rm -f $(OBJS)
	@printf " [$(GREEN)Success$(CYAN)]\n$(END)"

fclean:
	@printf "$(CYAN)Deleting libft.a and all .o ..."
	@rm -f $(NAME) $(OBJS)
	@make -s fclean -C ./libft/
	@make -s clean -C ./minilibx_macos/
	@printf " [$(GREEN)Success$(CYAN)]\n$(END)"

re: fclean all
