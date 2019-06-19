# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 18:00:07 by dtreutel          #+#    #+#              #
#    Updated: 2019/04/08 14:06:40 by dtreutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
LINKING=-framework OpenGL -framework AppKit
HEADER=includes/wolf3d.h
SRCS_DIR=./src
OBJS_DIR=./objects
LIBFT_DIR=./libft
RAW_SRCS= main.c\
          ft_exit.c\
          get_next_line.c\
          wolf3d.c\
          get_map.c\
          set_pxl.c\
          put_line.c\
          wolf_init.c\
          clear_image.c\
          move_player.c\
          distance_init.c\
          read_textur.c\
          put_textur.c\
		  minimap.c\
		  put_pistol.c\
		  loop_hook.c\
		  player_init.c

RAW_OBJS=$(RAW_SRCS:.c=.o)
SRCS=$(addprefix $(SRCS_DIR)/,$(RAW_SRCS))
OBJS=$(addprefix $(OBJS_DIR)/,$(RAW_OBJS))
OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))
LIBFT_A=$(LIBFT_DIR)/libft.a
MINLIBX=-L minilibx_macos -lmlx $(LINKING)
INCLUDES:=-I includes -I $(LIBFT_DIR)/includes
FLAGS=-Wall -Wextra -Werror

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0mmake fclean

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR):
	@echo "$(BLUE)Compiling $(NAME_CLEAN) objects files..."
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@gcc $(INCLUDES) $(FLAGS) -o $@ -c $<

$(LIBFT_A):
	@make -C $(LIBFT_DIR)
	@make -C minilibx_macos

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@echo "$(BLUE)Compiling executable..."
	@gcc $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME) $(MINLIBX)
	@echo "$(GREEN)Bin $(NAME) is ready to use!"

clean:
ifneq ($(OBJS_CLEAN),)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@make -C minilibx_macos clean
	@echo "$(RED)$(NAME_CLEAN) objects files removed."
else
	@echo "$(RED)$(NAME_CLEAN) objects already cleaned"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)Bin $(NAME_CLEAN) removed."
else
	@echo "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$"
endif

test:
	gcc $(FLAGS) -g $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A)

re: fclean all
