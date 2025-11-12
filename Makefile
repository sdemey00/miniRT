# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 08:33:05 by mmichele          #+#    #+#              #
#    Updated: 2025/11/06 21:18:31 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Be carefull that switching from compile target might require a clear or a clean !

# Source program name
NAME	= miniRT

# Program compile macro variables
W		?= 0
H		?= 0
M		?= 0

# Only used with "valgrind" target
F		?=

# Source program compiler settings
CC		= cc
FLAGS	= -Wall -Wextra -Werror -g -D WIDTH=$(W) -D HEIGHT=$(H) -D MAX_OBJS=$(M)

# Directories
BLDD	= build
SRCD	= src
LIBD	= libs
INCD	= includes
DOCD	= doc

# MiniLibX
MLXD	= $(LIBD)/mlx
MLXN	= $(MLXD)/libmlx_Linux.a

# LibFT
LFTD	= $(LIBD)/libft
LFTN	= $(LFTD)/libft.a

# Source compile variables
SRCS	= $(shell find $(SRCD) -type f -name "*.c")
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
INCS	= -I $(SRCD) -I $(MLXD) -I $(LFTD) -I $(INCD)
LNKS	= -L $(MLXD) -L $(LFTD)
LIBS	= -lmlx -lX11 -lXext -lft -lm
DEPS	= $(OBJS:.o=.d)

# Fake targets
.PHONY: $(MLXN) $(LFTN) $(LFTN)-fast clean fclean re norm \
		san valgrind verbose fast clear doc doc-clean

MAKEFLAGS += --no-print-directory

all: $(MLXN) $(LFTN) $(NAME)

$(MLXN):
	@ $(MAKE) -C $(MLXD) > /dev/null 2>&1

$(LFTN):
	@ $(MAKE) -C $(LFTD)

$(LFTN)-fast:
	@ $(MAKE) -C $(LFTD) fast

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(INCS) $(LNKS) $(LIBS)

$(BLDD)/%.o: %.c
	@ mkdir -p $(@D)
	$(CC) $(FLAGS) -MMD -c $< -o $@ $(INCS)

-include $(DEPS)

clean:
	rm -rf $(BLDD)
	$(MAKE) -C $(LFTD) clean

fclean: clean doc-clean
	rm -rf $(NAME)
	@ $(MAKE) -C $(MLXD) clean > /dev/null 2>&1
	rm -rf $(LFTN)

re: fclean all

norm:
	@ ! norminette $(INCD) $(SRCD) | grep -v "OK"
	@ $(MAKE) -C $(LFTD) $@
	@ echo "Project at norm"

san: FLAGS += -g -fsanitize=address,leak,undefined
san: all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(F)

verbose: FLAGS += -D VERBOSE
verbose: all

fast: FLAGS = -Ofast -D WIDTH=$(W) -D HEIGHT=$(H) -D MAX_OBJS=$(M)
fast: $(MLXN) $(LFTN)-fast $(NAME)

clear:
	rm -rf $(BLDD)

doc:
	cd $(DOCD) && bash build.sh

doc-clean:
	rm -rf $(DOCD)/$(BLDD)
