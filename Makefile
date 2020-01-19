# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:29:31 by ladawi            #+#    #+#              #
#    Updated: 2020/01/19 12:11:22 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIST = src/ft_printf.c \
			src/ft_buffset.c \
			src/ft_scanstr.c \
			src/ft_getflags.c \
			src/ft_checkchar.c \
			src/ft_parsing.c \
			src/ft_printf_c.c \
			src/ft_printf_s.c \
			src/ft_printf_d.c \
			src/ft_printf_u.c \
			src/ft_printf_x.c \
			src/ft_printf_p.c \
			

LIBFT_LIST = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_memset.c ft_putchar_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
ft_strdup.c ft_strjoin.c ft_strjoinfree.c ft_strlcat.c ft_strlcpy.c\
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
ft_itoa_base.c ft_pow.c ft_intlen.c ft_intlenbase.c ft_ultoax.c\

SRCO = $(SRC_LIST:%.c= %.o)

LIBFT_SRC = $(addprefix libft/,$(LIBFT_LIST))

LIBFT_O = $(LIBFT_SRC:%.c= %.o)

INCLUDE = includes/ft_printf.h \

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

$(NAME): $(SRCO) $(INCLUDE) $(OBJ_DIR) $(LIBFT_O)
	@ar -rc $(NAME) $(SRCO) $(LIBFT_O)
	@mv src/*.o obj/.
	@echo "$(YEL)Made $(NAME)$(END)"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

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
	@echo "$(YEL)Made libft.a$(END)"
	@echo "$(PUR)Compiling$(END)"
	@gcc main.c libftprintf.a -o printf.out
	@echo "$(PUR)Exec printf.out :$(END)"
	@./printf.out
