# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 18:25:09 by jofilipe          #+#    #+#              #
#    Updated: 2024/05/20 18:25:10 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror -g
LIBXFLAGS	= -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBFTFLAGS	= -L ./libft -lft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes
SRCS		= mandatory
LIBFT		= libft
LIBX 		= minilibx-linux

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
SRC				= mandatory/main.c \ mandatory/variable_struct.c \
OBJS 			:= $(SRC:.c=.o)
NAME			= cub3d
TARGET			= $(addprefix $(SRCS)/, $(OBJS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	make $(MKFLAGS) -C $(LIBFT)
	make all -C $(LIBX)
	$(CC) $(CFLAGS) $(TARGET) $(LIBFTFLAGS) $(LIBXFLAGS) -o $(NAME)
	clear
	echo "$(BLUE) .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ";
	echo "$(YELLOW)| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
	echo "$(WHITE)| |     ______   | || | _____  _____ | || |   ______     | || |    ______    | || |  ________    | |";
	echo "$(CYAN)| |   .' ___  |  | || ||_   _||_   _|| || |  |_   _ \    | || |   / ____ \`.  | || | |_   ___ \`.  | |";
	echo "$(GREEN)| |  / .'   \_|  | || |  | |    | |  | || |    | |_) |   | || |   \`'  __) |  | || |   | |   \`. \ | |";
	echo "$(RED)| |  | |         | || |  | '    ' |  | || |    |  __'.   | || |   _  |__ '.  | || |   | |    | | | |";
	echo "$(PURPLE)| |  \ \`.___.'\  | || |   \ \`--' /   | || |   _| |__) |  | || |  | \____) |  | || |  _| |___.' / | |";
	echo "$(BLUE)| |   \`._____.'  | || |    \`.__.'    | || |  |_______/   | || |   \______.'  | || | |________.'  | |";
	echo "$(YELLOW)| |              | || |              | || |              | || |              | || |              | |";
	echo "$(WHITE)| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
	echo "$(RED) '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
	echo "                                      ";
	echo "$(GREEN)Cub3D is ready to play!$(RESET)"
	echo "$(BLUE)Execute with a map to start!$(RESET)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	make clean -C $(LIBX)
	$(RM) $(TARGET)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.SILENT: