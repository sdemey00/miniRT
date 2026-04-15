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
S		?= 1
V		?= 0

# Only used with "valgrind" target
F		?=

# Source program compiler settings
CC		= cc
FLAGS	= -Wall -Wextra -Werror -g -D WIDTH=$(W) -D HEIGHT=$(H) -D MAX_OBJS=$(M) -D VERBOSE=$(V) -D START_RENDER=$(S)

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
SRCS	= src/bitmap.c \
			src/parsing/parse_light.c \
			src/parsing/parse_cylinder.c \
			src/parsing/print_scene_infos.c \
			src/parsing/parse_utils/check_range.c \
			src/parsing/parse_utils/parse_utils.c \
			src/parsing/parse_utils/ft_atof.c \
			src/parsing/parse_utils/free_split.c \
			src/parsing/parse_utils/is_valid_format.c \
			src/parsing/parse_cone.c \
			src/parsing/scene_init.c \
			src/parsing/scene.c \
			src/parsing/textures_free.c \
			src/parsing/parse_ambiant.c \
			src/parsing/parse_camera.c \
			src/parsing/parse_background.c \
			src/parsing/parse_circle.c \
			src/parsing/parse_blackhole.c \
			src/parsing/parse_optional_args.c \
			src/parsing/parse_plane.c \
			src/parsing/parse_sphere.c \
			src/parsing/parse_line.c \
			src/parsing/parse_file.c \
			src/graphics/ray.c \
			src/graphics/blurtracing.c \
			src/graphics/color.c \
			src/graphics/camera.c \
			src/graphics/lights.c \
			src/graphics/bump_tex.c \
			src/graphics/rasterizers.c \
			src/graphics/raytracing.c \
			src/graphics/xpm_tex.c \
			src/graphics/reflection.c \
			src/graphics/window.c \
			src/graphics/normal.c \
			src/graphics/map_uv.c \
			src/graphics/ray_hit_cyl.c \
			src/graphics/ray_hit_bh.c \
			src/graphics/ray_hits.c \
			src/export/others.c \
			src/export/lights.c \
			src/export/objs.c \
			src/maths/eq2.c \
			src/maths/vec_utils.c \
			src/events/controller/loop.c \
			src/events/controller/camera.c \
			src/events/controller/object.c \
			src/events/window.c \
			src/events/kbm/key.c \
			src/events/kbm/mouse.c \
			src/events/kbm/obj_change.c \
			src/main.c \
			src/time.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
INCS	= -I $(SRCD) -I $(MLXD) -I $(LFTD) -I $(INCD)
LNKS	= -L $(MLXD) -L $(LFTD)
LIBS	= -lmlx -lX11 -lXext -lft -lm
DEPS	= $(OBJS:.o=.d)

# Fake targets
.PHONY: $(MLXN) $(LFTN) $(LFTN)-fast clean fclean re norm \
		san valgrind fast clear doc doc-clean

MAKEFLAGS += --no-print-directory

all: $(MLXN) $(LFTN) $(NAME)

$(MLXN):
	@ $(MAKE) -C $(MLXD) > /dev/null 2>&1 || \
		$(MAKE) -C $(MLXD) -f Makefile.gen > /dev/null 2>&1

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
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(F)

fast: FLAGS = -Ofast -D WIDTH=$(W) -D HEIGHT=$(H) -D MAX_OBJS=$(M) -D VERBOSE=$(V) -D START_RENDER=$(S)
fast: $(MLXN) $(LFTN)-fast $(NAME)

clear:
	rm -rf $(BLDD)

doc:
	cd $(DOCD) && bash build.sh

doc-clean:
	rm -rf $(DOCD)/$(BLDD)
