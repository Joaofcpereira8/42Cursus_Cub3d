# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 15:23:36 by jofilipe          #+#    #+#              #
#    Updated: 2024/05/21 15:23:37 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[5;32m
YELLOW  = \033[5;33m
BLUE    = \033[5;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

# FLAGS AND VARIABLES
NAME = cub3D

CC = cc -g
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS =	mandatory/main.c \
		mandatory/errors.c \
		mandatory/map_verification.c \
		mandatory/variable_struct.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)
	clear
	@echo "$(BLUE).----------------.  .----------------.  .----------------.  .----------------.  .----------------. $(RESET)";
	@echo "$(YELLOW)| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |$(RESET)";
	@echo "$(WHITE)| |     ______   | || | _____  _____ | || |   ______     | || |    ______    | || |  ________    | |$(RESET)";
	@echo "$(CYAN)| |   .' ___  |  | || ||_   _||_   _|| || |  |_   _ \    | || |   / ____ \`.  | || | |_   ___ \`.  | |$(RESET)";
	@echo "$(GREEN)| |  / .'   \_|  | || |  | |    | |  | || |    | |_) |   | || |   \`'  __) |  | || |   | |   \`. \ | |$(RESET)";
	@echo "$(RED)| |  | |         | || |  | '    ' |  | || |    |  __'.   | || |   _  |__ '.  | || |   | |    | | | |$(RESET)";
	@echo "$(PURPLE)| |  \ \`.___.'\  | || |   \ \`--' /   | || |   _| |__) |  | || |  | \____) |  | || |  _| |___.' / | |$(RESET)";
	@echo "$(BLUE)| |   \`._____.'  | || |    \`.__.'    | || |  |_______/   | || |   \______.'  | || | |________.'  | |$(RESET)";
	@echo "$(YELLOW)| |              | || |              | || |              | || |              | || |              | |$(RESET)";
	@echo "$(WHITE)| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |$(RESET)";
	@echo "$(RED)'----------------'  '----------------'  '----------------'  '----------------'  '----------------' $(RESET)";
	@echo "                                      ";
	@echo "$(GREEN)Cub3D is ready to play!$(RESET)"
	@echo "$(BLUE)Execute './cub3D ' and the map config you wish to play!$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME) -lm

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@echo "$(RED)Object and Executable files have been deleted!$(RESET)"

re: fclean all

.SILENT: