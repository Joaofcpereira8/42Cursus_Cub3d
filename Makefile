# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 15:23:36 by jofilipe          #+#    #+#              #
#    Updated: 2024/05/21 18:33:37 by bbento-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
REDBL   = \033[5;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
BLUEBL  = \033[5;34m
IBLUE  = \033[5;34;7m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m
IWHITE   = \033[1;37;7m
BLINK   = \033[5m
ENDBL   = \033[25m

# FLAGS AND VARIABLES
NAME = cub3D

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g
MFLAGS = -lX11 -lXext

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS =	mandatory/main.c \
		mandatory/errors.c \
		mandatory/map_verification.c \
		mandatory/map_verification2.c \
		mandatory/file_verification.c \
		mandatory/variable_struct.c \
		mandatory/init.c \
		mandatory/map_parsing.c \
		mandatory/utils.c \
		mandatory/free.c \
		mandatory/start.c \
		mandatory/prog_info.c \
		mandatory/image.c \
		mandatory/calcs.c \
		mandatory/calcs2.c \
		mandatory/plr_mov.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)
	clear
	echo "$(BLUEBL).------------------..------------------..------------------..------------------..------------------. $(RESET)";
	echo "$(BLUEBL)|$(ENDBL)$(YELLOW) .--------------. $(BLINK)||$(ENDBL) .--------------. $(BLINK)||$(ENDBL) .--------------. $(BLINK)|| .--------------. || .--------------. $(BLUEBL)|$(ENDBL)$(RESET)";
	echo "$(BLUEBL)|$(ENDBL)$(WHITE) |     ______   | $(BLINK)||$(ENDBL) | _____  _____ | $(BLINK)||$(ENDBL) |   ______     | $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)    ______    $(BLINK)|$(ENDBL) $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)  ________    $(BLINK)|$(ENDBL) $(BLUEBL)|$(ENDBL)$(RESET)";
	echo "$(BLUEBL)|$(ENDBL)$(CYAN) |   .' ___  |  | $(BLINK)||$(ENDBL) ||_   _||_   _|| $(BLINK)||$(ENDBL) |  |_   _ \    | $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)   / ____ \`.  $(BLINK)|$(ENDBL) $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL) |_   ___ \`.  $(BLINK)|$(ENDBL) $(BLUEBL)|$(ENDBL)$(RESET)";
	echo "$(BLUEBL)|$(ENDBL)$(GREEN) |  / .'   \_|  | $(BLINK)||$(ENDBL) |  | |    | |  | $(BLINK)||$(ENDBL) |    | |_) |   | $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)   \`'  __) |  $(BLINK)|$(ENDBL) $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)   | |   \`. \ $(BLINK)|$(ENDBL) $(BLUEBL)|$(ENDBL)$(RESET)";
	echo "$(REDBL)|$(ENDBL)$(RED) |  | |         | $(BLINK)||$(ENDBL) |  | '    ' |  | $(BLINK)||$(ENDBL) |    |  __'.   | $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)   _  |__ '.  $(BLINK)|$(ENDBL) $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)   | |    | | $(BLINK)|$(ENDBL) $(BLUEBL)|$(ENDBL)$(RESET)";
	echo "$(REDBL)|$(ENDBL)$(PURPLE) |  \ \`.___.'\  | $(BLINK)||$(ENDBL) |   \ \`--' /   | $(BLINK)||$(ENDBL) |   _| |__) |  | $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)  | \____) |  $(BLINK)|$(ENDBL) $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)  _| |___.' / $(BLINK)|$(ENDBL) $(REDBL)|$(ENDBL)$(RESET)";
	echo "$(REDBL)|$(ENDBL)$(BLUE) |   \`._____.'  | $(BLINK)||$(ENDBL) |    \`.__.'    | $(BLINK)||$(ENDBL) |  |_______/   | $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL)   \______.'  $(BLINK)|$(ENDBL) $(BLINK)||$(ENDBL) $(BLINK)|$(ENDBL) |________.'  $(BLINK)|$(ENDBL) $(REDBL)|$(ENDBL)$(RESET)";
	echo "$(REDBL)|$(ENDBL)$(YELLOW) |              | $(BLINK)||$(ENDBL) |              | $(BLINK)||$(ENDBL) |              | $(BLINK)|| |              | $(BLINK)|| |              | $(REDBL)|$(ENDBL)$(RESET)";
	echo "$(REDBL)|$(ENDBL)$(WHITE) '--------------' $(BLINK)||$(ENDBL) '--------------' $(BLINK)||$(ENDBL) '--------------' $(BLINK)|| '--------------' || '--------------' $(REDBL)|$(ENDBL)$(RESET)";
	echo "$(REDBL)'------------------''------------------''------------------''------------------''------------------' $(RESET)";
	echo "                                      ";
	echo "$(GREEN)Cub3D is ready.$(RESET)"
	@echo "$(BLUE)Execute $(IWHITE)./cub3D <map_name>.cub$(RESET)$(BLUE) to play!$(RESET)"

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
	clear
	@echo "$(RED)Object and Executable files have been deleted!$(RESET)"

re: fclean all

.SILENT: