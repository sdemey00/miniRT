# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 16:29:07 by mmichele          #+#    #+#              #
#    Updated: 2025/10/31 23:52:24 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
FLAGS		= -Wall -Wextra -Werror

NAME		= libft.a

SRC_DIR		= src
BLD_DIR		= build

SRCS		= src/char/ft_isalnum.c src/char/ft_isalpha.c \
			  src/char/ft_isdigit.c src/char/ft_islower.c \
			  src/char/ft_isprint.c src/char/ft_issign.c \
			  src/char/ft_isspace.c src/char/ft_isupper.c \
			  src/char/ft_tolower.c src/char/ft_toupper.c \
			  src/cmp/ft_memcmp.c src/cmp/ft_vpfltcmp.c \
			  src/cmp/ft_vpintcmp.c src/cmp/ft_vpstrcmp.c \
			  src/convert/convert_utils/f_valid_base.c src/convert/ft_atoi_base.c \
			  src/convert/ft_atoi.c src/convert/ft_convert_base.c \
			  src/convert/ft_frombin.c src/convert/ft_itoa.c \
			  src/convert/ft_tobin.c src/list/ft_lstadd_back.c \
			  src/list/ft_lstadd_front.c src/list/ft_lstclear.c \
			  src/list/ft_lstdelone.c src/list/ft_lstiter.c \
			  src/list/ft_lstlast.c src/list/ft_lstmap.c \
			  src/list/ft_lstnew.c src/list/ft_lstsize.c \
			  src/math/ft_abs.c src/math/ft_fact.c \
			  src/math/ft_pow.c src/math/ft_pythagoras.c \
			  src/math/ft_round.c src/math/ft_sqrt.c \
			  src/math/matrix/mat1.c src/math/vector/rotx.c \
			  src/math/vector/roty.c src/math/vector/rotz.c \
			  src/math/vector/vec1.c src/math/vector/vec2.c \
			  src/math/vector/vec3.c src/memory/ft_bzero.c \
			  src/memory/ft_calloc.c src/memory/ft_free.c \
			  src/memory/ft_malloc.c src/memory/ft_memadd.c \
			  src/memory/ft_memchr.c src/memory/ft_memcpy.c \
			  src/memory/ft_memdup.c src/memory/ft_memmax.c \
			  src/memory/ft_memmin.c src/memory/ft_memmove.c \
			  src/memory/ft_memset.c src/memory/ft_memswap.c \
			  src/memory/ft_nfree.c src/memory/ft_parrlen.c \
			  src/memory/ft_realloc.c src/read/ft_gnl.c \
			  src/read/gnl/f_gnl_utils.c src/sort/ft_insertion.c \
			  src/sort/ft_selection.c src/string/ft_split.c \
			  src/string/ft_strchr.c src/string/ft_strcmp.c \
			  src/string/ft_strdup.c src/string/ft_striteri.c \
			  src/string/ft_strjoin.c src/string/ft_strlcat.c \
			  src/string/ft_strlcpy.c src/string/ft_strlen.c \
			  src/string/ft_strmapi.c src/string/ft_strncmp.c \
			  src/string/ft_strndup.c src/string/ft_strnstr.c \
			  src/string/ft_strrchr.c src/string/ft_strtrim.c \
			  src/string/ft_substr.c src/write/ft_aec.c \
			  src/write/ft_dprintf.c src/write/ft_printf.c \
			  src/write/printf/f_flags.c src/write/printf/f_pad.c \
			  src/write/printf/f_putchar.c src/write/printf/f_putdbl.c \
			  src/write/printf/f_puthex.c src/write/printf/f_putnbr.c \
			  src/write/printf/f_putptr.c src/write/printf/f_putstr.c \
			  src/write/printf/f_putuint.c src/write/printf/f_vdprintf.c
OBJS		= $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRCS))
INCS		= -I .
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(@D)
	$(CC) $(FLAGS) -MMD -c $< -o $@ $(INCS)

-include $(DEPS)

.PHONY: clean fclean re san norm

clean:
	rm -rf $(BLD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

san: FLAGS += -g -fsanitize=address,leak,undefined
san: $(NAME)

norm:
	@ ! norminette libft.h includes src | grep -v "OK!"

fast: FLAGS = -Ofast
fast: all
