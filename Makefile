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
RED     = \033[5;31m
GREEN   = \033[5;32m
YELLOW  = \033[5;33m
BLUE    = \033[5;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

# FLAGS AND VARIABLES
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address #-fsanitize=leak
MLXFLAGS = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx_Linux.a

# PROJECT NAME && FOLDERS
NAME = cub3D
NAME_B = cub3D_bonus
SRC =	mandatory/main.c \
		mandatory/errors.c \
		mandatory/map_verification.c \
		mandatory/variable_struct.c \

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# RULES
all: $(NAME)
	echo "$(BLUE).----------------.  .----------------.  .----------------.  .----------------.  .----------------. $(RESET)";
	echo "$(YELLOW)| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |$(RESET)";
	echo "$(WHITE)| |     ______   | || | _____  _____ | || |   ______     | || |    ______    | || |  ________    | |$(RESET)";
	echo "$(CYAN)| |   .' ___  |  | || ||_   _||_   _|| || |  |_   _ \    | || |   / ____ \`.  | || | |_   ___ \`.  | |$(RESET)";
	echo "$(GREEN)| |  / .'   \_|  | || |  | |    | |  | || |    | |_) |   | || |   \`'  __) |  | || |   | |   \`. \ | |$(RESET)";
	echo "$(RED)| |  | |         | || |  | '    ' |  | || |    |  __'.   | || |   _  |__ '.  | || |   | |    | | | |$(RESET)";
	echo "$(PURPLE)| |  \ \`.___.'\  | || |   \ \`--' /   | || |   _| |__) |  | || |  | \____) |  | || |  _| |___.' / | |$(RESET)";
	echo "$(BLUE)| |   \`._____.'  | || |    \`.__.'    | || |  |_______/   | || |   \______.'  | || | |________.'  | |$(RESET)";
	echo "$(YELLOW)| |              | || |              | || |              | || |              | || |              | |$(RESET)";
	echo "$(WHITE)| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |$(RESET)";
	echo "$(RED)'----------------'  '----------------'  '----------------'  '----------------'  '----------------' $(RESET)";
	echo "                                      ";
	echo "$(GREEN)Cub3D is ready to play!$(RESET)"
	@echo "\e[1;33mExecute './cub3D ' and the map config you wish to play!$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@echo "Compiling MiniLibX..."
	@$(MAKE) -C ./minilibx-linux
	@echo "MiniLibX Done!"

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "Instalation Complete!"

$(NAME_B): $(OBJ_B) $(LIBFT) $(MINILIBX)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) $(MLXFLAGS) -o $(NAME_B)
	@echo "Instalation Complete!"

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_B)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)
	$(MAKE) clean -C ./libft

fclean: clean
	@echo "Uninstalling..."
	$(RM) $(NAME) $(OBJDIR)
	$(RM) $(NAME_B) $(OBJDIR_B)
	$(MAKE) fclean -C ./libft
	@echo "Uninstall successful!"

re: fclean all

rb: fclean bonus

.SILENT:

.PHONY: all clean fclean re bonus rb