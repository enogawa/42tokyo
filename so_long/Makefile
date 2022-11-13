NAME         =    so_long
CC           =    cc
CFLAGS       =    -Wall -Werror -Wextra -I ./include

MLX_PATH     =    ./minilibx-linux/
MLX_FLAG     =    -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MLX_MAKE     =    $(MLX)
MLX          =    ./minilibx-linux/libmlx_Darwin.a ./minilibx-linux/libmlx.a


LIBFTDIR     =    libft
LIBFT        =    $(LIBFTDIR)/libft.a
LIB          =    $(LIBFT)

GNL_SRC      =    ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL_PATH     =    ./get_next_line/
GNL_OBJS     =    $(GNL_SRC:.c=.o)

SRCS         =    ./src/so_long.c ./src/args_error_handler.c ./src/ft_strlen_so_long.c ./src/map_error_handler.c ./src/make_map.c \
				./src/put_gnl.c ./src/destroy_mlx.c ./src/move.c ./src/map_error_utils.c ./src/DFS_utils.c ./src/ft_strchr_so_long.c

OBJS         =    ${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(GNL_OBJS) 
		$(MAKE) -C $(MLX_PATH)
		$(CC) -o $(NAME) $(SRCS) $(GNL_OBJS) $(LIB) $(CFLAGS) $(MLX) $(MLX_FLAG)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

clean:
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) ${GNL_OBJS}
		$(RM) ${OBJS}
		$(RM) ${MLX}
		$(MAKE) clean -C $(MLX_PATH)

fclean: clean
		$(RM) ${NAME}

re : fclean all

.PHONY:
		all clean fclean re 