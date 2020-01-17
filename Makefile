# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:29:31 by ladawi            #+#    #+#              #
#    Updated: 2020/01/17 20:52:27 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIST = src/ft_printf.c \
			src/ft_buffset.c \
			src/ft_scanstr.c \
			src/ft_getflags.c \
			src/ft_checkchar.c \
			src/ft_parsing.c \
			src/ft_flags.c \
			src/ft_printf_c.c \
			src/ft_printf_s.c \
			src/ft_printf_d.c \
			src/ft_printf_u.c \
			src/ft_printf_x.c \
			
SRCO = $(SRC_LIST:%.c= %.o)

INCLUDE = includes/ft_printf.h \

LIBFT = libft/libft.a

OBJ_DIR = obj

FLAGS = -Wall -Werror -Wextra

RED = \033[0;91m
YEL = \033[93m
END = \033[0m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m

all: $(NAME)

$(NAME): $(SRCO) $(INCLUDE) $(OBJ_DIR) $(LIBFT)
	@ar -rc $(NAME) $(SRCO)
	@mv src/*.o obj/.
	@echo "$(YEL)Made $(NAME)$(END)"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(LIBFT):
	@make -C libft
	@echo "$(YEL)Made libft.a$(END)"
	
%.o: %.c
	@gcc -c $< -o $@
	@echo "$(GRE)$<$(END)"

clean:
	@make clean -C libft
	@echo "$(RED)$(BOLD)Made [clean] in libft$(END)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Removed *.o $(END)"

re: fclean all

fclean: clean
	@make fclean -C libft
	@echo "$(RED)$(BOLD)Made [fclean] in libft$(END)"
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"
	@rm -rf printf.out
	@echo "$(RED)$(BOLD)Removed *.out $(END)"

run : all 
	@make -C libft
	@echo "$(YEL)Made libft.a$(END)"
	@echo "$(PUR)Compiling$(END)"
	@gcc main.c libftprintf.a libft/libft.a -o printf.out
	@echo "$(PUR)Exec printf.out :$(END)"
	@./printf.out
