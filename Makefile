# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/05/02 18:22:00 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[48;5;196m
SKIN = \033[0m\033[48;5;223m
BROWN = \033[48;5;88m
BLUE = \033[48;5;21m
YELLOW = \033[48;5;226m
END = \033[0m

NAME = fractol
FLAG = -Ofast -Wall -Werror -Wextra
FRAMEWORK = -framework OpenGL -framework AppKit
OBJS = ./main.o ./print_point.o ./key_hook.o ./error.o ./init.o ./fractal.o \
	   ./key_hook_julia.o ./key_hook_mandelbrot.o
LFT = -L./libft/ -lft
LMLX = -L./minilibx_macos/ -lmlx
HEAD = -I ./includes/fdf.h

VPATH = sources/

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[33mCompiling libft.a ...\033[0m"
	@make -s -C ./libft/
	@echo "\033[32mCompiling libft.a done !\033[0m"
	@echo "\033[33mCompiling mlx.a ...\033[0m"
	@make -s -C ./minilibx_macos/
	@echo "\033[32mCompiling mlx.a done !\033[0m"
	@echo "\033[33mCompiling in .o ...\033[0m"
	@echo "\033[32mCompiling in .o done !\033[0m"
	@echo "\033[33mCompiling fdf ...\033[0m"
	@gcc $(FLAG) -o $(NAME) $(OBJS) $(LMLX) $(LFT) $(FRAMEWORK)
	@echo "\033[32mCompiling fdf done !\033[0m"

%.o : %.c 
		@gcc -c $(FLAG) $(HEAD) $< -o $@

clean:
	@echo "\033[31mdeleting all .o ...\033[0m"
	@rm -f $(OBJS)
	@echo "\033[32mThe folder is clean !\033[0m"

fclean:
	@echo "\033[31mDeleting libft.a and all .o ...\033[0m"
	@rm -f $(NAME) $(OBJS)
	@echo "\033[32mThe folder is clean\033[0m"
	@make -s fclean -C ./libft/
	@make -s clean -C ./minilibx_macos/

re: fclean all
