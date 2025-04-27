NAME	= cub3D

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

# fsani = -g -fsanitize=address

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLXLIB = MLX42/libmlx42.a -lglfw -lm -ldl -lX11 -lpthread -lXrandr -lXi -lGL
else ifeq ($(UNAME_S),Darwin)
	MLXLIB = MLX42/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
endif


GNL = get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c

utils =	utils/ft_strncmp.c 	utils/ft_error.c 	utils/ft_split.c	utils/ft_strchr.c	\
		utils/ft_duplicate.c	utils/ft_strdup.c	utils/ft_substr.c	utils/free_arr.c utils/ft_copy.c

parse = parse/parse.c 		parse/col_atoa.c		parse/flood_fill.c 	parse/map_path.c	\
		parse/map_utils.c	parse/get_map.c			parse/map_parse1.c	\
		parse/map_parse2.c	parse/map_parse3.c		parse/door_parse.c

SRCS =	srcs/cub3d.c			srcs/allocation_management.c	srcs/initialisation.c	srcs/input_handle.c				srcs/ray_handler.c		srcs/ray_cast_utils1.c	\
		srcs/ray_cast_utils2.c 	srcs/render.c					srcs/render3d.c			srcs/render_utils.c				srcs/texture_handle.c	srcs/color.c 	\
		parse/valid_elements.c	parse/get_data.c				srcs/graphic_handle.c	srcs/key_hook.c	srcs/minimap.c	srcs/torch.c \
		srcs/clean_close.c		srcs/my_puts.c					srcs/error_mlx.c

OBJS	= ${SRCS:.c=.o} ${parse:.c=.o} ${utils:.c=.o} ${GNL:.c=.o}

all: $(NAME)

%.o:%.c cub3d.h utils/utils.h parse/parse.h get_next_line/get_next_line.h Makefile
	@($(CC) ${fsani} -Ofast ${CFLAGS} -c $< -o $@)

$(NAME): ${OBJS}
	@($(CC) ${fsani}  -Ofast ${OBJS} $(MLXLIB) -o ${NAME})
	@printf "\r\033[K\033[33mcub3d compiled\033[0m\n"

clean:
	@rm -f ${OBJS}
	@printf "\r\033[K\033[33mcleaning objects completed\033[0m\n"

fclean: 	clean
	@rm -f $(NAME)
	@rm -rf obj
	@printf "\r\033[K\033[33mcleaning completed\033[0m\n"

re:		fclean all

.PHONY: clean
